#include<iostream>
using namespace std;
struct node{
    int t;
    int x1,x2,y1,y2;
}nod[502];
int map[502][502];
int flag[502],y[502];
int n;
int path(int u)
{
    for(int i=1;i<=n;i++)
    {
        if(!flag[i]&&map[u][i])
        {
            flag[i]=1;
            if(y[i]==0||path(y[i]))
            {
                y[i]=u;
                return 1;
            }
        }
    }
    return 0;
}
int MaxMatch()
{
    int ans=0;
    memset(y,0,sizeof(y));
    for(int i=1;i<=n;i++)
    {
        memset(flag,0,sizeof(flag));
        if(path(i))ans++;
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(map,0,sizeof(map));
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            char ti[6];
            scanf("%s%d%d%d%d",ti,&nod[i].x1,&nod[i].y1,&nod[i].x2,&nod[i].y2);
            nod[i].t=((ti[0]-'0')*10+ti[1]-'0')*60+(ti[3]-'0')*10+ti[4]-'0';
        }
        for(int i=1;i<=n;i++)
        {
            int j,tt;
            tt=abs(nod[i].x1-nod[i].x2)+abs(nod[i].y1-nod[i].y2);
            tt+=nod[i].t;
            for(j=i+1;j<=n;j++)
            {
                tt+=abs(nod[j].x1-nod[i].x2)+abs(nod[j].y1-nod[i].y2);
                if(nod[j].t>tt)map[i][j]=1;
            }
        }
        printf("%d\n",n-MaxMatch());
    }
    return 0;
}
