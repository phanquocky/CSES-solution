#include <iostream>
#include <vector>
using namespace std;
long long diff(long long a, long long b)
{
    return (a > b) ? a - b : b - a;
}

void backtrack(int idx, long long &result, vector<long long> &p, vector<long long> &temp, long long &sum)
{
    if (idx >= p.size())
    {
        long long sum1 = 0;
        for (long long i : temp)
            sum1 += i;
        result = min(result, diff(sum - sum1, sum1));
        return;
    }

    temp.push_back(p[idx]);
    backtrack(idx + 1, result, p, temp, sum);
    temp.pop_back();
    backtrack(idx + 1, result, p, temp, sum);
    return;
}

int main()
{

    int n;
    cin >> n;
    vector<long long> p;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        long long u;
        cin >> u;
        sum += u;
        p.push_back(u);
    }

    long long result = sum;

    vector<long long> temp;
    backtrack(0, result, p, temp, sum);

    cout << result;
}