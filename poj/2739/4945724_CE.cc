/*
素数
*/

#include<stdio.h>
#include<stdlib.h>
int arrey[10001];
int n;

int isprime(int n)
{
    int i;
    for(i=2;i<=sqrt(n);i++)
       if(!(n%i))break;
    if(i>sqrt(n))
    return 1;
    return 0;
}
void pre()
{
     int i,j;
     arrey[1]=0;
     for(i=2;i<10001;i++){
                        if(isprime(i))
                        arrey[i]=1;
                        else arrey[i]=0;
     }
    /* for(i=2;i<10001;i++)
     if(arrey[i]){
     printf("%d\n",i);
     system("pause");
     }*/
     return ;
}

int main()
{
    pre();
    while(scanf("%d",&n),n){
                            int count=0,i,j;
                            int sum;
                            for(i=2;i<=n;i++){
                                               if(!arrey[i])continue;
                                               sum=i;
                                               if(sum==n){
                                                               count++;break;
                                               }
                                               for(j=i+1;j<n;j++)
                                               if(!arrey[j])continue;
                                               else{
                                                    sum+=j;
                                                    if(sum==n){
                                                               count++;break;
                                                    }
                                                    else if(sum>n)
                                                    break;
                                               }
                            }
                            printf("%d\n",count);
    }
    system("pause");
    return 0;
}
                            
    
