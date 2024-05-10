#include <bits/stdc++.h>
using namespace std;

int mcm(vector<int> &arr, int n)
{
    vector<vector<int>> m(n, vector<int>(n, 0));
    vector<vector<int>> s(n, vector<int>(n, 0));
    for (int d = 1; d < n - 1; d++)
    {
        for (int i = 1; i < n - d; i++)
        {
            int j = i + d;
            int min = INT_MAX;
            for (int k = 0; k < j; k++)
            {
                int ans = m[i][k] + m[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if (ans < min)
                {
                    s[i][j] = k;
                    min = ans;
                }
            }
            m[i][j] = min;
        }
    }
    return m[1][n - 1];
}

int main()
{
    int n;
    cout << "Enter number of limits: ";
    cin >> n;
    vector<int> arr(n, 0);
    cout << "Enter the limits of Matrix:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "The cost of Matrix Chain Multiplication is: " << mcm(arr, n) << "\n";
    return 0;
}