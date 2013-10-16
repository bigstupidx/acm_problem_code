#include<iostream>
using namespace std;
int par[10002],aa[10002],bb[10002];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,u,v,flag=1,top1=0,top2=0;
        cin>>n;
        for(int i=1;i<=n;i++)
            par[i]=i;
        for(int i=1;i<n;i++)
        {
            cin>>u>>v;
            par[v]=u;
        }
        cin>>u>>v;
        aa[top1++]=u;
        while(par[u]!=u){
            aa[top1++]=par[u];
            u=par[u];
        }
        bb[top2++]=v;
        while(par[v]!=v){
            bb[top2++]=par[v];
            v=par[v];
        }
        do{
            top1--;top2--;
        }while(aa[top1]==bb[top2]);
        cout<<aa[top1+1]<<endl;
    }
    return 0;
}
