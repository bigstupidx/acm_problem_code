/*
http://hi.baidu.com/anshang/blog/item/01fc5710e2ab3cfac2ce7953.html
*/
#include<stdio.h>
#include<math.h>
#include<string.h>
int arrey[2][24];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
               int w,threes=1;
               int i,j,k;
               memset(arrey,0,sizeof(arrey));
               scanf("%d",&w);
               i=0;j=0;
               while(w>0){
                          int temp;
                          double c;
                          temp=w%3;
						  c=w/3.0;
						  if((c-(int)c)>0.5)
						  w=c+1;
						  else w=c;
                          if(temp==1)
                                     arrey[1][i++]=threes;
                          else if(temp==2)
                                      arrey[0][j++]=threes;
                          threes*=3;
               }
               for(i=0;arrey[0][i];i++){
                                        printf("%d",arrey[0][i]);
                                        if(arrey[0][i+1])
                                        printf(",");
               }
               if(!i)printf("empty");
               printf(" ");
               for(i=0;arrey[1][i];i++){
                                        printf("%d",arrey[1][i]);
                                        if(arrey[1][i+1])
                                        printf(",");
               }
               printf("\n");
    }
    return 0;
}
               
    
