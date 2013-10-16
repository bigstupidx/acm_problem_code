
#include<iostream>
#include<algorithm>
using namespace std;

struct node{
    int x,y;
    bool operator<(const node a)const
    {
        if(a.x==x)return a.y>y;
        return a.x>x;
    }
}nodes[1000010];
int aa[1000010],bb[1000010];
__int64 ans;
void merge(int ,int);
void mergesort(int l,int h)
{
    int m;
    if(l<h){
        m=(l+h)/2;
        mergesort(l,m);
        mergesort(m+1,h);
        merge(l,h);
    }
}
void merge(int l,int h)
{
    int m=(l+h)/2,i,j,k=0;
    for(i=l,j=m+1;i<=m&&j<=h;)
    {
        if(aa[i]>aa[j])
        {
            ans+=m-i+1;
            bb[k++]=aa[j];
            j++;
        }
        else
        {
            bb[k++]=aa[i];
            i++;
        }
    }
    if(i<=m)
    {
        for(;i<=m;i++)bb[k++]=aa[i];
    
    }
    else
    {
        for(;j<=h;j++)bb[k++]=aa[j];
    }
    for(i=0;i<k;i++)
        aa[l+i]=bb[i];
    return ;
}
int main()
{
    int t;
    cin>>t;
    for(int j=1;j<=t;j++)
    {
        int n,m,k;
        ans=0;
        cin>>n>>m>>k;
        for(int i=0;i<k;i++)
            scanf("%d%d",&nodes[i].x,&nodes[i].y);
        sort(nodes,nodes+k);
        for(int i=0;i<k;i++)
            aa[i]=nodes[i].y;
        mergesort(0,k-1);
        printf("Test case %d: %I64d\n",j,ans);
    }
    return 0;
}
