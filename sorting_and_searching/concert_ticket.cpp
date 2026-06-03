#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bisearch(vector<long long> &tickets, long long price)
{

    int l = 0;
    int r = tickets.size() - 1;
    int result = l;

    if (tickets[l] > price || tickets.size() == 0)
        return -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (tickets[mid] <= price)
        {
            result = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    return result;
}

int find(vector<long long> &parents, long long idx)
{
    if (idx < 0)
        return -1;
    if (parents[idx] == idx)
        return idx;

    return parents[idx] = find(parents, parents[idx]);
}

int main()
{
    long long n, m;
    cin >> n >> m;
    vector<long long> tickets(n);
    vector<long long> parents(n);
    vector<long long> users(m);
    for (int i = 0; i < n; i++)
    {
        cin >> tickets[i];
        parents[i] = i;
    }
    for (int i = 0; i < m; i++)
        cin >> users[i];

    sort(tickets.begin(), tickets.end());

    for (int i = 0; i < m; i++)
    {
        int idx_price = bisearch(tickets, users[i]);
        idx_price = find(parents, idx_price);
        if (idx_price != -1)
        {
            cout << tickets[idx_price] << endl;
            parents[idx_price] = find(parents, idx_price - 1);
        }
        else
            cout << idx_price << endl;
    }

    return 0;
}