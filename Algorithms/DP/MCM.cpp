#include <bits/stdc++.h>
using namespace std;

int matrixChainMultiplication(vector<int> &dims, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len < n; len++)
    {
        for (int i = 1; i < n - len + 1; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k] + dp[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[1][n - 1];
}

int main()
{
    int n;
    cin >> n;

    vector<int> dims(n + 1);
    for (int i = 0; i <= n; i++)
    {
        cin >> dims[i];
    }

    int result = matrixChainMultiplication(dims, n + 1);
    cout << "Minimum cost of multiplication: " << result << endl;

    return 0;
}
