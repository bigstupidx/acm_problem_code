#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
using namespace std;

vector<int>front[140],back[140];

int n,top,id[140],order[140],deg[140],color[140];
bool v[140];
int zeros(int x){return 2*x;}
int ones(int x){return 2*x+1;}
void DFS(int s)
{
    int i;
    v[s]=1;
    for(i=0;i<front[s].size();i++)
        if(!v[front[s][i]])DFS(front[s][i]);
    order[top++]=s;
}
void DFS_RG(int s)
{
    int i;
    v[s]=1;
    id[s]=top;
    for(i=0;i<back[s].size();i++)
        if(!v[back[s][i]])DFS_RG(back[s][i]);
}
void Display()
{
    n=n*4;
    for(int i=0;i<top;i++){front[i].clear();deg[i]=0;color[i]=1;}
    for(int i=0;i<n;i++)
        for(int j=0;j<back[i].size();j++)
            if(id[i]!=id[back[i][j]])
            {
                deg[id[back[i][j]]]++;
                front[id[i]].push_back(id[back[i][j]]);
            }
    stack<int>S;
    vector<int>aa;
    for(int i=0;i<top;i++)
        if(deg[i]==0)S.push(i);
    while(!S.empty())
    {
        int i=S.top();S.pop();
        aa.push_back(i);
        int j,len=front[i].size();
        for(j=0;j<len;j++)
        {
            deg[front[i][j]]--;
            if(deg[front[i][j]]==0)S.push(front[i][j]);
        }
    }

    for(int i=0;i<aa.size();i++)
        if(color[aa[i]])
            for(int j=0;j<n;j++)
                if(id[j]==aa[i])
                    color[id[j^1]]=0;
    for(int i=2;i<n/2;i++)
        if(color[id[i]])
        {
            if(i%2)printf("%dh",i/2);
            else printf("%dw",i/2);
            printf(" ");
        }
    puts("");
}
int main()
{
    int m;
    while(scanf("%d%d",&n,&m),n||m)
    {
        for(int i=0;i<4*n;i++){front[i].clear();back[i].clear();}
        for(int i=0;i<n;i++)
        {//i 表示 wife，n+i 表示 husband
            front[zeros(i)].push_back(ones(i+n));   back[ones(i+n)].push_back(zeros(i));
            front[zeros(i+n)].push_back(ones(i));   back[ones(i)].push_back(zeros(i+n));
            front[ones(i)].push_back(zeros(i+n));   back[zeros(i+n)].push_back(ones(i));
            front[ones(i+n)].push_back(zeros(i));   back[zeros(i)].push_back(ones(i+n));
        }
        front[1].push_back(0);back[0].push_back(1);
        while(m--)
        {
            char ch1,ch2;
            int a,b;
            scanf("%d%c%d%c",&a,&ch1,&b,&ch2);
            if(ch1=='w'&&ch2=='w')
            {
                front[ones(a)].push_back(zeros(b)); back[zeros(b)].push_back(ones(a));
                front[ones(b)].push_back(zeros(a)); back[zeros(a)].push_back(ones(b));
            }
            else if(ch1=='w'&&ch2=='h')
            {
                front[ones(a)].push_back(zeros(n+b));   back[zeros(b+n)].push_back(ones(a));
                front[ones(b+n)].push_back(zeros(a));   back[zeros(a)].push_back(ones(b+n));
            }
            else if(ch1=='h'&&ch2=='w')
            {
                front[ones(a+n)].push_back(zeros(b));   back[zeros(b)].push_back(ones(a+n));
                front[ones(b)].push_back(zeros(a+n));   back[zeros(a+n)].push_back(ones(b));
            }
            else{
              front[ones(a+n)].push_back(zeros(b+n)); back[zeros(b+n)].push_back(ones(a+n));
              front[ones(b+n)].push_back(zeros(a+n)); back[zeros(a+n)].push_back(ones(b+n));
            }
        }
        memset(v,0,sizeof(v));top=0;
        for(int i=0;i<4*n;i++)
            if(!v[i])DFS(i);

        memset(v,0,sizeof(v));top=0;
        for(int i=4*n-1;i>=0;i--)
            if(!v[order[i]]){DFS_RG(order[i]);top++;}

        bool flag=false;
        for(int i=0;i<2*n;i++)
            if(id[zeros(i)]==id[ones(i)]){flag=true;break;}

        if(flag)puts("bad luck");
        else Display();
    }
    return 0;
}
