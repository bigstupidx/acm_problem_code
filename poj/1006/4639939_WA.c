#include<stdio.h>
int main()
{
    int a,b,c,d;
    int i,j=0;
    while(scanf("%d%d%d%d",&a,&b,&c,&d)==4){
           if(a==-1&&d==-1&&a==b&&c==d)break;
           else{
                j++;
                for(i=d+1;i<=21252;i++){
                    if(!((i+d-a)%23)&&!((i+d-b)%28)&&!((i+d-c)%33)){
                      i=i+21252;
                      i=i%21252;
                      if(i=0)i=21252;
                      printf("Case %d: the next triple peak occurs in %d days.\n",j,i);
                      break;
                    }
                }
           }
    }
    return 0;
}  
