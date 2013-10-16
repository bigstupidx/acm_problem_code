#include<stdio.h>
#define MAX 102
int matrix[MAX][MAX];
int sum[MAX][MAX];
int main()
{
    int r,r1,c,c1,n,max,temp;
    scanf("%d",&n);
    
    for(r=0;r<=n;r++)sum[r][0]=0;
    
    for(r=1;r<=n;r++)for(c=1;c<=n;c++){
              scanf("%d",&matrix[r][c]);
              sum[r][c]=sum[r][c-1]+matrix[r][c];
    }
    max=sum[1][1];     
    for(c1=1;c1<=n;c1++)
                        for(c=c1;c<=n;c++){
                                           int now,k;
                                           now=0;
                                           for(k=1;k<=n;k++){
                                                             now+=sum[k][c]-sum[k][c1-1];
                                                             if(now>max)max=now;
                                                             else if(now<0)
                                                             now=0;
                                           }
                        }
    printf("%d\n",max);
    return 0;
}
