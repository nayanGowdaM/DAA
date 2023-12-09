#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter the number of vertices and edges:";
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i=0;i<=n;i++){
        cout<<i<<": ";
        for(auto x: adj[i]) cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}