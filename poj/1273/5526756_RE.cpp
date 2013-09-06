#include <iostream>
#include <queue>
using namespace std;
struct nod{
    int f,c;
}map[202][202];
int pre[202],v[202],n;
int Max_Flow(int s)
{
    while(1)
    {
        int i,j;
        memset(pre,0,sizeof(pre));
        queue<int>Q;
        Q.push(s);
        v[s]=0x7fffffff;
        while(!Q.empty()&&pre[n]==0)
        {
            i=Q.front();Q.pop();
            for(j=1;j<=n;j++)
            {
                if(!pre[j])
                {
                    if(map[i][j].f<map[i][j].c)
                    {
                        v[j]=min(v[i],map[i][j].c-map[i][j].f);
                        pre[j]=i;
                        Q.push(j);
                    }
                    else if(map[j][i].f>0)
                    {
                        v[j]=min(v[i],map[j][i].f);
                        pre[j]=-1*i;
                        Q.push(j);
                    }
                }
            }
        }
        if(pre[n]==0)break;
        for(i=n;i!=s;i=pre[i])
        {
            j=abs(pre[i]);
            if(pre[i]>0)
                map[j][i].f+=v[n];
            else
                map[i][j].f-=v[n];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans+=map[s][i].f;
    return ans;
}
int main()
{
    int m;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        memset(map,0,sizeof(map));
        while(m--)
        {
            int i,j,va;
            scanf("%d%d%d",&i,&j,&va);
            map[i][j].c=va;
        }
        printf("%d\n",Max_Flow(1));
    }
    return 0;
}
