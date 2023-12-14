#include<bits/stdc++.h>
using namespace std;
vector<int>res;
void topo(vector<int> adj[],int n){
    vector<int>indegree(n,0);
    queue<int> q;
    for(int i=0;i<n;i++){
        for(auto x: adj[i]){
            indegree[x]++;
        }
    }
    for(int i=0;i<n;i++) if(!indegree[i]) q.push(i);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto y: adj[x]){
            indegree[y]--;
            if(!indegree[y]) q.push(y);
        }
        res.push_back(x);
    }

}

int main() {

	//V = 6;
	vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
	int V = 6;
	topo(adj,V);

	for (auto node : res) {
		cout << node << " ";
	}
	cout << endl;

	return 0;
}