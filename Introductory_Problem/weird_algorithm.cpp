#include <iostream>
using namespace std;

long long weird_algo(long long n)
{
    if (n % 2 == 0)
        return (n / 2);
    else
        return 3 * n + 1;
}

int main()
{
    long long n;
    cin >> n;

    while (n != 1)
    {
        cout << n << " ";
        n = weird_algo(n);
    }
    cout << n;

    return 0;
}