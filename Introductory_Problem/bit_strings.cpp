#include <iostream>
using namespace std;
long long Modulo = 1e9 + 7;
int main()
{
    long long n;
    cin >> n;

    long long result = 1;

    for (int i = 0; i < n; i++)
    {

        result = result << 1;
        result = result % Modulo;
    }
    cout << result;
    return 0;
}