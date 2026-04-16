#include <iostream>
#include <vector>
using namespace std;

int main()
{

    long long n;
    vector<int> arr;
    cin >> n;
    long long cur_sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int u;
        cin >> u;
        cur_sum += u;
    }

    long long total_sum = n * (n + 1) / 2;

    cout << total_sum - cur_sum;
    return 0;
}