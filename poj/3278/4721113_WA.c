#include<stdio.h>

long determine(long x,long y){
    if( x >= y ) return x-y ;
    else{
         if(x >= ((3*y)/4) )return y-x;
         else if( x>=((y+1)/2) )return x-(y/2)+1;
         else return 1+(y%2)+determine(x,y/2);
    }
}

int main()
{
    long n,k;
    while(scanf("%ld%ld",&n,&k)==2){
          long m;
          m=determine(n,k);
          printf("%ld\n",m);
    }
    return 0;
}
