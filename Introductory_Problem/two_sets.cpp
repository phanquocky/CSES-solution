#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    if (n % 4 == 1 || n % 4 == 2)
    {
        cout << "NO";
        return 0;
    }

    long long sum = (n * (n + 1)) / 2;
    sum = sum / 2; // sum for each list
    // cout << "sum: " << sum << endl;
    vector<long long> l1;
    vector<long long> l2;

    while (sum >= n)
    {
        l1.push_back(n);
        sum -= n;
        n--;
    }

    for (int i = 1; i <= n; i++)
    {
        if (i != sum)
            l2.push_back(i);
    }

    if (sum > 0)
        l1.push_back(sum);

    cout << "YES" << endl;
    cout << l1.size() << endl;
    for (int i : l1)
        cout << i << " ";
    cout << endl
         << l2.size() << endl;
    for (int i : l2)
        cout << i << " ";

    // (4k + 1)(2k+1) cut
    // (4k + 2)(4k + 3) cut
    // 4k + 3
    // 4k
    // 1, 2, 3, 4, 5
    return 0;
}