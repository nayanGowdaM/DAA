#include<stdio.h>
#include<stdlib.h>
#define N 100
int result[N],a[N][N],vis[N],k=-1;

void dfs(int src,int n){
    vis[src]=1;
    for(int i=0;i<n;i++){
        if(a[src][i]==1 && vis[i]==0) dfs(i,n);
    }
    result[++k]=src;
}

void DFS(int n){
    int ct=0;
    for(int i=0;i<n;i++) vis[i]=0;
    for(int i=0;i<n; i++){
        if(vis[i]==0){
            dfs(i,n);
            ct++;
        }
    }
    if(ct==1) printf("\nConnected Graph");
    else printf("\nUnconnected Graph");

}

int main(){
    int  n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for(int i=0;i<n; i++){
        for(int j=0;j<n;j++) scanf("%d",&a[i][j]);
    }
    DFS(n);
    printf("\nTopologincal Ordering : ");
    while(k>=0) printf("%d\t",result[k--]);
}