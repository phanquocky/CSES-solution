#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int len = str.length();
    if (len < 2)
    {
        cout << len;
        return 0;
    }

    int left = 0;
    int right = 0;
    int result = 0;
    int rep = 0;
    while (right < str.length())
    {
        if (str[right] == str[left])
        {
            right++;
            rep++;
        }
        else
        {
            left = right;
            result = max(result, rep);
            rep = 0;
        }
    }

    result = max(result, rep);
    cout << result;

    return 0;
}