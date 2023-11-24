#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> closest(vector<pair<int,int>>& a, int k){
    priority_queue<pair<int,pair<int,int>>>pq;
    for(auto x : a){
        pq.push({x.first*x.first+x.second*x.second,x});
        if(pq.size()>k)pq.pop();
    }
    vector<pair<int,int>> ans;
    while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}

int main(){
    
    int n;
    cout<<"Enter the number of locations:  ";
    cin>>n;
    vector<pair<int,int>> v(n);
    cout<<"Enter the elements of array: ";
    for(int i=0;i<n ; i++){
        int x,y;
        cin>>x;
        cin>>y;
        v[i]={x,y};
    }
    vector<pair<int,int>> ans=closest(v,3);
    for (auto x: ans) cout<<x.first<<" "<<x.second<<endl;

    cout<<endl;
}