#include<stdio.h>
#include<string.h>
int floor[60][60];
int count[60];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int i,j,r,c;
        __int64 ans=0;
        scanf("%d%d",&r,&c);
        memset(count,0,sizeof(count));
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                scanf("%d",&floor[i][j]);
                if(floor[i][j]!=-1)count[i]++;
            }
        for(i=0;i<r;i++)
        {
            int min=50000,k;
            ans+=i*20*count[i];
            for(j=0,k=0;j<count[i];j++,min=50000)
            {
                int y,ii,a,b;
                for(y=0;y<c;y++)
                    if(floor[i][y]!=-1&&min>floor[i][y]){
                        ii=y;min=floor[i][y];
                    }
                if(k>ii){
                    a=k-ii;
                    b=(ii+c-k)%c;
                }
                else{
                    a=ii-k;
                    b=(k+c-ii)%c;
                }
                floor[i][ii]=-1;
                ans+=5*(a>b?b:a);
                k=ii;
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
