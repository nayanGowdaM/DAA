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
void preorderRecc(vector<int>& ans, Node* root){
    if(!root) return ;
    ans.push_back(root->data);
    preorderRecc(ans,root->left);
    preorderRecc(ans,root->right);
}

vector<int> preorderIter(Node* root){
    vector<int> ans;
    if(!root) return ans;
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        root=st.top();
        st.pop();
        ans.push_back(root->data);
        if(root->right) st.push(root->right);
        if(root->left)  st.push(root->left);

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
    preorderRecc(ansR,root);
    vector<int>ansI=preorderIter(root);
    cout<<"Preorder(Reccursive):  ";
    for(auto x: ansR) cout<<x<<" ";
    cout<<"Preorder(Iterative):  ";
    for(auto x: ansI) cout<<x<<" ";
    cout<<endl;
    return 0;

}