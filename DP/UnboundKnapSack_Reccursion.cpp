#include<bits/stdc++.h>
using namespace std;

int knapSack(int wt[],int val[], int W,int n){
    if(n==0 || W==0 ) return 0;
    if(wt[n-1]<=W){
        return max(val[n-1]+knapSack(wt,val,W-wt[n-1],n),knapSack(wt,val,W,n-1));
    }
    else return knapSack(wt,val,W,n-1);
}

int main(){
    int wt[4]={2,3,2,1},val[4]={8,6,16,11};
    cout<<knapSack(wt,val,5,4)<<endl;
    return 0;
}