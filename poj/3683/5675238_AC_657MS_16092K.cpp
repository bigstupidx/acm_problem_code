#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#define zeros(x) (2*x)
#define ones(x) (2*x+1)
using namespace std;
vector<int>front[2020],back[2020];
int top,n,order[2020],id[2020],start[2020],end[2020],deg[2020],color[2020];
bool v[2020];
bool intersect(int i,int j)
{
    if(start[i]>=end[j]||end[i]<=start[j])return false;
    return true;
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
void Display()
{
    n=n<<1;
    for(int i=0;i<n;i++){front[i].clear();deg[i]=0;}
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<back[i].size();j++)
            if(id[i]!=id[back[i][j]]){
                front[id[i]].push_back(id[back[i][j]]);
    //            printf("%d->%d\n",id[i],id[back[i][j]]);
                deg[id[back[i][j]]]++;
            }
    }
    stack<int>S;
    vector<int>tt;
    for(int i=0;i<top;i++)
        if(deg[i]==0)S.push(i);
    while(!S.empty())
    {
        int i=S.top();S.pop();
        tt.push_back(i);
        int len=front[i].size();
        for(int j=0;j<len;j++)
        {
            deg[front[i][j]]--;
            if(deg[front[i][j]]==0)S.push(front[i][j]);
        }
    }

    for(int i=0;i<n;i++)color[i]=1;
    for(int i=0;i<tt.size();i++)
        if(color[tt[i]])
        {
            for(int j=0;j<n;j++)
                if(id[j]==tt[i])color[id[j^1]]=0;
        }

    for(int i=0;i<n;i++)
        if(color[id[i]])
        {
            printf("%.2d:%.2d ",start[i]/60,start[i]%60);
            printf("%.2d:%.2d\n",end[i]/60,end[i]%60);
        }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<2*n;i++){front[i].clear();back[i].clear();}
        for(int i=0;i<n;i++)
        {
            int a1,a2,b1,b2,c;
            scanf("%d:%d %d:%d %d",&a1,&a2,&b1,&b2,&c);
            a1=a1*60+a2,b1=b1*60+b2;
            start[zeros(i)]=a1; end[zeros(i)]=a1+c;
            start[ones(i)]=b1-c;    end[ones(i)]=b1;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int ii=i*2,jj=j*2;
                if(intersect(ii,jj))
                {
                    front[ii].push_back(jj+1);    back[jj+1].push_back(ii);
                    front[jj].push_back(ii+1);    back[ii+1].push_back(jj);
                }
                if(intersect(ii,jj+1))
                {
                    front[ii].push_back(jj);    back[jj].push_back(ii);
                    front[jj+1].push_back(ii+1);    back[ii+1].push_back(jj+1);
                }
                if(intersect(ii+1,jj))
                {
                    front[ii+1].push_back(jj+1);    back[jj+1].push_back(ii+1);
                    front[jj].push_back(ii);    back[ii].push_back(jj);
                }
                if(intersect(ii+1,jj+1))
                {
                    front[ii+1].push_back(jj);  back[jj].push_back(ii+1);
                    front[jj+1].push_back(ii);  back[ii].push_back(jj+1);
                }
            }
        }
        top=0;
        memset(v,0,sizeof(v));
        for(int i=0;i<2*n;i++)
            if(!v[i])DFS(i);

        top=0;
        memset(v,0,sizeof(v));
        for(int i=2*n-1;i>=0;i--)
            if(!v[order[i]]){DFS_RG(order[i]);top++;}

        bool flag=false;
        for(int i=0;i<n;i++)
            if(id[zeros(i)]==id[ones(i)]){flag=true;break;}

        if(flag)puts("NO");
        else{
            puts("YES");
            Display();
        }
    }
    return 0;
}
