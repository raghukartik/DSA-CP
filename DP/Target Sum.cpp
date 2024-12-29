#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(vector<int>& nums, int idx, int target, int sum, unordered_map<string, int>& mpp){
        if(idx == nums.size()){
            if(sum == target) return 1;
            else return 0;
        }
        string key = to_string(idx) + "_" + to_string(sum);
        if(mpp.count(key)) return mpp[key];
    
        int add = solve(nums, idx+1, target, sum + nums[idx], mpp);
        int sub = solve(nums, idx+1, target, sum - nums[idx], mpp);

        return mpp[key] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> mpp;
        return solve(nums, 0, target, 0, mpp);
    }
};