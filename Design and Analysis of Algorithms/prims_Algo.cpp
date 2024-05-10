/*
Sample Input:
3 3
0 1 5
1 2 3
0 2 1

Sample Output:
4
*/
#include <bits/stdc++.h>
using namespace std;

int primsAlgorithm(int V, vector<vector<int>> adj[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(V, 0);
    int cost = 0;
    pq.push({0, 0}); // {wt, node}
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int wt = it.first;
        int node = it.second;

        if (vis[node] == 1)
            continue;

        vis[node] = 1;
        cost += wt;

        for (auto edge : adj[node])
        {
            int neighbor_node = edge[0];
            int weight = edge[1];
            if (!vis[neighbor_node])
                pq.push({weight, neighbor_node});
        }
    }

    return cost;
}

int main()
{
    int n, m;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;
    vector<vector<int>> adj[n];

    cout << "Enter the edges source, destination and their weights: \n";
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        vector<int> t1, t2;
        t1.push_back(v);
        t1.push_back(w);
        adj[u].push_back(t1);
        t2.push_back(u);
        t2.push_back(w);
        adj[v].push_back(t2);
    }
    cout << "Cost of Minimum Spanning Tree using Prim's Algorithm is " << primsAlgorithm(n, adj);
    return 0;
}
