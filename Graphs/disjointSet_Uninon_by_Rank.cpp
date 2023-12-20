#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int>rank,par;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        par.resize(n+1);
        for(int i=0;i<=n ;i++){
            par[i]=i;
        }
    }
    int findParent(int node){
        if(node==par[node]) return node;
        return par[node]=findParent(par[node]);
    }
    void unionByRank(int u, int v){
        int upU=findParent(u),upV=findParent(v);
        if(upU == upV) return ;
        if(rank[upU]<rank[upV]) par[upU]=upV;
        else if(rank[upU]>rank[upV]) par[upV]=upU;
        else{
            par[upV]=upU;
            rank[upU]++;
        }
    }
};

