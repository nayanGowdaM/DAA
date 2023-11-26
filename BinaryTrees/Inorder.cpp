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

void inorderRecc(vector<int>& ans, Node* root){
    if(root==NULL) return;
    inorderRecc(ans, root->left);
    ans.push_back(root->data);
    inorderRecc(ans, root->right);
}

vector<int> inorderIter(Node* root){
    vector<int>ans;
    stack<Node*>st;
    while(1){
        if(root){
            st.push(root);
            root=root->left;
        }
        else{
            if(st.empty()) break;
            root=st.top();
            st.pop();
            ans.push_back(root->data);
            root=root->right;
        }
        
    }
    return ans;
}

int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    vector<int>ansR;
    inorderRecc(ansR,root);

    cout<<"Inorder(Reccursive):  ";
    for(auto x: ansR) cout<<x<<" ";
    vector<int>ansI=inorderIter(root);
    cout<<"Inorder(Iterative):  ";
    for(auto x: ansI) cout<<x<<" ";
    cout<<endl;
    return 0;

}