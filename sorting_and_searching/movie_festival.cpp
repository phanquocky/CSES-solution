#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        arr[i] = {u, v};
    }

    sort(arr.begin(), arr.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.second < b.second; });

    int result = 1;
    int min_out = arr[0].second;
    for (int i = 1; i < n; i++)
    {
        if (arr[i].first >= min_out)
        {
            min_out = arr[i].second;
            result++;
        }
    }

    cout << result << endl;
    return 0;
}