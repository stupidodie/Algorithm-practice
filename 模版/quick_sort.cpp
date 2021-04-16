#include<iostream>

using namespace std;

int q[100010];

void quick_sort(int q[],int l ,int r){
    if (l >= r)
        return; // 终止条件 即一个数 或者传入不合法时
    int i = l - 1;
    int j = r + 1;
    int x = q[(l + r) >> 1]; //有可能取到l，不可能取到r
    //选l不能用i，r不能用j，因为
    while(i<j){
        while(q[++i]<x);
        while(q[--j]>x); 
        if(i<j){
            int temp=q[i];
            q[i]=q[j];
            q[j]=temp;
        }
    }
    //选j的话,j和j+1;选i的话 i-1和i；因为停下来的时候i是>=x,j是<=x,i右半边，j左半边
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r); //
}
int main(){
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&q[i]);
    }
    quick_sort(q, 0, n - 1);
    for (int i=0;i<n;i++){
        printf("%d ",q[i]);
    }
    
}
