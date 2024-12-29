#include<bits/stdc++.h>
using namespace std;

int isPossible(vector<int>& bloomDay, int mid, int k){
    int n = bloomDay.size();
    int consecutive_f = 0;
    int numBouq = 0;
    for(int i = 0; i < n; i++){
       if(bloomDay[i] <= mid){
        consecutive_f++;
        if(consecutive_f == k){
            numBouq++;
            consecutive_f = 0;
        }
       }else{
         consecutive_f = 0;
       }
    }

    return numBouq;
}

int minDays(vector<int>& bloomDay, int m, int k){
    int low = 1, high = *max_element(begin(bloomDay), end(bloomDay));
    int ans = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(m == isPossible(bloomDay, mid, k)){
            ans = mid;
            high = mid -1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    int n, m, k;
    cin>>n >> m >> k;
    vector<int> bloomDay(n, 0);
    for(int i = 0; i < n; i++){
        cin>>bloomDay[i];
    }
    cout<<minDays(bloomDay, m, k);
}