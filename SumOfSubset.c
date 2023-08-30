#include<stdio.h>
#include<stdlib.h>

#define SIZE 20
int w[SIZE] , x[SIZE] , d;

void sum_subset(int s, int k, int r){
    static int b=1;
    int i;
    x[k]=1;
    if(s+w[k]==d){
        printf("Subset %d : ",b++);
        for(i=0;i<=k;i++) if(x[i]) printf("\t%d",w[i]);
        printf("\n");
    }
    else {
        if(s+w[k]+w[k+1]<=d) sum_subset(s+w[k],k+1,r-w[k]);
    }
    if(s+r-w[k] >=d && s+w[k+1] <=d) {
        x[k]=0;
        sum_subset(s,k+1,r-w[k]);
    }

    if(b==1) {
        printf("No Subsets Exists");
        exit(0);
    }
}

int main(){
    int n,i,sum=0;
    printf("Enter the number of elements in set: ");
    scanf("%d",&n);
    printf("Enter the elements in ascending order:\n");
    for(i=1;i<=n;i++){ 
        scanf("%d", &w[i]);
        sum+=w[i];
    }
    printf("Enter the target : ");
    scanf("%d",&d);
    if(sum<d || d<w[1]){
        printf("NO Subsets");
        return 0;
    }
    sum_subset(0,1,sum);
    return 0;
}