
#include <iostream>
#include <vector>

using namespace std;

// void createPermutation(int &n, vector<vector<int>> &result, vector<bool> &vi, vector<int> &temp)
// {
//     if (temp.size() == n)
//     {
//         result.push_back(temp);
//         return;
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         if (vi[i])
//             continue;

//         temp.push_back(i);
//         vi[i] = true;
//         createPermutation(n, result, vi, temp);
//         vi[i] = false;
//         temp.pop_back();
//     }
//     return;
// }

// bool check(int &n, vector<int> &permutation, int &a, int &b)
// {
//     int x = 0; // player 1
//     int y = 0; // player 2
//     for (int i = 1; i <= n; i++)
//     {
//         if (i < permutation[i - 1])
//             y++;
//         if (i > permutation[i - 1])
//             x++;
//     }
//     return (x == a && y == b);
// }

// void sol(int n, int a, int b)
// {
//     vector<vector<int>> permutation;
//     vector<bool> vi(n + 1, false);
//     vector<int> temp;
//     createPermutation(n, permutation, vi, temp);

//     for (int i = 0; i < permutation.size(); i++)
//     {
//         if (check(n, permutation[i], a, b))
//         {
//             cout << "YES" << endl;
//             for (int j = 1; j <= n; j++)
//                 cout << j << " ";
//             cout << endl;
//             for (int j : permutation[i])
//                 cout << j << " ";
//             cout << endl;
//             return;
//         }
//     }
//     cout << "NO" << endl;
//     return;
// }

void sol(int n, int a, int b)
{
    if (a + b > n) // check the case
    {
        cout << "NO" << endl;
        return;
    }

    int nn = a + b; // standerdize problem 1, 2, 3, ..., nn but without any same pair in their choice.
    // if (nn == 0) // check the edge case
    // {
    //     cout << "YES" << endl;
    //     for (int i = 1; i <= n; i++)
    //         cout << i << " ";
    //     cout << endl;
    //     for (int i = 1; i <= n; i++)
    //         cout << i << " ";
    //     cout << endl;
    //     return;
    // }
    if (nn != 0 && (a == 0 || b == 0)) // check edge case, because one player loose at least 1 round because their "1" choice, (remmber don't have any pair the same choice)
    {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) // first sort the first player
    {
        cout << i << " ";
    }
    cout << endl;

    for (int i = a + 1; i <= nn; i++)
        cout << i << " ";
    for (int i = 1; i <= a; i++) // this loop and previous loop rotate the 1 --> nn "a" round. this mean the player 1 will have "a" score. and player 2 have nn-a=b score
        cout << i << " ";
    for (int i = nn + 1; i <= n; i++) // print out pair which two player have the same choices
        cout << i << " ";
    cout << endl;
    return;
}

int main()
{
    int n;
    vector<vector<int>> mm;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> temp({n, a, b});
        mm.push_back(temp);
    }

    for (int i = 0; i < n; i++)
    {
        sol(mm[i][0], mm[i][1], mm[i][2]);
    }
    return 0;
}
// player1: 1, 2, 3, 4, 5, 6, ... , n
// player2: 1, 2, 3, 4, 5, 6, ... , n
// s1, s2 are scores of player1, player 2
// we have a condition s1 + s2 <= n
// 7 8 9 4 5 6 1 2 3
// 1 2 3 4 5 6 7 8 9 3  2 3 --> 6
//
//  8 9 1 2 3 4 5 7 6
//  1 8 9 3 4 5 6 7 2
// 1, 2, 3, 4, 5, *, ... , n : 1
// 1, 2, *, 4, 5, 6, ... , n : 0

// lemma 1: if we have a difference pairs, for player 2 we have max n-2a same pairs.
// brute force: fix player 1: 1, 2, 3, 4, 5 ... , n
//              and permutate 1->n for player2