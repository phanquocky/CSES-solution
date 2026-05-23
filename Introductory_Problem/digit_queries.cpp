#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
long long p10[19];

// calculate power of 10, p10[i] = 10**i
void init()
{
    p10[0] = 1;
    for (int i = 1; i <= 18; i++)
    {
        p10[i] = p10[i - 1] * 10;
    }
}

long long powPos(long long len)
{
    long long result = 0;

    for (long long i = 1; i <= len; i++)
    {
        result += (p10[i] - p10[i - 1]) * i;
    }

    return result;
}

long long intToPos(long long k)
{

    string str = to_string(k);
    long long len = str.length();

    return (k - p10[len - 1]) * len + powPos(len - 1) + 1;
}

// long long pos, find a largest integer and position of this integer must be lower than pos
char findDigit(long long pos)
{

    long long l = 1;
    long long r = 1e17 + 7;
    long long ans = -1;
    while (l <= r)
    {
        long long mid = l + (r - l) / 2;

        if (intToPos(mid) <= pos)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    long long gap = pos - intToPos(ans);
    return to_string(ans)[gap];
}

int main()
{

    long long n;
    cin >> n;
    vector<long long> queries(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> queries[i];
    }
    init();

    for (long long i : queries)
    {
        cout << findDigit(i) << endl;
    }
}

// 1 digit : 1 --> 9
// 2 digit : 10 --> 110
// 3 digit : 110 --> 1110
// Input K: how many digit before it
// 6 --> 6
// 12 --> 12 -10 = 2 * 2 +

// function input k --> position of k.

// binary search --> find 102 , 102 - 100 = 2 (2 * 3)