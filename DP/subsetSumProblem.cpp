#include<bits/stdc++.h>
using namespace std;

// Approach-> recursive
class Solution {
  public:
  
    bool solve(vector<int>& arr, int target, int idx){
        if(target == 0) return true;
        if(idx == 0) return arr[0] == target;
        
        bool notTake = solve(arr, target, idx-1);
        bool take = false;
        if(target > arr[idx]) take = solve(arr, target-arr[idx], idx-1);
        return notTake || take;
    }
    
    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();
        return solve(arr, target, n-1);
    }
};

// Approach-> memoization

class Solution {
  public:
  
    bool solve(vector<int>& arr, int target, int idx, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(idx == 0) return arr[0] == target;
        if(dp[idx][target] != -1) return dp[idx][target];
        bool notTake = solve(arr, target, idx-1, dp);
        bool take = false;
        if(target >= arr[idx]) take = solve(arr, target-arr[idx], idx-1, dp);
        return dp[idx][target] = notTake | take;
    }
    
    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return solve(arr, target, n-1, dp);
    }
};

// Approach-> tabulation

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(target+1, false));
        for(int i = 0; i < n; i++){
            dp[i][0] = true;
        }
        if (arr[0] <= target) {
            dp[0][arr[0]] = true;
        }
        for(int i = 1; i < n; i++){
            for(int t = 1; t <= target; t++){
                bool notTake = dp[i-1][t];
                bool take = false;
                if(t >= arr[i]) take = dp[i-1][t-arr[i]];
                dp[i][t] = take || notTake;
            }
        }
        return dp[n-1][target];
    }
};
