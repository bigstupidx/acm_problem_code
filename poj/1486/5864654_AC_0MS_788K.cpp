#include<cstdio>
#include<cstring>

struct paper{
    int x1,x2,y1,y2;
}pp[400];

int n,y[400],flag[400],map[400][400];
bool Path(int s)
{
    for(int i=0;i<n;i++)
    {
        if(flag[i]==0&&map[s][i])
        {
            flag[i]=1;
            if(y[i]==-1||Path(y[i]))
            {
                y[i]=s;
                return true;
            }
        }
    }
    return false;
}
int Max_Match()
{
    int ans=0;
    memset(y,-1,sizeof(y));
    for(int i=0;i<n;i++)
    {
        memset(flag,0,sizeof(flag));
        if(Path(i))ans++;
    }
    return ans;
}
int main()
{
    int ncase=0;
    while(scanf("%d",&n),n)
    {
        ncase++;
        memset(map,0,sizeof(map));
        for(int i=0;i<n;i++)
            scanf("%d%d%d%d",&pp[i].x1,&pp[i].x2,&pp[i].y1,&pp[i].y2);
        for(int i=0;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            for(int j=0;j<n;j++)
            {
                if(pp[j].x1<x && pp[j].x2>x && pp[j].y1<y &&pp[j].y2>y)
                    map[i][j]=1;
            }
        }
        Max_Match();
        printf("Heap %d\n",ncase);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            int s=y[i];
            map[s][i]=0;
            y[i]=-1;
            memset(flag,0,sizeof(flag));
            if(!Path(s))
            {
                y[i]=s;
                cnt++;
                printf("(%c,%d) ",'A'+i,s+1);
            }
            map[s][i]=1;
        }
        if(cnt==0)printf("none");
        printf("\n\n");
    }
    return 0;
}
