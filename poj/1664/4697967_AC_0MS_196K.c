#include<stdio.h>

int m,n;

int f(int m,int n)
{
    if(n==1||m==0)return 1;//只有一个盘子或者苹果数目为0 
    if(n>m) return f(m,m);//盘子数目大于苹果数目 
    return (f(m,n-1)+f(m-n,n));
}
    
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
               scanf("%d%d",&m,&n);
               printf("%d\n",f(m,n));
    }
    return 0;
} 
