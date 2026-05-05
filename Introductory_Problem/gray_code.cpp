#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> temp = {"0", "1"};
    for (int i = 0; i < n - 1; i++)
    {
        int l = temp.size();
        for (int j = l - 1; j >= 0; j--)
        {
            temp.push_back("1" + temp[j]);
        }
        for (int j = 0; j < l; j++)
            temp[j] = "0" + temp[j];
    }

    for (string i : temp)
        cout << i << endl;
    return 0;
}
// n = 1 0 1
// if n = 2 00  01  11  10
//          +2^0 + 2^1 -2^0
// if n = 3 000  001  011 010 110 111 101 100
//          + 2^0  + 2^1. +2^2
// if n = 4 0000 0001 0011 0111 1111