#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find the minimum number of scalar multiplications needed to multiply a chain of matrices
int matrixChainOrder(const vector<int>& dims) {
    int n = dims.size() - 1; // Number of matrices
    vector<vector<int>> dp(n, vector<int>(n, 0)); // DP table to store results

    // Fill the DP table diagonally
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i < n - len + 1; ++i) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            // Try all possible splits to find the minimum cost
            for (int k = i; k < j; ++k) {
                int cost = dp[i][k] + dp[k + 1][j] + dims[i] * dims[k + 1] * dims[j + 1];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    // The result is stored in the top-right cell of the DP table
    return dp[0][n - 1];
}
int main() {
    vector<int> dimensions = {10, 30, 5, 60}; // Dimensions of matrices: 10x30, 30x5, 5x60
    int minCost = matrixChainOrder(dimensions);
    cout << "Minimum number of scalar multiplications: " << minCost << endl;
    return 0;
}
