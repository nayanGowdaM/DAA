#include<bits/stdc++.h>
using namespace std;

int main(){
    // 7 8

    string str="axxzxy",dummy=str;
    int n=str.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=(str[i-1]==dummy[j-1] && i!=j)? dp[i-1][j-1]+1:max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<< dp[n][n]<<endl;
    string s="";
    int i=n,j=n;
    while(i>0 && j>0){
        if(str[i-1]==dummy[j-1]  && i!=j){
            s.push_back(str[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }
    cout<<s<<endl;
    return 0;
}