#include<bits/stdc++.h>
using namespace std;

int dp[1002][1002];
class Solution

{
    int LCS(int n,int  m,string & s1, string& s2){
        if(m==0 || n==0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(s1[n-1]==s2[m-1]) {
            cout<<s1[n-1]<<" ";
            return dp[n][m]= 1 + LCS(n-1,m-1,s1,s2);
        }
        else return dp[n][m]= max(LCS(n-1,m,s1,s2),LCS(n,m-1,s1,s2));
    }

    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        // your code hereme
        memset(dp,-1,sizeof(dp));
        return LCS(n,m,s1,s2);
    }
};

int main(){
    string s1="CDEECDCBAEDAB",s2="EABCEAECBAAB";
    Solution s;
    cout<<s.lcs(13,6*2,s1,s2);
    cout<<endl;
    return 0;
}