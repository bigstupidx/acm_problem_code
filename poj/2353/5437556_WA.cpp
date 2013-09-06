#include<stdio.h>
__int64 fee[102][502];
__int64 sum[102][502];
struct node{
    int i,j;
}path[102][502];

void output(int r,int c)
{
    if(r==-1)return ;
    printf("%d\n",c+1);
    output(path[r][c].i,path[r][c].j);
}
int m,n;
int main()
{
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        for(int i=m-1;i>=0;i--)
            for(int j=0;j<n;j++)
                scanf("%d",&fee[i][j]);
        for(int i=0;i<n;i++)
        {
            path[0][i].i=-1;
            sum[0][i]=fee[0][i];
        }
        for(int i=1;i<m;i++)
        {
            sum[i][0]=fee[1][0]+fee[0][0];
            for(int j=1;j<n;j++)
            {
                if(fee[i-1][j]>sum[i][j-1])
                {
                    path[i][j].i=i,path[i][j].j=j-1;
                    sum[i][j]=sum[i][j-1]+fee[i][j];
                 }
                 else
                 {
                    path[i][j].i=i-1;path[i][j].j=j;
                    sum[i][j]=fee[i][j]+fee[i-1][j];
                }
            }
            if(sum[i][n-1]>fee[i][n-1]+fee[i-1][n-1])
                sum[i][n-1]=fee[i][n-1]+fee[i-1][n-1];
            for(int j=n-2;j>=0;j--)
            {
                if(sum[i][j]>fee[i][j]+sum[i][j+1])
                {
                    path[i][j].i=i,path[i][j].j=j+1;
                    sum[i][j]=fee[i][j]+sum[i][j+1];
                }
            }   
        }
        int k=0;
        for(int i=1;i<n;i++)
            if(sum[m-1][i]>sum[m-1][k])k=i;
        output(m-1,k-1);
    }
    return 0;
}
