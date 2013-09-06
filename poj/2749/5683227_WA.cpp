
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#include<cmath>
#include<cstdlib>
#define ones(x) (2*x+1)
#define zeros(x) (2*x)
using namespace std;

vector<int>front[1010],back[1010],tem[1010];

struct node{
    int x,y;
}nod[505];

int top,n,order[1010],color[1010],id[1010],s[2][2],d,dis[505][505][4];
bool v[1010];

int Distance(int i,int j)
{
    return abs(nod[i].x-s[j][0])+abs(nod[i].y-s[j][1]);
}

void DFS(int s)
{
    v[s]=1;
    for(int i=0;i<front[s].size();i++)
        if(!v[front[s][i]])DFS(front[s][i]);
    order[top++]=s;
}
void DFS_RG(int s)
{
    v[s]=1;
    id[s]=top;
    for(int i=0;i<back[s].size();i++)
        if(!v[back[s][i]])DFS_RG(back[s][i]);
}
void Make_Graph(int mid)
{
    int i,j;
    for(i=0;i<2*n;i++){front[i].clear();back[i].clear();}
    for(i=0;i<2*n;i++)
    {
        for(j=0;j<tem[i].size();j++)
        {
            front[i].push_back(tem[i][j]);
            back[tem[i][j]].push_back(i);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(dis[i][j][0]>mid)
            {
                front[zeros(i)].push_back(ones(j)); back[ones(j)].push_back(zeros(i));
                front[zeros(j)].push_back(ones(i)); back[ones(i)].push_back(zeros(j));
            }
            if(dis[i][j][1]>mid)
            {
                front[ones(i)].push_back(zeros(j)); back[zeros(j)].push_back(ones(i));
                front[ones(j)].push_back(zeros(i)); back[zeros(i)].push_back(ones(j));
            }
            if(dis[i][j][2]>mid)
            {
                front[zeros(i)].push_back(zeros(j));    back[zeros(j)].push_back(zeros(i));
                front[zeros(j)].push_back(zeros(i));    back[zeros(i)].push_back(zeros(j));
            }
            if(dis[i][j][3]>mid)
            {
                front[ones(j)].push_back(ones(i));  back[ones(i)].push_back(ones(j));
                front[ones(i)].push_back(ones(j));  back[ones(j)].push_back(ones(i));
            }
        }
    }
}
bool solve(int mid)
{
    Make_Graph(mid);
    memset(v,0,sizeof(v));top=0;
    for(int i=0;i<2*n;i++)
        if(!v[i])DFS(i);

    memset(v,0,sizeof(v));top=0;
    for(int i=2*n-1;i>=0;i--)
        if(!v[order[i]]){DFS_RG(order[i]);top++;}

    for(int i=0;i<n;i++)
        if(id[zeros(i)]==id[ones(i)])return false;
    return true;
}
int main()
{
    int m1,m2;
    while(scanf("%d%d%d",&n,&m1,&m2)!=EOF)
    {
        int i,j;

        for(i=0;i<2*n;i++)  tem[i].clear();

        scanf("%d%d%d%d",&s[0][0],&s[0][1],&s[1][0],&s[1][1]);
        for(i=0;i<n;i++)scanf("%d%d",&nod[i].x,&nod[i].y);
        while(m1--)
        {
            scanf("%d%d",&i,&j);
            i--;j--;
            tem[zeros(i)].push_back(ones(j));
            tem[zeros(j)].push_back(ones(i));
            tem[ones(i)].push_back(zeros(j));
            tem[ones(j)].push_back(zeros(i));
        }
        while(m2--)
        {
            scanf("%d%d",&i,&j);
            i--;j--;
            tem[zeros(i)].push_back(zeros(j));
            tem[zeros(j)].push_back(zeros(i));
            tem[ones(i)].push_back(ones(j));
            tem[ones(j)].push_back(ones(i));
        }
        int maxi=-1;
        d=abs(s[0][0]-s[1][0])+abs(s[0][1]-s[1][1]);

        memset(dis,0,sizeof(dis));
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                int a1,a2,b1,b2;
                a1=Distance(i,0);a2=Distance(i,1);b1=Distance(j,0);b2=Distance(j,1);
                dis[i][j][0]=dis[j][i][0]=a1+b1;//i->s1+j->s1
                dis[i][j][1]=dis[j][i][1]=a2+b2;//i->s2+j->s2
                dis[i][j][2]=dis[j][i][2]=a1+b2+d;//i->s1+j->s2+s1->s2
                dis[i][j][3]=dis[j][i][3]=a2+b1+d;//j->s1+i->s2+s1->s2
                if(a1+b1>maxi)maxi=a1+b1;
                if(a2+b2>maxi)maxi=b2+a2;
                if(a1+d+b2>maxi)maxi=a1+b2+d;
                if(a2+d+b1>maxi)maxi=a2+b1+d;
            }
        }
        //printf("%d\n",maxi);
        int l=0,r=maxi,mid;
        while(l<=r)
        {
            mid=(l+r)/2;
            //printf("try mid :%d\n",mid);
            if(solve(mid))
                r=mid-1;
            else
                l=mid+1;
        }
        printf("%d\n",l);
    }
    return 0;
}
