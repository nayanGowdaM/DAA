#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node *left, *right;
    Node(int data){
        val=data;
        left=NULL;
        right=NULL;
    }
};

void levelorder(Node* root){
    if(!root) return ;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            Node* temp=q.front();
            q.pop();
            cout<<temp->val<<" ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}

int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    cout<<"Level Order Treaversal:  ";
    levelorder(root);
    cout<<endl;
    return 0;

}