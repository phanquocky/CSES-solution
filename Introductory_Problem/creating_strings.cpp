#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

void backtrack(string &str, string temp, vector<bool> &vi, vector<string> &result)
{
    if (temp.length() == str.length())
    {
        result.push_back(temp);
        return;
    }

    for (int i = 0; i < str.length(); i++)
    {
        if (!vi[i])
        {
            if (i > 0 && str[i] == str[i - 1] && !vi[i - 1]) // trickkk to remove duplicate
                continue;
            vi[i] = true;
            backtrack(str, temp + str[i], vi, result);
            vi[i] = false;
        }
    }
    return;
}

int main()
{
    string str;
    cin >> str;
    sort(str.begin(), str.end());
    vector<bool> vi(str.length(), false);
    vector<string> result;
    backtrack(str, "", vi, result);

    cout << result.size() << endl;
    for (string i : result)
    {
        cout << i << endl;
    }
    return 0;
}