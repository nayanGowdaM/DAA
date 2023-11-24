#include<bits/stdc++.h>
using namespace std;
vector<int> Fsort(vector<int>& a){
    unordered_map<int,int> mp;
    vector<int> ans;
    for(auto x: a) mp[x]++;
    priority_queue<pair<int,int>> pq;
    for(auto x : mp){
        pq.push({x.second,x.first});
    }
    while(!pq.empty()){
        auto x=pq.top();
        pq.pop();
        while(x.first){
            ans.push_back(x.second);
            x.first--;
        }
    }
    return ans;
}

int main(){
    
    int n;
    cout<<"Enter the number of elements:  ";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the elements of array: ";
    for(int i=0;i<n ; i++) cin>>v[i];
    vector<int> ans=Fsort(v);
    for (auto x: ans) cout<<x<<" ";

    cout<<endl;
}