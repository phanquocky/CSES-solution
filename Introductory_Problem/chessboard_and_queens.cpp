#include <iostream>
#include <vector>
using namespace std;

bool isInBoard(int x, int y)
{
    return (0 <= x) && (x < 8) && (0 <= y) && (y < 8);
}

vector<vector<bool>> nextStep(vector<vector<bool>> &vi, int x, int y)
{
    vector<vector<bool>> result(8, vector<bool>(8, false));
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            result[i][j] = vi[i][j]; // copy
        }
    }
    result[x][y] = true;
    // row, col;
    for (int i = 0; i < 8; i++)
    {
        result[x][i] = true;
        result[i][y] = true;
    }

    // diagonal
    for (int i = 0; i < 8; i++)
    {
        if (isInBoard(x - i, y - i))
            result[x - i][y - i] = true;
        if (isInBoard(x - i, y + i))
            result[x - i][y + i] = true;
        if (isInBoard(x + i, y - i))
            result[x + i][y - i] = true;
        if (isInBoard(x + i, y + i))
            result[x + i][y + i] = true;
    }

    return result;
}

void backtrack(int idx, vector<vector<char>> &board, vector<bool> &col, vector<bool> &diag1, vector<bool> &diag2, int &result)
{
    if (idx >= 8)
    {
        result++;
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        if (board[idx][i] == '*' || col[i] || diag1[idx - i + 7] || diag2[idx + i])
            continue;
        col[i] = true;
        diag1[idx - i + 7] = true;
        diag2[idx + i] = true;
        backtrack(idx + 1, board, col, diag1, diag2, result);
        col[i] = false;
        diag1[idx - i + 7] = false;
        diag2[idx + i] = false;
    }
    return;
}

int main()
{
    vector<vector<char>> board;
    vector<bool> col(8, false);
    vector<bool> diag1(15, false);
    vector<bool> diag2(15, false);
    for (int i = 0; i < 8; i++)
    {
        vector<char> temp;
        for (int j = 0; j < 8; j++)
        {
            char c;
            cin >> c;
            temp.push_back(c);
        }
        board.push_back(temp);
    }
    int result = 0;
    backtrack(0, board, col, diag1, diag2, result);
    cout << result;

    return 0;
}

// 0 1 2 3 4 5 6 7
// 1 2
// 2
// 3