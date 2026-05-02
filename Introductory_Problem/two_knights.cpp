#include <iostream>
#include <vector>
using namespace std;

int is_inboard(int x, int y, int k)
{
    return (x >= 0) && (y >= 0) && (x < k) && (y < k);
}

int knight_steps[8][2] = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
int count_poss_next_step(int x, int y, int k)
{
    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        if (is_inboard(x + knight_steps[i][0], y + knight_steps[i][1], k))
            count++;
    }
    return count;
}

long long dp_knight_move(int k)
{
    long long res = 0;
    // case one knight at x = k - 1, and other knight must be in (k-1) * (k-1)
    int x = k - 1;
    for (int y = 0; y < k; y++)
    {
        res += (k - 1) * (k - 1) - count_poss_next_step(x, y, k - 1);
    }

    // case one knight at y = k - 1, and other knight must be in (k -1) * (k - 1), but x != k - 1 (because x = k - 1 have consider in previous loop)
    int y = k - 1;
    for (int x = 0; x < k - 1; x++)
    {
        res += (k - 1) * (k - 1) - count_poss_next_step(x, y, k - 1);
    }

    return res + ((2 * k - 1) * (2 * k - 2) - 4) / 2; // ((2 * k - 1) * (2 * k - 2) - 4) / 2 is the posible cases if 2 knights in x = k - 1 or y = k - 1.
    // first we have (2 * k - 1) * (2 * k - 2) chances to place 2 knights in 2k - 1 spaces (we don't care 2 knights can attack or not)
    // -4 hear means 4 cases 2 knights can attack at the corner.
    // divided 2 because 2 knights have the same order.
}

int main()
{
    int n;
    cin >> n;
    vector<long long> res(n + 1);
    res[1] = 0;
    res[2] = 6;

    for (int k = 3; k <= n; k++)
    {
        res[k] = res[k - 1] + dp_knight_move(k);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << res[i] << endl;
    }
}