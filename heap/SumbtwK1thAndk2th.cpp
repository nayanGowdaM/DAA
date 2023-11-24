/*Given an array of elements Find the sum of elements between k1 th snallest and k2 th smallert elements;*/
#include<bits/stdc++.h>
using namespace std;
int sum(vector<int>& a,int k1,int k2){
    if(k1==k2) return 0;
    if(k1>k2)swap(k1,k2);
    int ans=0;
    priority_queue<int> pq;
    for(auto x : a){
        pq.push(x);
        if(pq.size()>=k2) pq.pop();
    }
    while(pq.size()>k1){
        ans+=pq.top();
        pq.pop();
    }
    return ans;
}

int main(){
        
    int n,k1,k2;
    cout<<"Enter the number of elements:  ";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the elements of array: ";
    for(int i=0;i<n ; i++) cin>>v[i];
    cout<<"Enter k1 and k2:  ";
    cin>>k1>>k2;
    if(k1>n || k2>n) cout<<"Out of array length!!";
    else {
        if(k1>k2) swap(k1,k2);
        int ans=sum(v,k1,k2);
        cout<<ans;
    }

    cout<<endl;
}