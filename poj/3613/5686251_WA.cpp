#include<cstdio>
#include<cstring>
#include<map>
#define N 120
#define inf 1000000000
using namespace std;

int tem[N][N],c[N][N],a[N][N],id;
void init_tem(int x[][N])
{
    int i,j;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            x[i][j]=inf;
}
void process(int n)
{
    int i,j,k;
    if(n==1)
    {
        for(i=0;i<id;i++)
            for(j=0;j<id;j++)
                c[i][j]=a[i][j];
       return ;
    }
    process(n/2);
    init_tem(tem);
    for(i=0;i<id;i++)
        for(j=0;j<id;j++){
            int mini=c[i][0]+c[0][j];
            for(k=0;k<id;k++)
                mini=min(mini,c[i][k]+c[k][j]);
            tem[i][j]=mini;
        }
    if(n%2)
    {
        for(i=0;i<id;i++)
            for(j=0;j<id;j++)
            {
                int mini=tem[i][0]+a[0][j];
                for(k=0;k<id;k++)
                    mini=min(mini,tem[i][k]+a[k][j]);
                tem[i][j]=mini;
            }
    }
    else{
        for(i=0;i<id;i++)
            for(j=0;j<id;j++)
                c[i][j]=tem[i][j];
    }
}
int main()
{
    int k,m,s,t;
    while(scanf("%d%d%d%d",&k,&m,&s,&t)!=EOF)
    {
        id=2;
        map<int,int>mp;
        map<int,int>::iterator p;
        mp[s]=0;mp[t]=1;
        init_tem(a);
        while(m--)
        {
            int l,x,y,u,v;
            scanf("%d%d%d",&l,&x,&y);

            p=mp.find(x);
            if(p==mp.end())
            {
                mp[x]=id;
                u=id++;
            }
            else u=p->second;

            p=mp.find(y);
            if(p==mp.end())
            {
                mp[y]=id;
                v=id++;
            }
            else v=p->second;

            a[u][v]=a[v][u]=l;
        }
        process(k);
        printf("%d\n",c[0][1]);
    }
    return 0;
}
