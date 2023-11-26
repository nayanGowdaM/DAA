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

void postorderRecc(vector<int>& ans, Node* root){
    if(!root) return ;
    postorderRecc(ans, root->left);
    postorderRecc(ans, root->right);
    ans.push_back(root->data);
}


vector<int> postorder1Stack(Node* root){
    vector<int> ans;
    if(!root) return ans;
    stack<Node*>st;
    while(root || !st.empty()){
        if(root){
            st.push(root);
            root=root->left;
        }
        else{
            Node* temp=st.top()->right;
            if(!temp){
                temp=st.top();
                st.pop();
                ans.push_back(temp->data);
                while(!st.empty() && temp== st.top()->right){
                    temp=st.top();
                    st.pop();
                    ans.push_back(temp->data);
                }
            }
            else root=temp;
        }
    }
    return ans;
}

vector<int>postorder2Stack(Node* root){
    vector<int> ans;
    if(!root) return ans;
    stack<Node*> s1,s2;
    s1.push(root);
    while(!s1.empty()){
        Node* temp=s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left) s1.push(temp->left);
        if(temp->right) s1.push(temp->right);
    }
    while(!s2.empty()){
        ans.push_back(s2.top()->data);
        s2.pop();
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
    postorderRecc(ansR,root);
    vector<int>ansI1=postorder1Stack(root);
    vector<int>ansI2=postorder2Stack(root);
    cout<<"PostOrder(Reccursive):  ";
    for(auto x: ansR) cout<<x<<" ";
    cout<<"Preorder(Iterative Single Stack):  ";
    for(auto x: ansI1) cout<<x<<" ";
    cout<<"Preorder(Iterative Double Stack):  ";
    for(auto x: ansI2) cout<<x<<" ";
    cout<<endl;
    return 0;

}