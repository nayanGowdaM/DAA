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

vector<vector<int>> PreInPostOrder(Node* root){
    vector<vector<int>> ans(3,vector<int>());
    stack<pair<Node*,int>>st;
    st.push({root,1});
    while(!st.empty()){
        auto  temp=st.top();
        if(temp.second==1){
            ans[0].push_back(temp.first->data);
            st.pop();
            temp.second++;
            st.push(temp);
            if(temp.first->left)st.push({temp.first->left,1});
        }
        else if(temp.second==2){
            ans[1].push_back(temp.first->data);
            st.pop();
            temp.second++;
            st.push(temp);
            if(temp.first->right) st.push({temp.first->right,1});
        }
        else{
            st.pop();
            ans[2].push_back(temp.first->data);
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
    vector<vector<int>> ans=PreInPostOrder(root);
    for(auto x: ans){
        for(auto y:x) cout<<y<<" ";
        cout<<endl;
    }
    return 0;

}