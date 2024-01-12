#include<bits/stdc++.h>
using namespace std;

int dp[502][502];
int solve(int arr[],int i, int j){
    if(i>=j) return 0;
    int ans=INT_MAX;
    if(dp[i][j]!=-1) return dp[i][j];
    for(int k=i;k<j;k++){
        ans=min(ans,solve(arr,i,k)+arr[i-1]*arr[k]*arr[j]+solve(arr,k+1,j));
    }
    return dp[i][j]=ans;
}

int main(){
    int arr[]={40, 20, 30, 10, 30};
    memset(dp,-1,sizeof(dp));
    cout<<solve(arr,1,sizeof(arr)/sizeof(int)-1)<<endl;
}