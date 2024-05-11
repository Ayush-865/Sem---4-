#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;

void floydWarshall(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == INF)
                matrix[i][j] = -1;
            if (i == j)
                matrix[i][j] = 0;
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = n; j < n; j++)
            {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (matrix[i][j] == -1)
    //             matrix[i][j] = INF;
    //     }
    // }
}

int main()
{
    vector<vector<int>> graph = {{0, 5, INF, 10},
                                 {INF, 0, 3, INF},
                                 {INF, INF, 0, 1},
                                 {INF, INF, INF, 0}};
    floydWarshall(graph);
    for (auto &row : graph)
    {
        for (auto &num : row)
        {
            cout << num << "\t";
        }
        cout << "\n";
    }

    return 0;
}