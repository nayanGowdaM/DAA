#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
vector<int> topK(vector<int>& a,int k){
    unordered_map<int,int> mp;
    vector<int>ans;
    for(auto x: a) mp[x]++;
    priority_queue<pi,vector<pi>,greater<pi>>pq;
    for(auto x:mp){
        pq.push({x.second,x.first});
        if(pq.size()>k) pq.pop();
    }
    while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}

int main(){
    vector<int> v={1,4,1,3,1,3,2,4};
    vector<int> ans=topK(v,3);
    for(auto x : ans) cout<<x<<" ";
    cout<<endl;
};