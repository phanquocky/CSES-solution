#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    string a;
    cin >> a;
    map<char, int> mm;
    for (char i : a)
    {
        mm[i]++;
    }

    int num_odd = 0;
    string char_odd;
    for (auto [key, val] : mm)
    {
        if (val % 2 != 0)
        {
            num_odd++;
            for (int i = 0; i < val; i++)
                char_odd += key;
        }
    }

    if (num_odd > 1)
    {
        cout << "NO SOLUTION";
        return 0;
    }

    string result;
    if (num_odd == 1)
    {
        result = char_odd;
        mm.erase(char_odd[0]);
    }

    for (auto [key, val] : mm)
    {

        result = string(val / 2, key) + result + string(val / 2, key);
    }
    cout << result;
    return 0;
}