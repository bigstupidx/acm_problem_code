
#include<stdio.h>
#include<math.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
               char temp[2][3];
               int a,b;
               scanf("%s%s",temp[0],temp[1]);
                   
                   a=abs(temp[0][0]-temp[1][0]);
                   b=abs(temp[0][1]-temp[1][1]);
				   if(a==0&&b==0)
					   printf("0 0 0 0\n");
                   
                   if(a<b)
                        printf("%d ",b);
                   else printf("%d ",a);
                   
                   if(a==0||b==0||a==b)
                        printf("1 ");
                   else printf("2 ");
                   
                   if(a==0||b==0)
                        printf("1 ");
                   else printf("2 ");
                   
                   if((abs(a-b))%2)
                        printf("Inf\n");
                   else if(a==b)printf("1\n");
                   else printf("2\n");
    }
    return 0;
}
