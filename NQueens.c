#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
int x[SIZE];
static int c=1;
void print(int n){
    printf("Solution %d: \n",c++);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(x[i]==j) printf("Q\t");
            else printf("_\t");
        }
        printf("\n");
    }
}

int inplace(int  k , int i){
    for(int j=1;j<k;j++){
        if(i==x[j] || abs(i-x[j])==abs(k-j)) return 0;
    }
    return 1;
}

void NQueens(int k, int n){
    for(int i=1;i<=n;i++) {
        if(inplace(k,i)) {
            x[k]=i;
            if(k==n) {printf("\n"); print(n);}
            else NQueens(k+1,n);
        }
    }
}

int main(){
    int n;
    printf("Enter the number of queens: ");
    scanf("%d",&n);
    NQueens(1,n);
    if(c==1) printf("No Solutions");
}