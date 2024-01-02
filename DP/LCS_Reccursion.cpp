#include<bits/stdc++.h>
using namespace std;


class Solution

{

    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        if(m==0 || n==0) return 0;
        if(s1[n-1]==s2[m-1]) return lcs(n-1,m-1,s1,s2)+1;
        else return  max(lcs(n-1,m,s1,s2),lcs(n,m-1,s1,s2));
    }
};

int main(){
    string s1="ABCDGH",s2="AEDFHR";
    Solution s;
    cout<<s.lcs(6,6,s1,s2);
    cout<<endl;
    return 0;
}