#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[20001][4];
    int helper(vector<int>& subarray, int idx, int count, int k){
        if(count == 0) return 0;
        if(idx >= subarray.size()) return INT_MIN;
        if(dp[idx][count] != -1) return dp[idx][count];

        int take = subarray[idx] + helper(subarray, idx+k, count-1, k);
        int notTake = helper(subarray, idx+1, count, k);

        return dp[idx][count] = max(take, notTake);
    }

    void solve(vector<int>& subarray, int idx, int count, int k, vector<int>& result){
        if(count == 0) return;
        if(idx >= subarray.size()) return;

        int take_i = subarray[idx] + helper(subarray, idx+k, count-1, k);
        int notetake_i = helper(subarray, idx+1, count, k);

        if(take_i >= notetake_i){
            result.push_back(idx);
            solve(subarray, idx + k, count-1, k, result);
        }else{
            solve(subarray, idx+1, count, k, result);
        }
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        memset(dp, -1, sizeof(dp));
        vector<int> subarray;
        vector<int> result;
        int i = 0, j = 0, windowSum = 0;
        while(j < nums.size()){
            windowSum += nums[j];
            if(j-i+1 == k){
                subarray.push_back(windowSum);
                windowSum -= nums[i];
                i++;
            }
            j++;
        }

        solve(subarray, 0, 3, k, result);
        return result;
    }
};