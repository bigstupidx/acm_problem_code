#include<stdio.h>
int main()
{
    long x,y,m,n,l;
    int i;
    scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l);
    if(x!=y&&m==n)
        printf("Impossible");
    else{
      for(i=0;;i++)
         if(((i*m)%l+x)==((i*n)%l+y))
            break;
      printf("%lld\n",i);
    }
    return 0;
}