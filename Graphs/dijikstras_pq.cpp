#include<bits/stdc++.h>
using namespace std;

vector<int> diji(vector<vector<int>>& edges,int n, int src){
    vector<pair<int,int>> adj[n];
    for(auto x: edges){
        adj[x[0]].push_back({x[1],x[2]});
        adj[x[1]].push_back({x[0],x[2]});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    vector<int> dist(n,INT_MAX);
    dist[src]=0;
    q.push({0,src});
    while(!q.empty()){
        int d=q.top().first, node=q.top().second;
        q.pop();
        for(auto x: adj[node]){
            int len=d+x.second;
            if(len<dist[x.first]){
                dist[x.first]=len;
                q.push({len,x.first});
            }
        }
    }
    for(auto& x: dist) if(x==INT_MAX) x=-1;
    return dist;
}

int main()
{
    // Driver code.
    /*
    3 3 2
    1 2 1
    0 2 2
    0 1 6
*/
    vector<vector<int>> edges={{1,2,1},{0,2,2},{0,1,6}};
    int V=3,S=2;
    vector<int> res= diji(edges,3,2);

    for (int i = 0; i < V; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}