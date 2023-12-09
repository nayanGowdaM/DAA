#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter number of nodes and edges: ";
    cin>>n>>m;
    int a[n][n];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) a[i][j]=0;
    for(int i=0;i<m;i++){
        cout<<"Enter "<<i+1<<"th edge: ";
        int u,v;
        cin>>u>>v;
        a[u][v]=1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout<<a[i][j]<< " ";
        cout<<endl;
    }
    return 0;
}