#include<bits/stdc++.h>
using namespace std;

int main(){
    // 7 8


    string s1="abcde",s2="abfce";
    int m=s1.size(),n=s2.size(),ans=0;
    vector<vector<int>>dp(m+1,vector<int>(n+1));
    for(int i=0;i<=m; i++) dp[i][0]=0;
    for(int i=0;i<=n;i++) dp[0][i]=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]) {
                
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    cout<< m+n-dp[m][n]<<endl;
    
    return 0;
}