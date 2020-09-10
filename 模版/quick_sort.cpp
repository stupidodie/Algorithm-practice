#include<iostream>

using namespace std;

int q[100010];

void quick_sort(int q[],int l ,int r){
    if(l>=r) return ;
    int x=q[(l+r)>>1];int i=l-1;int j=r+1;//选l不能用i，r不能用j
    while(i<j){
        while(q[++i]<x);
        while(q[--j]>x);
        if(i<j){
            int temp=q[i];
            q[i]=q[j];
            q[j]=temp;
        }
    }
    quick_sort(q,l,j);quick_sort(q,j+1,r);//选j的话,j和j+1;选i的话 i-1和i；因为停下来的时候i是>=x,j是<=x,i右半边，j左半边
}
int main(){
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&q[i]);
    }
    quick_sort(q,0,n-1);
    for (int i=0;i<n;i++){
        printf("%d ",q[i]);
    }
    
}
