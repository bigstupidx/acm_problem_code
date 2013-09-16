#include<cstdio>
#include<map>
#include<cstring>
#include<string>
#include<iostream>
#include<queue>
#define inf 1000000000
using namespace std;
struct edge{
    int i;
    int s,e;
    int d;
    bool operator<(const edge a)const
    {
        return a.d<d;
    }
}edg[500];
int m,n,aa[22],par[22],bb[22];
int f(int x)
{
    int t=par[x];
    if(t==-1)return x;
    return par[x]=f(t);
}
int Kruskra(int kk)
{
    edge tem;
    int ii=m,ans=0,count=1;
    priority_queue<edge>Q;
    while(ii--)Q.push(edg[ii]);
    while(!Q.empty())
    {
        int u,v,k;
        tem=Q.top();Q.pop();
        u=tem.s;v=tem.e;
        if(u==0)
        {
            int i;
            for(i=0;i<kk;i++)
                if(bb[i]==tem.i)break;
            if(!aa[i])continue;
        }
        if(v==0)
        {
            int i;
            for(i=0;i<kk;i++)
                if(bb[i]==tem.i)break;
            if(!aa[i])continue;
        }
        int uu=f(u),vv=f(v);
        if(uu==vv)continue;
        par[uu]=vv;
        ans+=tem.d;
        count++;
        if(count==n)break;
    }
    return ans;
}
int main()
{
    while(scanf("%d",&m)!=EOF)
    {
        char na1[12],na2[12];
        int id=1,tt=1,d,kk=0;

        map<string,int>mp;
        map<string,int>::iterator p;
        for(int i=0;i<m;i++)
        {
            int u,v;
            scanf("%s%s%d",na1,na2,&d);
            if(strcmp(na1,"Park")==0)
            {   u=0;tt*=2;  bb[kk++]=i;}
            else
            {
                p=mp.find(na1);
                if(p==mp.end())
                {
                    mp[na1]=id++;
                    u=id-1;
                }
                else u=p->second;
            }
            if(strcmp(na2,"Park")==0)
            {   v=0;tt*=2;  bb[kk++]=i;}
            else
            {
                p=mp.find(na2);
                if(p==mp.end())
                {
                    mp[na2]=id++;
                    v=id-1;
                }
                else v=p->second;
            }
            edg[i].i=i;
            edg[i].s=u;edg[i].e=v;edg[i].d=d;
        }
        n=mp.size()+1;
        int k,min=inf;
        scanf("%d",&k);
        for(int i=1;i<tt;i++)
        {
            int count=0,j=0,tem=i;
            memset(aa,0,sizeof(aa));
            while(tem)
            {
                aa[j++]=tem%2;
                if(aa[j-1]==1)count++;
                tem/=2;
            }
            if(count!=k)continue;
            memset(par,-1,sizeof(par));
            int temp=Kruskra(kk);
            if(temp<min)min=temp;
        }
        printf("Total miles driven: %d\n",min);
    }
    return 0;
}
