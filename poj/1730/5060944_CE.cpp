#include<stdio.h>
#include<math.h>
int main()
{
    long long p;
    while(scanf("%lld",&p),p){
                            int i,j,ans=1;
                            long long temp;
                            if(p>0){
                                    for(i=2;i<=sqrt(p);i++){
                                              temp=i;
                                              for(j=1;j<34;j++)
                                              {    
                                                   if(temp>p)break;
                                                   else if(temp==p){
                                                        if(ans<j)ans=j;
                                                        break;
                                                   }
                                                   temp*=i;
                                              }
                                    }
                            }
                            else {
                                 for(i=2;i<=sqrt(-p);i++){
                                              temp=i;
                                              for(j=1;j<34;j+=2)
                                              {               
                                                                     if(temp>(-p))break;
                                                                     else if(temp==(-p)){
                                                                          if(ans<j)ans=j;
                                                                          break;
                                                                     }
                                                                     temp*=i*i;
                                              }
                                 }
                            }
                            printf("%d\n",ans);
    }
    return 0;
}
