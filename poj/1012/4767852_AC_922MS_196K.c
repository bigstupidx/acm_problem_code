#include<stdio.h>

int joseph(int k,int m)
{
    int i,a=1;
    for(i=1;i<=k;i++){
         a=(a+m-1)%(2*k-i+1);
         if(!a)a=2*k-i+1;
         if(a<=k&&a>=1)return 0;
    }
    return 1;
}
long long solve(int k)
{
     int h;
     long long r,m;
     for(r=0;;r++)
        for(h=k+1;h<=2*k;h++){
             m=2*k*r+h;
             if(joseph(k,m))goto end;
     }
     end:return m;
}
     

int main()
{
    int i;
    long long so[15];
    for(i=1;i<15;i++)
        so[i]=solve(i);
    while(scanf("%d",&i),i)printf("%ld\n",so[i]);
    return 0;
}
    
