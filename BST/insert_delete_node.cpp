#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node *left , *right;
    Node(int data){
        val=data;
        left=NULL;
        right=NULL;
    }
    Node(int data,Node* l,Node* r){
        val=data;
        left=l;
        right=r;
    }
};

Node* insert(Node* root, int val){
    Node* node=new Node(val);
    if(!root) return root;
    Node* dummy=root;
    while(1){
        if(root->val<val){
            if(!root->right){
                root->right=node;
                break;
            }
            else root=root->right;
        }
        else{
            if(!root->left){
                root->left=node;
                break;
            }
            else root=root->left;
        }
    }
    return dummy;
}

Node* helper(Node* root){
    if(!root->left) return root->right;
    if(!root->right) return root->left;
    Node* rightMost=root->left;
    while(rightMost->right) rightMost=rightMost->right;
    rightMost->right=root->right;
    return root->left;
}

Node* deletenode(Node* root, int val){
    if(!root) return NULL;
    Node* dummy=root;
    if(root->val==val) return helper(root);
    while(1){
        if(root->val<val){
            if(root->right->val==val){
                root->right= helper(root->right);
                break;
            }
            else root=root->right;
        }
        else{
            if(root->left->val==val) {
                root->left=  helper(root->left);
                break;
            }
            else root=root->left;
        }
    }
    return dummy;
}

void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}



int main(){

  Node* root=new Node(8);
  root -> left = new Node(5);
  root -> left -> left = new Node(4);
  root -> left -> right = new Node(7);
  root -> left -> right -> left = new Node(6);
  root -> right = new Node(12);
  root -> right -> left = new Node(10);
  root -> right -> right = new Node(14);
  root -> right -> right ->left = new Node(13);
  cout<<"Before Inserting: ";
  inorder(root);
  
  root=insert(root,9);
  cout<<endl<<"After inserting: ";
  inorder(root);

  root=deletenode(root,5);
  cout<<endl<<"After Deleting: ";
  inorder(root);

  cout<<endl;
}