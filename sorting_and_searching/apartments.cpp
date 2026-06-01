#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long n, m, k;
    cin >> n >> m >> k;
    vector<long long> applicants(n);
    vector<long long> apartments(m);
    for (int i = 0; i < n; i++)
        cin >> applicants[i];
    for (int i = 0; i < m; i++)
        cin >> apartments[i];
    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    long long idxappli = 0;
    long long idxapart = 0;
    long long result = 0;
    while (idxappli < n && idxapart < m)
    {
        if (apartments[idxapart] >= applicants[idxappli] - k && apartments[idxapart] <= applicants[idxappli] + k) // in range satisfy
        {
            idxappli++;
            idxapart++;
            result++;
        }
        else if (apartments[idxapart] < applicants[idxappli] - k)
        {
            idxapart++;
        }
        else
        {
            idxappli++;
        }
    }

    cout << result << endl;

    return 0;
}