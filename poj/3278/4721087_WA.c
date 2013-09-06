#include<stdio.h>

int determine(int x,int y){
    if( x >= y ) return x-y ;
    else{
         if(x >= ((3*y)/4) )return y-x;
         else if( x>=((y+1)/2) )return x-(y/2)+1;
         else return 1+(y%2)+determine(x,y/2);
    }
}

int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)==2){
          int m;
          m=determine(n,k);
          printf("%d\n",m);
    }
    return 0;
}
