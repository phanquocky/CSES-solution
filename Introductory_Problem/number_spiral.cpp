#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll number_spiral(ll x, ll y)
{
    if (x < y)
    {
        if (y % 2 == 0)
            return (y - 1) * (y - 1) + x;
        else
            return y * y - x + 1;
    }
    else
    {
        if (x % 2 == 0)
            return x * x - y + 1;
        else
            return (x - 1) * (x - 1) + y;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<pair<ll, ll>> arr;

    for (int i = 0; i < n; i++)
    {
        ll u, v;
        cin >> u >> v;
        arr.push_back({u, v});
    }

    for (pair<ll, ll> i : arr)
    {
        cout << number_spiral(i.first, i.second) << endl;
    }

    return 0;
}