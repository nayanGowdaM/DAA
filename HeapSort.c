#include <stdio.h>
#include <stdlib.h>

void heapify(int a[],int n)
{
    int i,k,v,j,flag=0;
    for(i=n/2;i>=1;i--)
    {
        k=i;
        v=a[k];
        while(!flag && 2*k <= n)
        {
            j=2*k;
            if(j<n)
            {
                if(a[j]<a[j+1])
                    j=j+1;
            }
            if(v>=a[j])
                flag=1;
            else
            {
                a[k]=a[j];
                k=j;
            }
        }
        a[k]=v;
        flag=0;
    }
}

void heapSort(int a[],int n){
    for(int i=n;i>=1;i--){
        int t=a[i];
        a[i]=a[1];
        a[1]=t;
        heapify(a,i-1);
    }
}

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of array:\n");
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    heapify(a,n);
    heapSort(a,n);
    printf("Sorted array is: ");
    for(int i=1;i<=n;i++) printf("%d\t",a[i]);
    printf("\n");
    return 0;
}