#include<stdio.h>

int main()
{
   int a,b,c,d;
   while(scanf("%d%d%d%d",&a,&b,&c,&d)&&a!=0&&b!=0&&c!=0&&d!=0){
         int temp;
         float x,y;
         if(a>b){temp=a;a=b;b=temp;}
         if(c>d){temp=c;c=d;d=temp;}
         x=(float)c/a;y=(float)d/b;
         if(x<y)printf("%d%%\n",(int)(x*100));
         else printf("%d%%\n",(int)(y*100));
   }
   return 0;
}
        
