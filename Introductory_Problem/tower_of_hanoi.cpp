#include <iostream>
#include <vector>
using namespace std;

void towerOfHanoi(int n, int left, int mid, int right, vector<pair<int, int>> &sol)
{
    if (n == 1)
    {
        sol.push_back({left, right});
        return;
    }
    towerOfHanoi(n - 1, left, right, mid, sol);
    sol.push_back({left, right});
    towerOfHanoi(n - 1, mid, left, right, sol);
    return;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> sol;
    towerOfHanoi(n, 1, 2, 3, sol);
    cout << sol.size() << endl;
    for (pair<int, int> i : sol)
    {
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}