#include<stdio.h>
int n;
int aa[1002][1002];
int main()
{
    while(scanf("%d",&n),n){
        int i,j,a;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                scanf("%d",aa[i]+j);
        if(n==1)
        {
            printf("homogeneous\n");
            continue;
        }
        if(n==2){
            if(aa[1][1]+aa[2][2]!=aa[1][2]+aa[2][1])
            printf("not homogeneous\n");
            else
            printf("homogeneous\n");
            continue;
        }
        a=aa[1][1];
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(aa[i][j]!=a)goto end;
        printf("homogeneous\n");
        continue;
        end:printf("not homogeneous\n");
    }
    return 0;
}
