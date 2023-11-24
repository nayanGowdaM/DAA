#include<bits/stdc++.h>
using namespace std;
class heap{
    private:
    vector<int> v;
    int n;

    void heapifyUp(int i){
        if(i>1 && v[i]>v[i/2]){
            swap(v[i],v[i/2]);
            heapifyUp(i/2);
        }
    }
    void heapifyDown(int i){
        int li=2*i,ri=2*i+1,largest=i;
        if(li<=n && v[li]>v[largest]) largest=li;
        if(ri<=n && v[ri]>=v[largest]) largest=ri;
        if(largest!=i){
            swap(v[largest],v[i]);
            heapifyDown(largest);
        }

    }

    public:
    heap(){
        v.push_back(INT_MAX);
        n=0;
    }
    void push(int val){
        n++;
        v.push_back(val);
        heapifyUp(n);
    }
    int top(){
        return v[1];
    }
    void pop(){
        v[1]=v[n];
        n--;
        v.pop_back();
        heapifyDown(1);
    }
    bool empty(){
        return n==0;
    }
    int size(){
        return n;
    }
    void print(){
        // cout<<v.size()<<endl;
        for(int i=1;i<=n;i++) cout<<v[i]<<" ";
    }

};

int main(){
    heap pq;
    cout<<pq.empty();
    pq.push(60);
    pq.push(50);
    pq.push(30);
    pq.push(20);
    pq.push(40);
    pq.push(100);
    cout<<pq.size();
    cout<<pq.top();
    pq.print();
    pq.pop();
    pq.pop();
    pq.print();
}