#include<iostream>
#include<queue>
using namespace std;
struct Map
{
    int f,c;
}map[201][201];
int pre[201],v[201];
queue<int>q;
int n,m,a,b,c,s=1;
int main()
{
    while(cin>>n>>m)
    {
        int i,j;
        memset(map,0,sizeof(map));
        while(n--)
        {
            cin>>a>>b>>c;
            map[a][b].c=c;
        }
        while(1)
        {
            memset(pre,0,sizeof(pre));
            v[s]=0x7fffffff;
            pre[s]=s;
            while(!q.empty())
                q.pop();
            q.push(s);
            while(!q.empty()&&pre[m]==0)
            {
                i=q.front();
                q.pop();
                for(j=1;j<=m;j++)
                {
                    if(pre[j]==0)
                    {
                        if(map[i][j].f<map[i][j].c)
                        {
                            v[j]=min(v[i],map[i][j].c-map[i][j].f);
                            pre[j]=i;
                            q.push(j);
                        }
                        else if(map[j][i].f>0)
                        {
                            v[j]=min(v[i],map[j][i].f);
                            pre[j]=-1*i;
                            q.push(j);
                        }
                    }
                }
            }
            if(pre[m]==0)
                break;
            i=m;
            while(i!=s)
            {
                j=abs(pre[i]);
                if(pre[i]>0)
                {
                    map[j][i].f+=v[m];
                }
                else
                {
                    map[i][j].f-=v[m];
                }
                i=j;
            }
        }
        int ans=0;
        for(i=1;i<=m;i++)
        {
            if(i!=s)
                ans+=map[s][i].f;
        }
        cout<<ans<<endl;
    }
    system("pause");
    return 0;
}