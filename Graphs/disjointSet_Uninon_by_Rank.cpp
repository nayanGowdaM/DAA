
int main(){
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    if(ds.findParent(3)==ds.findParent(7)) cout<<"Same Parent ";
    else cout<<"Not Same Parent";
    cout<<endl;
    ds.unionByRank(3,7);
    if(ds.findParent(3)==ds.findParent(7)) cout<<"Same Parent ";
    else cout<<"Not Same Parent";
    cout<<endl;

}