#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
    }
};

Node* isParent(Node *root,Node* p,Node* q){
    if(!root || root==p || root==q) return root;
    Node* l=isParent(root->left, p, q) ,*r = isParent(root->right,p, q);
    if(!l && !r) return NULL;
    if(l && r) return root;
    else if(l) return l;
    else if(r) return r;
    return NULL;
}

int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    root->right->right->right=new Node(8);
    Node *ans=isParent(root,root->right->right,root->right->right->right);
    cout<<ans->data<<endl;
}