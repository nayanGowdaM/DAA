#include<bits/stdc++.h>
using namespace std;

int main(){
    int wt[4]={2,3,2,1},val[4]={8,6,16,11};
    int n=4,W=5;
    int dp[n+1][W+1];
    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int i=0;i<=W;i++) dp[0][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(wt[i-1]<=j) dp[i][j]=max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[n][W];
    cout<<endl;
    return 0;
}