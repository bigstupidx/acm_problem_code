#include<stdio.h>
__int64 fee[102][502];
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
            path[0][i].i=-1;
        for(int i=1;i<m;i++)
        {
            int k=0;
            for(int x=1;x<n;x++)
                if(fee[i-1][x]<fee[i-1][k])
                    k=x;
            fee[i][k]+=fee[i-1][k];
            path[i][k].i=i-1;path[i][k].j=k;
            for(int j=k+1;j<n;j++)
            {
                if(fee[i-1][j]>fee[i][j-1])
                {
                    path[i][j].i=i,path[i][j].j=j-1;
                    fee[i][j]+=fee[i][j-1];
                }
                else
                {
                    path[i][j].i=i-1;path[i][j].j=j;
                    fee[i][j]+=fee[i-1][j];
                }
            }
            for(int j=k-1;j>=0;j--)
            {
                if(fee[i-1][j]>fee[i][j+1])
                {
                    path[i][j].i=i,path[i][j].j=j+1;
                    fee[i][j]+=fee[i][j+1];
                }
                else
                {
                    path[i][j].i=i-1;path[i][j].j=j;
                    fee[i][j]+=fee[i-1][j];
                }
            }
        }
        int k=0;
        for(int i=1;i<n;i++)
            if(fee[m-1][i]>fee[m-1][k])k=i;
        output(m-1,k-1);
    }
    return 0;
}
