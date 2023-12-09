#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
void bfs(vector<vector<int>>& a,vector<int>& vis,int src){
    queue<int> q;
    q.push(src);
    vis[src]=1;
    ans.push_back(src);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<vis.size();i++){
            if(!vis[i] && a[src][i]){
                vis[i]=1;
                q.push(i);
                ans.push_back(i);
            }
        }
    }
}
int main(){
    
    cout<<"Enter the number of nodes:";
    int n;
    cin>>n;
    vector<int>vis(n);
    vector<vector<int>> a(n, vector<int>(n));
    cout<<"Enter the adjacency  matrix\n";
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>a[i][j];
    for(int i=0;i<n;i++ ){
        if(!vis[i]){
            bfs(a, vis, i);
        }
    }
    for(auto x: ans) cout<<x<<" ";
    return 0;
}