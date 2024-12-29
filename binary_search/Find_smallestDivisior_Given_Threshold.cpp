#include<bits/stdc++.h>
using namespace std;

int isPossible(vector<int>& nums, int mid) {
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (nums[i] + mid - 1) / mid;  
    }
    return sum;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int low = 1, high = *max_element(begin(nums), end(nums));
    int ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(nums, mid) <= threshold) {  
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int threshold, n;
    cin >> n >> threshold;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << smallestDivisor(nums, threshold);
}

