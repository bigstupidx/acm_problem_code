#include<stdio.h>
int arrey[800];
int digit[10];
void Factorial(int n)
{
     int i,j,count,t;
     memset(arrey,0,sizeof(arrey));
     arrey[1]=1;t=1;
     for(i=2,count=0;i<=n;i++){
                               t=782;
                               while(!arrey[t])t--;
                               for(j=1;j<=t+4;j++){
                                    arrey[j]=arrey[j]*i+count;
                                    if(arrey[j]>=10){
                                                count=arrey[j]/10;
                                                arrey[j]=arrey[j]%10;
                                                      
                                     }
                                     else count=0;
                              }
     }
     return ;
}
int main()
{
    int n;
    while(scanf("%d",&n),n){
                            int i=781;
                            memset(digit,0,sizeof(digit));
                            Factorial(n);
                            while(!arrey[i])i--;
                            for(;i>0;i--)
                                         digit[arrey[i]]++;
                            printf("%d! --\n",n);
                            printf("   (0)%5d    (1)%5d    (2)%5d    (3)%5d    (4)%5d\n",
                            digit[0],digit[1],digit[2],digit[3],digit[4]);
                            printf("   (5)%5d    (6)%5d    (7)%5d    (8)%5d    (9)%5d\n",
                            digit[5],digit[6],digit[7],digit[8],digit[9]);
    }
    return 0;
}
                            
                              
