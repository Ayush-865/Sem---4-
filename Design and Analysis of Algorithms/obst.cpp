#include <bits/stdc++.h>
using namespace std;

int sum(vector<int> &freq, int i, int j)
{
    int sum = 0;
    for (int it = i; it <= j; it++)
    {
        sum += freq[it];
    }
    return sum;
}

int optCost(vector<int> &freq, int i, int j)
{
    if (j < i)
        return 0;
    if (j == i)
        return freq[i];

    int freqSum = sum(freq, i, j);
    int min = INT_MAX;

    for (int r = i; r <= j; r++)
    {
        int cost = optCost(freq, i, r - 1) + optCost(freq, r + 1, j);
        if (cost < min)
            min = cost;
    }
    return min + freqSum;
}

int optimalBinarySearchTree(vector<int> &keys, vector<int> &freq, int n)
{
    return optCost(freq, 0, n - 1);
}

int main()
{
    vector<int> keys = {10, 12, 20};
    vector<int> freq = {34, 8, 50};
    int n = sizeof(keys) / sizeof(keys[0]);
    cout << "Cost of Optimal BST is "
         << optimalBinarySearchTree(keys, freq, n);
    return 0;
}