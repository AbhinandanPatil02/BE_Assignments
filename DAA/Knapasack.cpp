#include<bits/stdc++.h>
using namespace std;


// DP 

int solve_dp(int idx,int W, vector<int> &val, vector<int> &wt,vector<vector<int>>&dp){
    if(idx>=val.size())return 0;
    if(dp[idx][W]!=-1)return dp[idx][W];
    int take=INT_MIN;
    if(W-wt[idx]>=0){
        take=val[idx]+solve_dp(idx+1,W-wt[idx],val,wt,dp);
    }
    int ntake=solve_dp(idx+1,W,val,wt,dp);
    return dp[idx][W]=max(take,ntake);
}


int knapsack_dp(int W, vector<int> &val, vector<int> &wt) {
    vector<vector<int>>dp(val.size()+1,vector<int>(W+1,-1));
    return solve_dp(0,W,val,wt,dp);
}


int knapsack_dp_tab(int W, vector<int> &val, vector<int> &wt) {
    int n=val.size();
        vector<vector<int>>dp(n+1,vector<int>(W+1,0));
        int max_wt=W;
        for(int idx=1;idx<=n;idx++){
            for(int w=0;w<=max_wt;w++){
                int n_take=dp[idx-1][w];
                int take=INT_MIN;
                if(w-wt[idx-1]>=0){
                    take=val[idx-1]+dp[idx-1][w-wt[idx-1]];
                }
                dp[idx][w]= max(take,n_take);  
            }
        }
    return dp[n][W];
}





// bnb


int main(){
    
    return 0;
}