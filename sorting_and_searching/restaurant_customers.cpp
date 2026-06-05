#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        arr[i] = {u, v};
    }

    sort(arr.begin(), arr.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.first < b.first; });

    if (arr.size() == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    int curr_result = 1;
    int final_result = 1;
    q.push(arr[0].second);
    for (int i = 1; i < n; i++)
    {
        while (!q.empty() && arr[i].first > q.top())
        {
            q.pop();
            curr_result--;
        }
        curr_result++;
        final_result = max(final_result, curr_result);
        q.push(arr[i].second);
    }

    cout << final_result << endl;
    return 0;
}

// 4

//     2 4 3 5 +
//     1 7 9 1 10
