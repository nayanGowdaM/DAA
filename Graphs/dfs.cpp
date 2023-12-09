#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
void dfs(vector<vector<int>>& a,vector<int>& vis, int src){
    vis[src]=1;
    ans.push_back(src);
    for(int i=0;i<vis.size();i++){
        if(!vis[i]  && a[src][i]){
            dfs(a,vis,i);
        }
    }
}

int main(){
    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    vector<vector<int>> a(n, vector<int>(n));
    vector<int> vis(n);
    cout<<"Enter the adj matrix\n";
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>a[i][j] ;
    for(int i=0;i<n;i++) if(!vis[i]) dfs(a,vis,i);
    cout<<"Dfs traversal : ";
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    return 0;
}