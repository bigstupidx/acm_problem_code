#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;
int n,m,id,k;//nÎª¶¥µãÊý£¬mÎª±ßÊý ,idÎªµã±àºÅ£¨0Îªpark£© 
struct node{
    int u,v;
    int dis;
    bool operator<(const node a)const
    {
        return a.dis>dis;
    }
}nodes[500];
int mark[22],par[22];
int fi[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,
        65536,131072,262144,524288,1048576};
map<string,int>mp;
int id_find(string aa)
{
    map<string,int>::iterator p;
    p=mp.find(aa);
    if(aa=="Park")
        return 0;
    if(p==mp.end())
    {
        mp[aa]=id;
        return id++;
    }
    return p->second;
}
int f(int i)
{
    int x=par[i];
    if(x!=i)par[i]=f(x);
    return par[i];
}
int check()
{
    int flag=0,visit[22];
    memset(visit,0,sizeof(visit));
    for(int i=0;i<n;i++)
        if(mark[i]){
            visit[nodes[i].u]=1;
            visit[nodes[i].v]=1;
    }
    for(int i=0;i<n;i++)
    {
        if(mark[i])continue;
        if(visit[nodes[i].u]||visit[nodes[i].v])
        {
            visit[nodes[i].u]=1;
            visit[nodes[i].v]=1;
        }
    }
    for(int i=0;i<n;i++)
        if(!visit[i])flag=1;
    if(flag)return 1;
    return 0;
}

int kruskal(int top,int &ans)
{
    for(int i=0;i<n-top;i++)
    {
        for(int j=0;j<m;j++)
        {
            int u,v;
            if(mark[j])continue;
            mark[j]=1;
            u=f(nodes[j].u);
            v=f(nodes[j].v);
            if(u==v)continue;
            else{
                ans+=nodes[j].dis;
                par[v]=u;
            }
        }
    }
    return ans;
}
int main()
{
    char aa[12],bb[12];
    int dis,_from_0[2][22];
    id=1;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int u,v,tem; 
        scanf("%s%s%d",aa,bb,&dis);
        u=id_find(aa);
        v=id_find(bb);
        if(v<u)
        {
            tem=u;u=v;v=tem;
        }
        nodes[i].u=u;
        nodes[i].v=v;
        nodes[i].dis=dis;
    }
    n=mp.size()+1;
    sort(nodes,nodes+m);
    cin>>k;
    int min=10000000,temp,d=0;
    for(int i=0;i<m;i++)
        if(nodes[i].u==0)_from_0[0][d++]=i;
    k=k>d?d:k;
    for(int i=1;i<=fi[k];i++)
    {
        int temp=i,top=0;
        memset(mark,0,sizeof(mark));
        for(int j=0;j<n;j++)
            par[j]=j;
        while(temp)
        {
            _from_0[1][top++]=temp%2;
            temp/=2;
        }
        temp=0;
        for(int j=0;j<top;j++)
            if(_from_0[1][j])
            {
                mark[_from_0[0][j]]=1;
                temp+=nodes[_from_0[0][j]].dis;
                par[nodes[_from_0[0][j]].v]=0;
            }
        if(check())continue;
        kruskal(top,temp);
        if(temp<min)min=temp;
    }
    cout<<"Total miles driven: "<<min<<endl;
    system("pause");
    return 0;
}
