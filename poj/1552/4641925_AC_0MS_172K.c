#include<stdio.h>

int main()
{
    int in[20];
    int i,j,t;
    memset(in,0,sizeof(in));
    while(1){
             scanf("%d",&in[0]);
             if(in[0]==-1)
                  break;
             else{t=0;
                  for(i=1;;i++){
                          scanf("%d",&in[i]);
                          if(in[i]==0)break;
                  }
                  for(i=0;in[i];i++)
                      for(j=i+1;in[j];j++)
                         if(in[j]==in[i]*2){t++;break;}
                  for(i=0;in[i];i++)
                      for(j=i+1;in[j];j++)
                          if(in[i]==in[j]*2){t++;break;}
                  printf("%d\n",t);
             }
    }
}
