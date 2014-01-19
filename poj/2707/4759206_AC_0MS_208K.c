#include<stdio.h>

int main()
{
   int a,b,c,d;
   while(scanf("%d%d%d%d",&a,&b,&c,&d)&&a!=0&&b!=0&&c!=0&&d!=0){
         int temp;
         double x,y;
         if(a>b){temp=a;a=b;b=temp;}
         if(c>d){temp=c;c=d;d=temp;}
         x=(double)c/a;y=(double)d/b;
         x=x<y?x:y;
         if(x>1)x=1;
         printf("%d%%\n",(int)(x*100));
   }
   return 0;
}
        
