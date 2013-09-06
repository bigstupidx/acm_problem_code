#include<cstdio>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;
int aa[120][120],n,cc[120][120],tem[120][120];
const int inf=1000000000;
void Multi(int k)
{
    if(k==1){
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cc[i][j]=aa[i][j];
        return ;
    }
    Multi(k/2);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            tem[i][j]=inf;
            for(int k=0;k<n;k++)
                //if(k!=i&&k!=j)
                tem[i][j]=min(tem[i][j],cc[i][k]+cc[k][j]);
        }
    if(k%2){
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                cc[i][j]=inf;
                for(int k=0;k<n;k++)
                    //if(k!=i&&k!=j)
                    cc[i][j]=min(cc[i][j],tem[i][k]+aa[k][j]);
            }
    }
    else{
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cc[i][j]=tem[i][j];
    }
}
int main()
{
    int k,m,s,t;
    while(scanf("%d%d%d%d",&k,&m,&s,&t)!=EOF)
    {
        int id=2;
        map<int,int>mp;
        map<int,int>::iterator p;
        mp[s]=0;    mp[t]=1;
        for(int i=0;i<120;i++)
            for(int j=0;j<120;j++)
                aa[i][j]=inf;
        //for(int i=0;i<120;i++)aa[i][i]=0;
        while(m--)
        {
            int x,y,u,v,va;
            scanf("%d%d%d",&va,&u,&v);
            p=mp.find(u);
            if(p==mp.end())
            {
                mp[u]=id;
                x=id++;
            }
            else x=p->second;
            p=mp.find(v);
            if(p==mp.end())
            {
                mp[v]=id;
                y=id++;
            }
            else y=p->second;
            if(aa[x][y]>va)
                aa[x][y]=aa[y][x]=va;
        }
        n=id;   Multi(k);
        printf("%d\n",cc[0][1]);
    }
    return 0;
}
