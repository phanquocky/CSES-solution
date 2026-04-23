#include <iostream>

using namespace std;

int main()
{

    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    if (n < 4)
    {
        cout << "NO SOLUTION";
        return 0;
    }

    int i = n - 1;
    while (i > 0)
    {
        cout << i << " ";
        i -= 2;
    }

    int j = n;
    while (j > 0)
    {
        cout << j << " ";
        j -= 2;
    }

    return 0;
}