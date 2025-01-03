#include<bits/stdc++.h>
using namespace std;

// Approach-1 Recursion
class Solution {
public:
    int solve(vector<vector<int>>& matrix, int r, int c) {
        if (c < 0 || c >= matrix[0].size()) return 1e9;
        if (r == matrix.size() - 1) return matrix[r][c]; 
    
        int down = matrix[r][c] + solve(matrix, r + 1, c);
        int diaLeft = matrix[r][c] + solve(matrix, r + 1, c - 1);
        int diaRight = matrix[r][c] + solve(matrix, r + 1, c + 1);
        
        return min(down, min(diaLeft, diaRight));
    }
      
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            ans = min(solve(matrix, 0, i), ans);
        }
        return ans;
    }
};

// Approach-2 memoization

class Solution {
public:
    int solve(vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& dp) {
        if (c < 0 || c >= matrix[0].size()) return 1e9;
        if (r == matrix.size() - 1) return matrix[r][c]; 
        if(dp[r][c] != -1) return dp[r][c];
        int down = matrix[r][c] + solve(matrix, r + 1, c, dp);
        int diaLeft = matrix[r][c] + solve(matrix, r + 1, c - 1, dp);
        int diaRight = matrix[r][c] + solve(matrix, r + 1, c + 1, dp);
        
        return dp[r][c] = min(down, min(diaLeft, diaRight));
    }
      
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            ans = min(solve(matrix, 0, i, dp), ans);
        }
        return ans;
    }
};

// Approach-3 Tabulation

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            dp[n - 1][i] = matrix[n - 1][i];
        }
        for (int r = n - 2; r >= 0; r--) {
            for (int c = 0; c < n; c++) {
                int down = dp[r + 1][c];
                int diaLeft = (c > 0) ? dp[r + 1][c - 1] : INT_MAX;
                int diaRight = (c < n - 1) ? dp[r + 1][c + 1] : INT_MAX;
                
                dp[r][c] = matrix[r][c] + min(down, min(diaLeft, diaRight));
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(dp[0][i], ans);
        }

        return ans;
    }
};

