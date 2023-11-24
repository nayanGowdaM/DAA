/*There are n ropes of length a[i] 
The task is to connect to ropes in such a way that that leeds to minimun cost
cost is defined as the length of ropes after connection
1 2 3 4
Let ropws are connected in the same order
cost (1,2) = 3
cost(3,3)  = 6
cost (6,4) = 10
hence the total cost is 3+6+10=19*/
#include<bits/stdc++.h>
using namespace std;

int minCost(vector<int>& v){
    priority_queue<int,vector<int>,greater<int>> pq;
    for(auto x: v) pq.push(x);
    int ans;
    while(pq.size()!=1){
        int x=pq.top();
        pq.pop();
        int y=pq.top();
        pq.pop();
        ans+=x+y;
        pq.push(x+y);
    }
    return ans;
}

int main(){
    
    int n;
    cout<<"Enter the number ropes:  ";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the length of ropes: ";
    for(int i=0;i<n ; i++) cin>>v[i];
    int ans=minCost(v);
    cout<<ans;

    cout<<endl;
}