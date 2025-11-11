#include<bits/stdc++.h>
using namespace std;

// Recursion
int solve_r(int idx,int max_wt,vector<int>&val,vector<int>&wt){
    if(idx==0){
        if(wt[idx]<=max_wt)return val[idx];
        return 0;
    }
    int n_take=solve_r(idx-1,max_wt,val,wt);
    int take=INT_MIN;
    if(max_wt>=wt[idx]){
        take=val[idx]+solve_r(idx-1,max_wt-wt[idx],val,wt);
    }
    return max(take,n_take);
}

int knapsack_r(int max_wt,vector<int>&val,vector<int>&wt){
    int n=val.size();
    return solve_r(n-1,max_wt,val,wt);
}


// Memoization
int solve_m(int idx,int max_wt,vector<int>&val,vector<int>&wt,vector<vector<int>>dp){
    if(idx==0){
        if(wt[idx]<=max_wt)return val[idx];
        return 0;
    }
    if(dp[idx][max_wt]!=-1)return dp[idx][max_wt];
    int n_take=solve_m(idx-1,max_wt,val,wt,dp);
    int take=INT_MIN;
    if(max_wt>=wt[idx]){
        take=val[idx]+solve_m(idx-1,max_wt-wt[idx],val,wt,dp);
    }
    return dp[idx][max_wt]=max(take,n_take);
}

int knapsack_m(int max_wt,vector<int>&val,vector<int>&wt){
    int n=val.size();
    vector<vector<int>>dp(n+1,vector<int>(max_wt+1,-1));
    return solve_m(n-1,max_wt,val,wt,dp);
}



// Tabulation
int knapsack_t(int W,vector<int>&val,vector<int>&wt){
    int n=val.size();
    vector<vector<int>>dp(n+1,vector<int>(W+1,0));
    for(int idx=1;idx<=n;idx++){
        for(int max_wt=0;max_wt<=W;max_wt++){
            int n_take=dp[idx-1][max_wt];
            int take=INT_MIN;
            if(max_wt>=wt[idx-1]){
                take=val[idx-1]+dp[idx-1][max_wt-wt[idx-1]];
            }
            dp[idx][max_wt]=max(take,n_take);
        }
    }

    cout<<"\n\nDP TABLE\n";
    for(int idx=1;idx<=n;idx++){
        for(int max_wt=0;max_wt<=W;max_wt++){
            cout<<dp[idx][max_wt]<<" ";
        }
        cout<<endl;
    }
    cout<<"\n";

    return dp[n][W];
}




int main(){
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 30;
    cout<<  "Recursion result : "<<knapsack_r(W,val,wt)<<endl;
    cout << "Memoized result: " << knapsack_m(W,val,wt) << endl;
    cout << "Tabulation result: " << knapsack_t(W,val,wt)<< endl;
    return 0;
}