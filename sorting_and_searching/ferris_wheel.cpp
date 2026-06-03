#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    long long n, x;
    cin >> n >> x;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());
    long long max_idx = n - 1;
    long long min_idx = 0;
    long long gondolas = 0;
    while (min_idx <= max_idx)
    {
        if (arr[max_idx] + arr[min_idx] > x)
        {
            max_idx--;
        }
        else
        {
            max_idx--;
            min_idx++;
        }
        gondolas++;
    }
    cout << gondolas << endl;
    return 0;
}