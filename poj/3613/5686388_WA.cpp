#include<cstdio>
#include<cstring>
#include<map>
#define N 120
#define inf 1000000000
using namespace std;

int tem[N][N],c[N][N],a[N][N],id;

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
    for(i=0;i<id;i++)
        for(j=0;j<id;j++)
        {
            tem[i][j]=inf;
            for(k=1;k<id;k++)
                tem[i][j]=min(tem[i][j],c[i][k]+c[k][j]);
        }
    if(n%2)
    {
        for(i=0;i<id;i++)
            for(j=0;j<id;j++){
                c[i][j]=inf;
                for(k=1;k<id;k++)
                    c[i][j]=min(c[i][j],tem[i][k]+a[k][j]);
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
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                a[i][j]=inf;
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
            if(a[u][v]>l)
                a[u][v]=a[v][u]=l;
        }
        process(k);
        printf("%d\n",c[0][1]);
    }
    return 0;
}
