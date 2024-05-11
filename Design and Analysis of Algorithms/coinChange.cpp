#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> coins, int i, int target)
{
    if (target == 0)
        return 1;

    if (i < 0 || target < 0)
        return 0;

    int notTake = solve(coins, i - 1, target);
    int take = 0;
    if (coins[i] <= target)
        take = solve(coins, i, target - coins[i]);

    return notTake + take;
}

int main()
{
    vector<int> coins = {1, 2, 3};
    int target = 5;
    int n = coins.size();
    cout << solve(coins, n - 1, target);
    return 0;
}