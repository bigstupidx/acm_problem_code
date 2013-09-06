#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 50010
using namespace std;
struct node{
    int id;
    int ki,ai;
}nod[MAXN];
int n,par[MAXN],lc[MAXN],rc[MAXN],map[32][MAXN],tem[MAXN];
bool cmp1(node a,node b){return a.ki<b.ki;}
void make_rmq()
{
    int i=1,t=1;
    for(i=1;i<=n;i++){tem[i]=nod[i].ai;map[0][i]=i;}
//    for(i=1;i<=n;i++)
//        printf("%d ",tem[i]);
//    puts("");
    i=1;
    while(t*2<=n)
    {
        for(int j=t*2;j<=n;j++)
        {
            if(tem[map[i-1][j]]<tem[map[i-1][j-t]])
                map[i][j]=map[i-1][j];
            else
                map[i][j]=map[i-1][j-t];
//            printf("%d ",map[i][j]);
        }
//        puts("");
        t*=2;i++;
    }
}
int rmq_check(int l,int r)
{
    int ll=r-l+1,i=0,t=1;
    while(t*2<=ll){t*=2;i++;}
    return tem[map[i][r]]<tem[map[i][l+t-1]]?map[i][r]:map[i][l+t-1];
}
bool build_tree(int l,int r,int root,int now)
{
    if(l>r)return true;
    if(l==r)
    {
        par[nod[l].id]=root;
        if(now==0)lc[root]=nod[l].id;
        else if(now==1)rc[root]=nod[l].id;
        return true;
    }
    int mid=rmq_check(l,r);
    int xid=nod[mid].id;
    
    if(now==0)lc[root]=xid;
    else if(now==1)rc[root]=xid;
    
    if(build_tree(l,mid-1,xid,0))
        par[xid]=root;
    else return false;
    
    if(build_tree(mid+1,r,xid,1))
        return true;
    return false;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            nod[i].id=i;
            scanf("%d%d",&nod[i].ki,&nod[i].ai);
        }
        sort(nod+1,nod+1+n,cmp1);
        //printf("%d\n",nod[1].ki);
        make_rmq();
        memset(lc,0,sizeof(lc));
        memset(rc,0,sizeof(rc));
        memset(par,0,sizeof(par));
        if(build_tree(1,n,0,-1))
        {
            puts("YES");
            for(int i=1;i<=n;i++)
                printf("%d %d %d\n",par[i],lc[i],rc[i]);
        }
        else puts("NO");
    }
    return 0;
}
