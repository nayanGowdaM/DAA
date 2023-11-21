#include<bits/stdc++.h>
using namespace std;
class LRUCache{
    public:
    class Node{
        public:
        int key,val;
        Node *prev,*next;
        Node(int key_,int val_){
            key=key_;
            val=val_;

        }
    };
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    int cap;
    map<int,Node*> mp;
    LRUCache(int cap_){
        cap=cap_;
        head->next=tail;
        tail->prev=head;
    }
    void addNode(Node* node){
        node->next=head->next;
        node->prev=head;
        head->next->prev=node;
        head->next=node;

    }
    void delNode(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
    int get(int key_){
        int ans=-1;
        if(mp.find(key_)!=mp.end()){
            Node* temp=mp[key_];
            ans=temp->val;
            delNode(temp);
            mp.erase(key_);
            addNode(temp);
            mp[key_]=head->next;
             
        }
        return  ans;
    }

    void put(int key_,int val_){
        if(mp.find(key_)!=mp.end()){
            Node* temp=mp[key_];
            delNode(temp);
            mp.erase(key_);
        }
        if(mp.size()==cap){
            Node* temp=tail->prev;
            mp.erase(temp->key);
            delNode(temp);
            
        }
        addNode(new Node(key_,val_));
        mp[key_]=head->next;
    }

};

int main(){
    LRUCache* lru=new LRUCache(2);
    lru->put(1,1);
    lru->put(2,2);
    cout<<lru->get(1)<<endl;
    lru->put(3,3);
    cout<<lru->get(2)<<endl;
    lru->put(4,.4);
    cout<<lru->get(1)<<endl;
    cout<<lru->get(3)<<endl;
    cout<<lru->get(4)<<endl;
    return 0;
}