#include<bits/stdc++.h>
using namespace std;

// Approach-1

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_map<int, int> mpp;
        priority_queue<int, vector<int>> q;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            mpp[arr[i]]++;
        }
        int i = 1;
        while(q.size() < k){
            if(mpp.find(i) == mpp.end()) q.push(i);
            i++;
        }
        return q.top();
    }
};

// Approach-2 Binary Search on Ans

class Solution {
public:
    int findKthPositive(vector<int> vec, int k) {
        int n = vec.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int missing = vec[mid] - (mid + 1);
            if (missing < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return k + high + 1;
    }
};