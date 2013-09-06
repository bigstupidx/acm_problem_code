
#include<stdio.h>
#include<string.h>
int dir[4][2]={-1,0,1,0,0,-1,0,1};
int map[34][34],mat[20][20];
int n,m,flag[20],y[20];

int path(int s)
{
    int i;
    for(i=1;i<=n;i++)
        if(mat[s][i]&&!flag[i])
        {
            flag[i]=1;
            if(y[i]==0||path(y[i]))
            {
                y[i]=s;
                return 1;
            }
        }
    return 0;  
}
int MaxMatch()
{
    int ans=0,i;
    memset(y,0,sizeof(y));
    for(i=1;i<=n;i++)
    {
        memset(flag,0,sizeof(flag));
        if(path(i))ans++;
    }
    return ans;
}
int main()
{
    int k;
    while(scanf("%d%d%d",&m,&n,&k)!=EOF)
    {
        int i,j;
        memset(map,0,sizeof(map));
        memset(mat,0,sizeof(mat));
        for(i=0;i<k;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            map[y][x]=1;
        }
        if((m*n-k)%2==1)
        {
            printf("NO\n");
            continue;
        } 
        for(i=1;i<=m;i++)
            for(j=1;j<=n;j++)
            {
                if(!map[i][j])
                {
                    int ii,jj,kk;
                    for(kk=0;kk<4;kk++)
                    {
                        ii=i+dir[kk][0];
                        jj=j+dir[kk][1];
                        if(ii<1||ii>m||jj<1||jj>n||map[ii][jj])continue;
                        
                        if(i%2==j%2) 
                            mat[((i-1)/2)*n+j][((ii-1)/2)*n+jj]=1;
                        else
                            mat[((ii-1)/2)*n+jj][((i-1)/2)*n+j]=1;
                    }
                }
            }
        int temp=(n*m-k)/2;
        n=((m+1)/2)*n;
        if(MaxMatch()==temp)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
