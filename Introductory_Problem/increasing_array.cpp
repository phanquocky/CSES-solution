#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    vector<int> arr;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int u;
        cin >> u;
        arr.push_back(u);
    }

    if (arr.size() < 2)
    {
        cout << 0;
        return 0;
    }
    int m = arr[0];
    int left = 0;
    int right = 1;
    long long result = 0;
    while (right < arr.size())
    {
        if (arr[right] < arr[left])
        {
            result += arr[left] - arr[right];
            arr[right] = arr[left];
        }
        left++;
        right++;
    }

    cout << result;

    return 0;
}