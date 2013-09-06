#include<cmath>
#include<iostream>
#define MAX 102
using namespace std;
struct node{
    int x,y;
}rc[MAX],lc[MAX];
char map[MAX][MAX];
int rtop,ltop;
int w[MAX][MAX],Lx[MAX],Ly[MAX],oppoy[MAX];
bool x_visit[MAX],y_visit[MAX];
int path(int u)
{
    x_visit[u]=1;
    for(int i=0;i<rtop;i++)
    {
        if(!y_visit[i]&& Lx[u]+Ly[i]==w[u][i])
        {
            y_visit[i]=1;
            if(oppoy[i]==-1||path(oppoy[i]))
            {
                oppoy[i]=u;
                return 1;
            }
        }
    }
    return 0;
}
int KM_Match()
{
    memset(oppoy,-1,sizeof(oppoy));
    for(int i=0;i<ltop;i++)
    {
        while(1)
        {
            memset(x_visit,0,sizeof(x_visit));
            memset(y_visit,0,sizeof(y_visit));
            
            if(path(i))break;
            
            int d=INT_MAX;
            for(int j=0;j<ltop;j++)
            {
                if(x_visit[j])
                {
                    for(int k=0;k<rtop;k++)
                        if(!y_visit[k] && (Lx[j]+Ly[k]-w[j][k]<d))
                            d=Lx[j]+Ly[k]-w[j][k];
                }
            }
            for(int j=0;j<ltop;j++)
            {
                if(x_visit[j])Lx[j]-=d;
                if(y_visit[j])Ly[j]+=d;
            }
        }
    }
    int sum=0;
    for(int i=0;i<ltop;i++)
        sum+=w[oppoy[i]][i];
    return -sum;
}
int main()
{
    int r,c;
    while(scanf("%d%d",&r,&c),r||c)
    {
        ltop=rtop=0;
        for(int i=0;i<r;i++)
            scanf("%s",map[i]);
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++){
                if(map[i][j]=='m')
                {
                    lc[ltop].x=i;
                    lc[ltop].y=j;
                    ltop++;
                }
                else if(map[i][j]=='H')
                {
                    rc[rtop].x=i;
                    rc[rtop].y=j;
                    rtop++;
                }
            }
        for(int i=0;i<ltop;i++)
        {
            int max=-100000000;   
            for(int j=0;j<rtop;j++)
            {
                w[i][j]=-(abs(lc[i].x-rc[j].x)+abs(lc[i].y-rc[j].y));
                if(w[i][j]>max)
                    max=w[i][j];
            }
            Lx[i]=max;
            Ly[i]=0;
        }
        printf("%d\n",KM_Match());
    }
    return 0;
}
