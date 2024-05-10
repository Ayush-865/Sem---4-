#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &arr, int x, int y, int n)
{
    for (int col = 0; col < n; col++)
    {
        if (arr[x][col] == 1)
            return false;
    }

    for (int row = 0; row < n; row++)
    {
        if (arr[row][y] == 1)
            return false;
    }

    int row = x;
    int col = y;
    while (row >= 0 && col < n)
    {
        if (arr[row][col] == 1)
            return false;
        row--;
        col--;
    }

    row = x;
    col = y;
    while (row >= 0 && col < n)
    {
        if (arr[row][col] == 1)
            return false;
        row--;
        col++;
    }
    return true;
}

bool nQueen(vector<vector<int>> &arr, int x, int n)
{
    if (x >= n)
        return true;

    for (int col = 0; col < n; col++)
    {
        if (isSafe(arr, x, col, n))
        {
            arr[x][col] = 1;

            if (nQueen(arr, x + 1, n))
            {
                return true;
            }

            arr[x][col] = 0; // backtracking
        }
    }
    return false;
}

int main()
{
    int n;
    cout << "Enter number of Queen's: ";
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n, 0));

    if (nQueen(arr, 0, n))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
