#include<stdio.h>
#include<stdlib.h>
int ct=0;
#define N 1000
int a[N];
void merge(int l, int mid, int r){
    int b[r-l+2];
    int i=l,j=mid+1,k=0;
    while(i<=mid && j<=r){
        if(a[i]<a[j]){
            b[k++]=a[i++];
        }
        else b[k++]=a[j++];
        ct++;

    }
    while(i<=mid){
        b[k++]=a[i++];
        ct++;
    } 
    while(j<=r) {
        b[k++]=a[j++];
        ct++;
    }
    for(i=l;i<=r ; i++) a[i]=b[i-l];
}

void mergeSort(int l, int r){
    if(l==r) return ;
    int mid=(l+r)/2;
    mergeSort(l,mid);
    mergeSort(mid+1,r);
    merge(l,mid,r);
}

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements of array:\n");
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    mergeSort(0,n-1);
    printf("Sorted array is: ");
    for(int i=0;i<n;i++) printf("%d\t",a[i]);
    printf("\n");
    return 0;
}