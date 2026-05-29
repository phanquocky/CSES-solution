#include <iostream>
using namespace std;

string path;
bool vis[9][9];
int ans = 0;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char dc[4] = {'D', 'U', 'L', 'R'};

bool deadEnd(int x, int y)
{
    int cnt = 0;

    cnt += vis[x + 1][y];
    cnt += vis[x - 1][y];
    cnt += vis[x][y + 1];
    cnt += vis[x][y - 1];

    return cnt == 3;
}

void dfs(int step, int x, int y)
{
    // tới đích
    if (x == 7 && y == 1)
    {
        ans += (step == 48);
        return;
    }

    if (step == 48)
        return;

    // split prune
    if (vis[x - 1][y] && vis[x + 1][y] &&
        !vis[x][y - 1] && !vis[x][y + 1])
        return;

    if (vis[x][y - 1] && vis[x][y + 1] &&
        !vis[x - 1][y] && !vis[x + 1][y])
        return;

    vis[x][y] = true;

    char c = path[step];

    // forced move
    int forced = -1;

    for (int d = 0; d < 4; d++)
    {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (vis[nx][ny])
            continue;

        // nếu ô kế tiếp thành dead-end
        // mà chưa phải đích => bắt buộc đi vào
        if (deadEnd(nx, ny) && !(nx == 7 && ny == 1))
        {
            if (forced != -1)
            {
                vis[x][y] = false;
                return;
            }
            forced = d;
        }
    }

    if (forced != -1)
    {
        if (c == '?' || c == dc[forced])
        {
            int nx = x + dx[forced];
            int ny = y + dy[forced];

            dfs(step + 1, nx, ny);
        }

        vis[x][y] = false;
        return;
    }

    for (int d = 0; d < 4; d++)
    {
        if (c != '?' && c != dc[d])
            continue;

        int nx = x + dx[d];
        int ny = y + dy[d];

        if (vis[nx][ny])
            continue;

        dfs(step + 1, nx, ny);
    }

    vis[x][y] = false;
}

int main()
{
    cin >> path;

    // border
    for (int i = 0; i < 9; i++)
    {
        vis[0][i] = true;
        vis[8][i] = true;
        vis[i][0] = true;
        vis[i][8] = true;
    }

    dfs(0, 1, 1);

    cout << ans << '\n';
}