#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<vector<int>> &arr, int x, int y)
{
    int result = 0;
    int vi[1000] = {0}; // TODO: assume max value lower than 1000.
    for (int i = x - 1; i >= 0; i--)
    {
        vi[arr[i][y]] = 1;
    }
    for (int i = y - 1; i >= 0; i--)
    {
        vi[arr[x][i]] = 1;
    }

    while (vi[result])
    {
        result++;
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = findMin(arr, i, j);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}