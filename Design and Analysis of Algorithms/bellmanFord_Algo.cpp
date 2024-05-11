#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int n, vector<vector<int>> adj, int s)
{
    vector<int> ans(n, 1e9);
    ans[s] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < adj.size(); j++)
        {
            int src = adj[j][0];
            int dest = adj[j][1];
            int wt = adj[j][2];
            if (ans[src] != 1e9 && ans[src] + wt < ans[dest])
                ans[dest] = ans[src] + wt;
        }
    }
    return ans;
}

int main()
{
    int n, m, source;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;
    vector<vector<int>> adj(m);

    cout << "Enter the edges source, destination and their weights: \n";
    for (int i = 0; i < m; i++)
    {
        vector<int> temp(3);
        for (int j = 0; j < 3; j++)
        {
            cin >> temp[j];
        }
        adj[i] = temp;
    }

    cout << "Enter the source Vertex: ";
    cin >> source;

    vector<int> res = bellmanFord(n, adj, source);
    for (auto a : res)
    {
        cout << a << " ";
    }
    return 0;
}