
#include<cmath>
#include<iostream>
using namespace std;
struct node{
    int x,y;
}l[112],r[112];
int rtop,ltop;
char map[112][112];
int w[112][112],Left[112],Right[112],pre[112];
bool l_visit[112],r_visit[112];

int path(int u)
{
    int i,k;
    l_visit[u]=1;
    for(i=0;i<rtop;i++)
    {
        if(!r_visit[i] && (Left[u]+Right[i]==w[u][i]))
        {
            r_visit[i]=1;
            k=pre[i];
            pre[i]=u;
            if(k==-1||path(k))
                return 1;
            pre[i]=k;
        }
    }
    return 0;
}
int KM_Match()
{
    int i,j,k,sum=0,d;
    memset(pre,-1,sizeof(pre));
    for(i=0;i<ltop;i++)
    {
        while(1)
        {
            memset(l_visit,0,sizeof(int)*ltop);
            memset(r_visit,0,sizeof(int)*rtop);
            if( path(i) )break;
            
            d=INT_MAX;
            for(j = 0;j<ltop;j++)
            {
                if(l_visit[j])
                {
                    for(k=0;k<rtop;k++)
                    {
                        if(!r_visit[k]&&(Left[j]+Right[k]-w[j][k]<d))
                            d=Left[j]+Right[k]-w[j][k];
                    }
                }
            }
            for(j=0;j<ltop;j++)
            {
                if(l_visit[j])Left[j]-=d;
                if(r_visit[j])Right[j]+=d;
            }
        }
    }
    for(i=0;i<rtop;i++)
        sum += w[pre[i]][i];
    return -sum;
}
int main()
{
    int rc,cc;
    while(scanf("%d%d",&rc,&cc),rc||cc)
    {
        int i,j;
        ltop = 0 ; rtop = 0 ;
        for(i=0;i<rc;i++)
            scanf("%s",map[i]);
        for(i= 0;i < rc; i++)
        {
            for(j=0;j<cc;j++)
            {
                if(map[i][j] == 'm')
                {
                    l[ltop].x=i;
                    l[ltop].y=j;
                    ltop++;
                }
                else if(map[i][j]== 'H')
                {
                    r[rtop].x=i;
                    r[rtop].y=j;
                    rtop++;
                }
            }
        }
        for(i=0;i<ltop;i++)
        {
            int max=-9999999;
            for(j=0;j<rtop;j++)
            {
                w[i][j]=-(abs(l[i].x-r[j].x)+abs(l[i].y-r[j].y));
                if(w[i][j]>max)
                    max=w[i][j];
            }
            Left[i]=max;
            Right[i]=0;
        }
        printf("%d\n",KM_Match());
    }
    return 0;
}

