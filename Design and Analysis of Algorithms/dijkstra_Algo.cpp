/*
Sample Input:
Enter the number of vertices: 4
Enter the number of edges: 4
Enter the edges source, destination and their weights:
1 2 24
1 4 20
3 1 3
4 3 12
Enter the source vertex: 1

Sample Output:
0 24 3 15
*/

#include <bits/stdc++.h>
using namespace std;
const int inf = 1e7;

int main()
{
    int n, m, source;
    vector<int> dist(n + 1, inf);
    vector<vector<pair<int, int>>> graph(n + 1);

    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;
    cout << "Enter the edges source, destination and their weights: \n";

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    cout << "Enter the source vertex: ";
    cin >> source;
    dist[source] = 0;
    set<pair<int, int>> s;
    s.insert({0, source});

    while (!s.empty())
    {
        auto x = *(s.begin());
        s.erase(x);
        for (auto it : graph[x.second])
        {
            if (dist[it.first] > dist[x.second] + it.second)
            {
                s.erase({dist[it.second], it.first});
                dist[it.first] = dist[x.second] + it.second;
                s.insert({dist[it.first], it.first});
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] < inf)
            cout << dist[i] << " ";
        else
            cout << -1 << " ";
    }
    return 0;
}