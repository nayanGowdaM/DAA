#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 256
int table[256];
void shiftTable(char p[]){
    int m=strlen(p);
    for(int i=0;i<SIZE;i++) table[i]=m;
    for(int i=0;i<m-1;i++) table[p[i]] = m-i-1;

}

int Horspool(char t[],char p[]){
    shiftTable(p);
    int m=strlen(p),n=strlen(t);
    int i=m-1;
    while(i<n){
        int k=0;
        while(k<m && p[m-k-1]==t[i-k]) k++;
        if(k==m) return i-k+1;
        else i=i+table[t[i]];
    }
    return -1;
}

int main(){
    char t[SIZE], p[SIZE];
    printf("Enter the Pattern and Text strings\n");
    // fgets(p,SIZE,stdin);
    // fgets(t,SIZE, stdin);
    scanf("%s",t);
    scanf("%s",p);
    int i=Horspool(t,p);
    if(i==-1) printf("\nPattern Not Found");
    else printf("\nPattern found at %d",i);
    return 0;
}