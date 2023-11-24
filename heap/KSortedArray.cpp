#include<bits/stdc++.h>
using namespace std;
vector<int> sorted(vector<int>& a,int k){
    priority_queue<int,vector<int>, greater<int>> pq;
    vector<int>ans;
    for(auto x:a){
        pq.push(x);
        if(pq.size()>k){
            ans.push_back(pq.top());
            pq.pop();
        }
    }
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
int main(){
    vector<int>v={6,5,2,8,10,9};
    vector<int> ans=sorted(v,2);
    for(auto x: ans) cout<<x<<" ";
}