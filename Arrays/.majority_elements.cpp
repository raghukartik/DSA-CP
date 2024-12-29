#include<iostream>
#include<vector>
using namespace std;
int majorityElement(vector<int>& nums) {
        vector<int>hash;
        int major=0;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        for(int j=0;j<hash.size();j++){
            if(hash[j]>(hash.size()/2)){
                major=j;
            }
        }
        return major;
    }