#include<stdio.h>
int floor[60][60];
int count[60];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int i,j,r,c;
        int ans=0;
        scanf("%d%d",&r,&c);
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                scanf("%d",&floor[i][j]);
                if(floor[i][j]!=-1)count[i]++;
            }
        for(i=0;i<r;i++)
        {
            int min=10000,k;
            ans+=i*20*count[i];
            for(j=0,k=0;j<count[i];j++,min=1000)
            {
                int y,x,a,b;
                for(y=0;y<c;y++)
                    if(floor[i][y]!=-1&&min>floor[i][y]){
                        x=y;min=floor[i][y];
                    }
                if(k>x){
                    a=k-x;
                    b=(x+c-k)%c;
                }
                else{
                    a=x-k;
                    b=(k+c-x)%c;
                }
                floor[i][x]=-1;
                ans+=5*(a>b?b:a);
                k=x;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
