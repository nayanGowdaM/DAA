#include<stdio.h>
#include<stdlib.h>

#define SIZE 100
int cost[SIZE][SIZE],vis[SIZE],dist[SIZE];


void diji(int n, int src){
    int i,j,v,min;
    for(i=1;i<=n;i++){
        vis[i]=0;
        dist[i]=cost[src][i];
    }
    
    int ct=1;
    vis[src] =1;
    dist[src]=0;
    for(j=1;j<=n ;j++) printf("\t%d",dist[j]);
    while(ct<n){
        min=999;
        for(j=1;j<n;j++){
            if(!vis[j] && min> dist[j]) {
                min=dist[j];
                v=j;
            }
        }
        vis[v]=1;
        ct++;
        for(i=1;i<=n;i++){
            if(!vis[i] && dist[i]>(dist[v]+cost[v][i])) dist[i]=dist[v]+cost[v][i];
        }
    }
}

int main(){
    int n,i,j,src;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    printf("Enter the cost matrix\n");
    for(i=1;i<=n;i++){ 
        for(j=1;j<=n;j++){ 
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0) cost[i][j]=999;
        }
    }
    for(i=1;i<=n;i++) for(j=1;j<=n;j++) printf("%d\t",cost[i][j]);
    printf("Enter the source vertex: ");
    scanf("%d",&src);
    diji(n,src);
    printf("The shortest path from %d is : \n",src);
    for(i=1;i<=n;i++){
        if(i!=src) printf("%d->%d\n",i,dist[i]);
    }
}