#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank,par,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        par.resize(n+1);
        size.resize(n+1,1);
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

    void unionBySize(int u, int v){
        int upU=findParent(u),upV=findParent(v);
        if(upU==upV) return;
        if(size[upU]<size[upV] ) {
            par[upU]=upV;
            size[upV]+=size[upU];
        }
        else{
            par[upV]=upU;
            size[upU]+=size[upV];
        }
    }
};


int main(){
    cout<<"Using Rank method"<<endl;
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    if(ds.findParent(3)==ds.findParent(7)) cout<<"Same";
    else cout<<"NotSame";
    cout<<endl;
    ds.unionBySize(3,7);
    if(ds.findParent(3)==ds.findParent(7)) cout<<"Same";
    else cout<<"NotSame";

    cout<<"\n\nUsing Size method\n";
    DisjointSet ds1(7);
    ds1.unionBySize(1, 2);
    ds1.unionBySize(2, 3);
    ds1.unionBySize(4, 5);
    ds1.unionBySize(6, 7);
    ds1.unionBySize(5, 6);
    if(ds1.findParent(3)==ds1.findParent(7)) cout<<"Same";
    else cout<<"NotSame";
    cout<<endl;
    ds1.unionBySize(3,7);
    if(ds1.findParent(3)==ds1.findParent(7)) cout<<"Same";
    else cout<<"NotSame";
    cout<<endl;
}