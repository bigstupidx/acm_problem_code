#include<stdio.h>
#include<math.h>
int isprime(int n)
{
    int i,m;
    if(n!=2&&!(n%2))return 0;
    m=sqrt(n);
    for(i=2;i<=m;i++)
       if(!(n%i))break;
    if(i>m)return 1;
    else return 0;
}
int main()
{
    int n;
    while(scanf("%d",&n),n){
         int i;
         for(i=2;i<=n/2;i++)
            if(isprime(i)&&isprime(n-i)){
              printf("%d = %d + %d\n",n,i,n-i);break;}
    }
}
