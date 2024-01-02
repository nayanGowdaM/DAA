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


    string str="";
    int i=m,j=n;
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            str.push_back(s1[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])str.push_back(s1[--i]);
        else str.push_back(s2[--j]);

    }
    while(i>0){
        str.push_back(s1[--i]);
    }
    while(j>0) str.push_back(s2[--j]);
    reverse(str.begin(),str.end());
    cout<<str<<endl;
    cout<< m+n-dp[m][n]<<endl;
    
    return 0;
}