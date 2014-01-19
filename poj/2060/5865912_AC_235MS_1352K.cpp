#include<cstdio>
#include<cstring>
struct node{
    int t;
    int x1,x2,y1,y2;
}e[502];
int n,map[550][550],y[550],flag[550];
int ABS(int x)
{
    if(x<0)return -x;
    return x;
}
bool Path(int s)
{
    for(int i=0;i<n;i++)
    {
        if(!flag[i]&&map[s][i])
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
    //printf("MATCH %d\n",ans);
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(map,0,sizeof(map));
        for(int i=0;i<n;i++)
        {
            int a1,a2,a,b,c,d;
            scanf("%d:%d%d%d%d%d",&a1,&a2,&a,&b,&c,&d);
            e[i].t=a1*60+a2;
            e[i].x1=a;  e[i].x2=c;  e[i].y1=b;  e[i].y2=d;
        }
        for(int i=0;i<n;i++)
        {
            int tt;
            tt=e[i].t+ABS(e[i].x1-e[i].x2)+ABS(e[i].y1-e[i].y2);
            for(int j=i+1;j<n;j++)
                if(tt+ABS(e[j].x1-e[i].x2)+ABS(e[j].y1-e[i].y2)<e[j].t)
                    map[i][j]=1;
        }
        printf("%d\n",n-Max_Match());
    }
    //system("pause");
    return 0;
}
