#include<bits/stdc++.h>
using namespace std;

int knapSack(int wt[],int val[], int W,int n,int dp[][5]){
    if(n==0 || W==0 ) return 0;
    if(dp[n][W]!=-1) return dp[n][W];
    if(wt[n-1]<=W){
        return dp[n][W]=max(val[n-1]+knapSack(wt,val,W-wt[n-1],n-1,dp),knapSack(wt,val,W,n-1,dp));
    }
    else return dp[n][W]=knapSack(wt,val,W,n-1,dp);
}

int main(){
    int wt[4]={2,3,2,1},val[4]={8,6,16,11};
    int dp[5][5];
    memset(dp,-1,sizeof(dp));
    cout<<knapSack(wt,val,5,4,dp)<<endl;
    return 0;
}