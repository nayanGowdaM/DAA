#include<stdio.h>
#include<stdlib.h>

int max(int x , int y){
    return (x>y) ? x: y;
}

int main(){
    int n, W;
    printf("Enter the number of objects: ");
    scanf("%d",&n);
    printf("Enter the knapsack capacity: ");
    scanf("%d",&W);
    int w[n+1],p[n+1],V[n+1][W+1],x[n+1];
    printf("\nEnter the weights\n");
    for(int i=1;i<=n ;i++) scanf("%d",&w[i]);
    printf("Enter the Profits\n");
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0 || j==0) V[i][j]=0;
            else if(j-w[i]<0) V[i][j]=V[i-1][j];
            else V[i][j] = max(V[i-1][j], V[i-1][j-w[i]]+p[i]);
        }
    }
    for(int i=0; i<=n ;i++){
        for(int j=0;j<=W;j++) printf("%d\t",V[i][j]);
        printf("\n");   
    }
    int i=n,j=W;
    for(int i=0;i<=n;i++) x[i]=0;
    while(i>=0 && j>=0){
        if(V[i][j] != V[i-1][j]) {
            x[i]=1;
            j=j-w[i];
        }
        i--;
    }

    printf("\nMax Profit is %d ", V[n][W]);
    printf("\nThe objects that are included are : ");
    for(int i=0;i<=n ;i++) if(x[i]) printf("%d\t",i);
    return 0;
}