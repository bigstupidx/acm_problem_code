#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct node{
    int x,y;
}l[112],r[112];
int rtop,ltop;
char map[112][112];
int w[112][112],Lx[112],Ly[112];
int xf[112],yf[112],oppoy[112];

int path(int u)
{
    int i,k;
    xf[u]=1;
    for(i=0;i<rtop;i++)
    {
        if(!yf[i] && (Lx[u]+Ly[i]==w[u][i]))
        {
            yf[i]=1;
            k=oppoy[i];
            oppoy[i]=u;
            if(k==-1||path(k))
                return 1;
            oppoy[i]=k;
        }
    }
    return 0;
}
int KM_Match()
{
    int i,j,k,sum=0;
    memset(oppoy,-1,sizeof(oppoy));
    for(i=0;i<ltop;i++)
    {
        while(1)
        {
            memset(xf,0,sizeof(int)*rtop);
            memset(yf,0,sizeof(int)*rtop);
            if( path(i) )break;
            
            int d=10000000;
            for(j = 0;j<ltop;j++)
            {
                if(xf[j])
                {
                    for(k=0;k<rtop;k++)
                    {
                        if(!yf[k]&&(Lx[j]+Ly[k]-w[j][k]<d))
                            d=Lx[j]+Ly[j]-w[j][k];
                    }
                }
            }
            for(j=0;j<ltop;j++)
            {
                if(xf[j])Lx[j]-=d;
                if(yf[j])Ly[j]+=d;
            }
        }
    }
    for(i=0;i<rtop;i++)
        sum += w[oppoy[i]][i];
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
            int max=-100000000;
            for(j=0;j<rtop;j++)
            {
                w[i][j]=-(abs(l[i].x-r[j].x)+abs(l[i].y-r[j].y));
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

