#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
char str[50][50];
vector<int>front[2000],back[2000],node;
int n,top,id[2000],order[2000],visit[2000],wi[2000],va[2000];
int map[2000][2000],ans[2000];
void init(int r,int c)
{
    node.clear();
    for(int i=0;i<r*c;i++)
        front[i].clear(),back[i].clear();
    memset(wi,0,sizeof(wi));
    memset(va,0,sizeof(va));
}
void DFS(int s)
{
    visit[s]=1;
    for(int i=0;i<front[s].size();i++)
        if(!visit[front[s][i]])DFS(front[s][i]);
    order[top++]=s;
}
void DFS_RG(int s)
{
    visit[s]=1;
    id[s]=top;
    for(int i=0;i<back[s].size();i++)
        if(!visit[back[s][i]])DFS_RG(back[s][i]);
}
int dfs(int s)
{
    if(visit[s])return ans[s];
    visit[s]=1;
    ans[s]=va[s];
    for(int i=0;i<front[s].size();i++)
    {
        dfs(front[s][i]);
        if(ans[front[s][i]]+va[s]>ans[s])
            ans[s]=ans[front[s][i]]+va[s];        
    }
}
int main()
{
    int nca;
    scanf("%d",&nca);
    while(nca--)
    {
        int r,c;
        scanf("%d%d",&r,&c);
        for(int i=0;i<r;i++)
            scanf("%s",str[i]);
        init(r,c);
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(str[i][j]>='0'&&str[i][j]<='9'||str[i][j]=='*')
                {
                    if(str[i][j]!='*')
                        wi[i*c+j]=str[i][j]-'0';
                    else{
                        wi[i*c+j]=0;
                        node.push_back(i*c+j);
                    }
                    if(i+1<r&&str[i+1][j]!='#'){
                        front[i*c+j].push_back((i+1)*c+j);
                        back[(i+1)*c+j].push_back(i*c+j);
                    }
                    if(j+1<c&&str[i][j+1]!='#'){
                        front[i*c+j].push_back(i*c+j+1);
                        back[i*c+j+1].push_back(i*c+j);
                    }
                }
            }
        }
        for(int i=0;i<node.size();i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(str[x][y]=='#')continue;
            front[node[i]].push_back(x*c+y);
            back[x*c+y].push_back(node[i]);
        }
        top=0;  n=r*c;
        memset(visit,0,sizeof(visit));
        for(int i=0;i<n;i++)
            if(!visit[i])DFS(i);
        
        top=0;
        memset(visit,0,sizeof(visit));
        for(int i=n-1;i>=0;i--)
        {
            if(!visit[order[i]])
            {
                DFS_RG(order[i]);top++;
            }
        }
        /*
        for(int i=0;i<n;i++)
            printf("%d ",id[i]);
        puts("");
        for(int i=0;i<n;i++)
            printf("%d ",wi[i]);
        puts("");
        */
        for(int i=0;i<n;i++)
            va[id[i]]+=wi[i];
        //for(int i=0;i<top;i++)
        //    printf("%d ",va[i]);
        memset(map,0,sizeof(map));
        for(int i=0;i<top;i++)front[i].clear();
        for(int i=0;i<n;i++)
            for(int j=0;j<back[i].size();j++)
                if(id[i]!=id[back[i][j]]&&!map[id[back[i][j]]][id[i]]){
                    map[id[back[i][j]]][id[i]]=1;
                    front[id[back[i][j]]].push_back(id[i]);
                }
        memset(visit,0,sizeof(visit));
        dfs(0);
        printf("%d\n",ans[0]);
    }
    return 0;
}
