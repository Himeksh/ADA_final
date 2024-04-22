 #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the length of the longest common subsequence
int longestCommonSubsequence(const string& text1, const string& text2) {
    int m = text1.size();
    int n = text2.size();

    // Create a 2D DP table to store the lengths of LCS for all subproblems
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the DP table bottom-up
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1; // If characters match, increment LCS length
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // Otherwise, take the maximum of left or top cell
            }
        }
    }

    // Return the length of LCS for the entire sequences
    return dp[m][n];
}
int main() {
    string text1 = "abcde";
    string text2 = "ace";
    int length = longestCommonSubsequence(text1, text2);
    cout << "Length of Longest Common Subsequence: " << length << endl;
    return 0;
}
