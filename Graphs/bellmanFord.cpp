#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> bellmanFord(int n, vector<vector<int>>& edges, int src){
        vector<int>dist(n, INT_MAX);
        dist[src]=0;
        for(int i=0;i<n-1;i++){
            for(auto x:edges){
                int u=x[0],v=x[1],w=x[2];
                if(dist[u]!=INT_MAX && dist[u]+w<dist[v]) dist[v]=dist[u]+w;
            }
        }
        for(auto x: edges){
            int u=x[0],v=x[1],w=x[2];
            if(dist[u]!=INT_MAX && dist[u]+w<dist[v]) return {-1};
        }
        return dist;
    }
};

int main() {

	int n = 6;
	vector<vector<int>> edges(7, vector<int>(3));
	edges[0] = {3, 2, 6};
	edges[1] = {5, 3, 1};
	edges[2] = {0, 1, 5};
	edges[3] = {1, 5, -3};
	edges[4] = {1, 2, -2};
	edges[5] = {3, 4, -2};
	edges[6] = {2, 4, 3};

	int src = 0;
	Solution obj;
	vector<int> dist = obj.bellmanFord(n, edges, src);
	for (auto d : dist) {
		cout << d << " ";
	}
	cout << endl;

	return 0;
}