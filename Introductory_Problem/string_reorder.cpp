#include <iostream>
#include <map>
#include <vector>
using namespace std;

// draf another way, to reduce run time
// HATTIVATTI -sort-> AAHIITTTTV
// IMPORTANT RULE: if count > (len+1)/2 --> IMPOSSIBLE, so we priority lower character but remain RULE true every round.

void findMax(map<char, int> &mm, int &maxCount, char &maxChar)
{
    maxCount = 0;
    for (char i = 'A'; i <= 'Z'; i++)
    {
        if (mm[i] > maxCount)
        {
            maxCount = mm[i];
            maxChar = i;
        }
    }
}

int main()
{
    string input;
    cin >> input;
    int maxCount;
    char maxChar;

    map<char, int> mm;
    for (char i : input)
        mm[i]++;

    int remainLen = input.length();
    findMax(mm, maxCount, maxChar);

    if (maxCount > (remainLen + 1) / 2)
    {
        cout << -1 << endl;
        return 0;
    }

    string result = "";
    while (remainLen > 0)
    {
        findMax(mm, maxCount, maxChar);
        remainLen--;
        if (maxCount > (remainLen + 1) / 2)
        {
            result += maxChar;
            mm[maxChar]--;
        }
        else
        {
            for (int i = 'A'; i <= 'Z'; i++)
            {
                int resultLen = result.length();

                if (mm[i] > 0 && resultLen == 0)
                {
                    result += i;
                    mm[i]--;
                    break;
                }

                if (mm[i] > 0 && result[resultLen - 1] != i)
                {
                    result += i;
                    mm[i]--;
                    break;
                }
            }
        }
    }

    cout << result;
    return 0;
}

// # this is brute force way
// int cmpLexicoOrder(string a, string b)
// {
//     int lena = a.length();
//     int lenb = b.length();
//     if (lena != lenb)
//         return lena > lenb ? 1 : -1;
//     for (int i = 0; i < lena; i++)
//     {
//         if (a[i] != b[i])
//             return a[i] > b[i] ? 1 : -1;
//     }

//     return 0;
// }

// void backtrack(string &str, vector<bool> vi, string &tmp, string &res)
// {
//     if (tmp.length() == str.length())
//     {
//         if (res == "" || cmpLexicoOrder(tmp, res) == -1)
//             res = tmp;
//         return;
//     }

//     int tmpLen = tmp.length();
//     for (int i = 0; i < str.length(); i++)
//     {
//         if (vi[i])
//             continue;
//         if (tmpLen > 0 && tmp[tmpLen - 1] == str[i])
//             continue;
//         vi[i] = true;
//         tmp.push_back(str[i]);
//         backtrack(str, vi, tmp, res);
//         tmp.pop_back();
//         vi[i] = false;
//     }
// }

// int main()
// {
//     string input;
//     cin >> input;
//     string res = "";
//     string tmp;
//     vector<bool> vi(input.length(), false);
//     backtrack(input, vi, tmp, res);
//     if (res == "")
//         cout << -1 << endl;
//     else
//         cout << res << endl;
//     return 0;
// }