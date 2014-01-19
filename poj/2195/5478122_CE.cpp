#include<stdio.h>
#include<string.h>
#include<math.h>
struct node{
    int x,y;
}l[102],r[102];
int rtop,ltop;
char map[102][102];
int w[102][102],Lx[102],Ly[102];
int xf[102],yf[102],oppoy[102];

int path(int u)
{
    xf[u]=1;
    for(int i=0;i<rtop;i++)
    {
        if(!yf[i] && (Lx[u]+Ly[i]==w[u][i]))
        {
            yf[i]=1;
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
    int sum=0;
    memset(oppoy,-1,sizeof(oppoy));
    for(int i=0;i<ltop;i++)
    {
        while(1)
        {
            int d=10000000;
            memset(xf,0,sizeof(xf));
            memset(yf,0,sizeof(yf));
            if( path(i) )break;
            for(int j = 0;j<ltop;j++)
                if(xf[j])
                {
                    for(int k=0;k<rtop;k++)
                        if(!yf[k]&&(Lx[j]+Ly[k]-w[j][k]<d))
                            d=Lx[j]+Ly[j]-w[j][k];
                }
            for(int j=0;j<ltop;j++)
            {
                if(xf[j])Lx[j]-=d;
                if(yf[j])Ly[j]+=d;
            }
        }
    }
    for(int i=0;i<rtop;i++)
        sum += w[oppoy[i]][i];
    return -sum;
}
int main()
{
    int rc,cc;
    while(scanf("%d%d",&rc,&cc),rc||cc)
    {
        ltop = 0 ; rtop = 0 ;
        for(int i=0;i<rc;i++)
            scanf("%s",map[i]);
        for(int i= 0;i < rc; i++)
            for(int j=0;j<cc;j++){
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
        for(int i=0;i<ltop;i++)
        {
            int max=-10000000;
            for(int j=0;j<rtop;j++)
            {
                int value=-(fabs(l[i].x-r[j].x)+fabs(l[i].y-r[j].y));
                w[i][j]=value;
                if(value>max){
                    max=value;
                }
            }
            Lx[i]=max;
            Ly[i]=0;
        }
        printf("%d\n",KM_Match());
    }
    return 0;
}
