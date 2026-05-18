#include <iostream>
#include <vector>
using namespace std;

char NEXTSTEP[4] = {'A', 'B', 'C', 'D'};
char NEIGHBOR[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool isValidGrid(int x, int y, int n, int m) { return x >= 0 && x < n && y >= 0 && y < m; }
bool backtrack(vector<string> &grid, vector<vector<bool>> &vi, int idx, int n, int m)
{
    if (idx == n * m)
        return true;
    int x = idx / m;
    int y = idx % m;
    for (char i : NEXTSTEP)
    {
        if (grid[x][y] == i)
            continue;
        bool isValid = true;
        for (int s = 0; s < 4; s++)
        {
            int dx = x + NEIGHBOR[s][0];
            int dy = y + NEIGHBOR[s][1];
            if (isValidGrid(dx, dy, n, m) && vi[dx][dy] && grid[dx][dy] == i)
                isValid = false;
        }
        if (!isValid)
            continue;
        char c = grid[x][y];
        vi[x][y] = true;
        grid[x][y] = i;
        if (backtrack(grid, vi, idx + 1, n, m))
        {
            return true;
        }

        vi[x][y] = false;
        grid[x][y] = c;
    }
    return false;
}

int main()
{
    int m, n;
    cin >> n >> m;
    vector<string> grid;
    vector<vector<bool>> vi(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        grid.push_back(a);
    }

    if (backtrack(grid, vi, 0, n, m))
    {
        for (string c : grid)
        {
            cout << c << endl;
        }
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
}