#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 700
struct edge{
    int to;
    int d;
    edge *next;
}edg[1000000],*vert[MAXN];
char str[1010];
int flag[MAXN],que[MAXN],cnt[MAXN],m;
double dis[MAXN];
const int inf= 1000000000;
inline void Add_Edge(int x,int y,int va,int &top)
{
   // printf("%d -> %d %d\n",x,y,va);
    edge *p=&edg[++top];
    p->to=y;
    p->d=va;
    p->next=vert[x];    vert[x]=p;
}
bool Spfa(double ans)
{
    int ff,rr;
    for(int i=0;i<m;i++){dis[i]=inf;flag[i]=0;cnt[i]=0;}
    for(int i=0;i<m;i++)
    {
        if(cnt[i]!=0)continue;
        dis[i]=0;
        ff=0,rr=1;
        que[0]=i;flag[i]=1;
        while(ff!=rr)
        {
            int s=que[ff];
            ff=(ff+1)%MAXN;
            flag[s]=0;
            if(s==i&&cnt[i]>1)return true;
            for(edge *p=vert[s];p;p=p->next)
            {
                if(dis[p->to]>dis[s]+ans-p->d)
                {
                    dis[p->to]=dis[s]+ans-p->d;
                    if(!flag[p->to])
                    {
                        flag[p->to]=1;
                        cnt[p->to]++;
                        if(cnt[p->to]>m)return true;
                        que[rr] = p->to;
                        rr=(rr + 1) % MAXN;
                    }
                }
            }
        }
    }
    return false;
}
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        m=0;
        int top=-1,maxi=-1,mini=inf;
        memset(flag,-1,sizeof(flag));
        memset(vert, 0,sizeof(vert));
        for(int i=0;i<n;i++)
        {
            scanf("%s",str);
            int len=strlen(str);
            int u=(str[0]-'a')*26+str[1]-'a';
            int v=(str[len-2]-'a')*26+str[len-1]-'a';
            if(flag[u]==-1)flag[u]=m++;
            if(flag[v]==-1)flag[v]=m++;
            Add_Edge(flag[u],flag[v],len,top);
            //Add_Edge(flag[v],flag[u],len,top);
            if(len>maxi)maxi=len;
            if(len<mini)mini=len;
        }
        double l=0,r=maxi,mid;
      //  printf("%d\n",sum);
        while(r-l>1e-4)
        {
            mid=(l+r)/2;
            //printf("try l,r,mid %.2lf %.2lf %.2lf\n",l,r,mid);
            if(Spfa(mid))
                l=mid;
            else r=mid;
            //system("pause");
        }
        if(l==0)puts("No solution.");
        else printf("%.2lf\n",l);
    }
    return 0;
}

