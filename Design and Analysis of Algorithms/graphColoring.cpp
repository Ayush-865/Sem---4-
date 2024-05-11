#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &graph, vector<int> &color, int vertex, int c)
{
    for (int i = 0; i < graph.size(); ++i)
    {
        if (graph[vertex][i] && c == color[i])
            return false;
    }
    return true;
}

bool graphColoringUtil(vector<vector<int>> &graph, vector<int> &color, int m, int vertex)
{
    if (vertex == graph.size())
        return true;

    for (int c = 1; c <= m; ++c)
    {
        if (isSafe(graph, color, vertex, c))
        {
            color[vertex] = c;
            if (graphColoringUtil(graph, color, m, vertex + 1))
                return true;
            color[vertex] = 0; // Backtrack
        }
    }

    return false;
}

bool graphColoring(vector<vector<int>> &graph, int m)
{
    vector<int> color(graph.size(), 0);
    if (!graphColoringUtil(graph, color, m, 0))
    {
        cout << "Solution does not exist.";
        return false;
    }
    // Print the solution
    cout << "Solution Exists: The following are the assigned colors:\n";
    for (int i = 0; i < color.size(); ++i)
        cout << "Vertex " << i << ": Color " << color[i] << '\n';
    return true;
}

int main()
{
    int m;
    cout << "Enter number of colors available: ";
    cin >> m;
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };

    if (graphColoring(graph, m))
        cout << "Graph Coloring is possible :)";
    else
        cout << "Graph Coloring is not possible ;(";

    return 0;
}
