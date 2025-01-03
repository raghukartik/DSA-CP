#include<bits/stdc++.h>
using namespace std;

// Approach-1 Recursion
class Solution {
public:
    int solve(vector<vector<int>>& triangle, int r, int c){
        if(r == triangle.size() - 1) return triangle[r][c];
        
        int down = triangle[r][c] + solve(triangle, r+1, c);
        int dia = triangle[r][c] + solve(triangle, r+1, c+1);
        return min(down, dia);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        return solve(triangle, 0, 0);
    }
};

// Appraoch-2 Memoization

class Solution {
public:

    int solve(vector<vector<int>>& triangle, int r, int c, vector<vector<int>>& dp){
        if(r == triangle.size()-1) return triangle[r][c];
        if(dp[r][c] != -1) return dp[r][c];
        int down = triangle[r][c] + solve(triangle, r+1, c, dp);
        int dia = triangle[r][c] + solve(triangle, r+1, c+1, dp);
        return dp[r][c] = min(down, dia);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        solve(triangle, 0, 0, dp);
    }
};

// Approach-3 tabulationclass Solution {

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for(int i = 0; i < n; i++){
            dp[m-1][i] = triangle[m-1][i];
        }
        for(int i = m-2; i >= 0; i--){
            for(int j = i; j >= 0; j--){
                int down = triangle[i][j] + dp[i+1][j];
                int dia = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down, dia);
            }
        }
        return dp[0][0];
    }
};