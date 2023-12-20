#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank,par;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        par.reserve(n+1);
        for(int i=0;i<=n;i++) par[i]=i;
    }

    int findParent(int node){
        if(node==par[node]) return node;
        return par[node]=findParent(par[node]);
    }

    void unionByRank(int u,int v) {
        int upU=findParent(u),upV=findParent(v);
        if(upU==upV) return ;

        if(rank[upU]<rank[upV]) par[upU]=upV;
        else if(rank[upV]<rank[upU]) par[upV]=upU;
        else {
            par[upV]=upU;
            rank[upU]++;
        }
    }
};


int main(){
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    if(ds.findParent(3)==ds.findParent(7)) cout<<"Same";
    else cout<<"NotSame";
    cout<<endl;
    ds.unionByRank(3,7);
    if(ds.findParent(3)==ds.findParent(7)) cout<<"Same";
    else cout<<"NotSame";
    cout<<endl;
}