#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int NEXTMOVE[8][2] = {{1, 2}, {2, 1}, {-1, -2}, {-2, -1}, {1, -2}, {-2, 1}, {-1, 2}, {2, -1}}; // 8 possible moves of knight

bool isValid(int n, int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}

void bfs(vector<vector<int>> &result, int n)
{
    queue<pair<int, int>> q;
    vector<vector<bool>> vi(n, vector<bool>(n, false));
    q.push({0, 0});
    vi[0][0] = true;
    int depth = 0;

    while (!q.empty())
    {
        int s = q.size();

        while (s > 0)
        {
            pair<int, int> t = q.front();
            q.pop();
            result[t.first][t.second] = depth;

            for (int i = 0; i < 8; i++)
            {
                int row = t.first + NEXTMOVE[i][0];
                int col = t.second + NEXTMOVE[i][1];
                if (isValid(n, row, col) && !vi[row][col])
                {
                    q.push({row, col});
                    vi[row][col] = true;
                }
            }
            s--;
        }
        depth++;
    }
    return;
}

using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> result(n, vector<int>(n, 0));

    bfs(result, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}