#include <bits/stdc++.h>
using namespace std;

typedef pair<int,pair<int,int>> ppi;
class Solution{
    public:
    Solution(){}
    vector<pair<int,int>>  mst(int n, vector<vector<int>> adj[]){
        vector<int>vis(n,0);
        vector<pair<int,int>> mst;
        priority_queue<ppi, vector<ppi>,greater<ppi>> q;
        q.push({0,{0,-1}});
        int sum=0;
        while(!q.empty()){
            int wt=q.top().first,node=q.top().second.first, par=q.top().second.second;
            q.pop();
            if(!vis[node]){
                vis[node]=1;
                sum+=wt;
                if(par!=-1)
                mst.push_back({par,node});
                for(auto x: adj[node]){
                    if(!vis[x[0]]){
                        q.push({x[1],{x[0],node}});
                    }
                }
            }
        }
        cout<<sum<<endl;
        return mst;
    }
};

int main() {

	int V = 5;
	vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
	vector<vector<int>> adj[V];
	for (auto it : edges) {
		vector<int> tmp(2);
		tmp[0] = it[1];
		tmp[1] = it[2];
		adj[it[0]].push_back(tmp);

		tmp[0] = it[0];
		tmp[1] = it[2];
		adj[it[1]].push_back(tmp);
	}

    Solution obj;
    auto ans=obj.mst(V , adj);
    for(auto x: ans){
        cout<<x.first<<" "<<x.second<<endl;
    }
	return 0;
}