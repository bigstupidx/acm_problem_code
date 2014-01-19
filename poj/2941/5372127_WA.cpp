#include<stdio.h>
int n;
int aa[1002][1002];
int main()
{
    while(scanf("%d",&n),n){
        int i,j;
        int sum;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                scanf("%d",aa[i]+j);
        if(n==1)
        {
            printf("homogeneous\n");
            continue;
        }
        sum=aa[1][1]+aa[n][n];
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                int last=sum-aa[i][j];
                for(int r=i+1;r<=n;r++)
                    for(int c=1;c<=n&&c!=j;c++)
                    if(aa[r][c]!=last)goto end;
            }
        printf("homogeneous\n");
        continue;
        end:printf("not homogeneous\n");
    }
    return 0;
}
