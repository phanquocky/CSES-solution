#include <iostream>
#include <vector>
using namespace std;

bool check(int a, int b)
{
    if (a > b)
    {
        int i = a;
        a = b;
        b = i;
    }

    if ((a + b) % 3 != 0)
        return false;
    if (a < int(b / 2))
        return false;
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        arr.push_back({u, v});
    }

    for (pair<int, int> i : arr)
    {
        if (check(i.first, i.second))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}

// piles: a and b coins
// the neccessary condition for the problem is that a + b is divisible by 3
// but the sufficient condition for the problem? we don't have
// but can proof this.
// a = 1, b = 11
// We need a another condition: we can see: a must be greater than b/2 (if b > a)
