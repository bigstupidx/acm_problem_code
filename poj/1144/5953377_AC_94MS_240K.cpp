#include<cstdio>
#include<string>
#include<cstring>
#include<sstream>
using namespace std;
struct edge{
    int to;
    edge *next;
}edg[10010],*vert[100];
int n,anc[100],cut[100],dep[100],tem[100],color[100];
char str[1000];
void Add_Edge(int x,int y,int &top)
{
    //printf("%d->%d\n",x,y);
    edge *p=&edg[++top];
    p->to=y;
    p->next=vert[x];    vert[x]=p;
}
void DFS(int k, int k_father, int depth)
{
    color[k] = 1; //染色为灰色 
    anc[k] = dep[k] = depth;
    int tot = 0; //儿子结点个数
    for (edge *p = vert[k]; p; p = p->next)
    {
        int i = p->to;
        if (i != k_father && color[i] == 1)
            anc[k] = anc[k] > dep[i] ? dep[i] : anc[k];
        else if (color[i] == 0) {
            tot++;
            DFS(i, k, depth + 1);
            anc[k] = anc[k] > anc[i] ? anc[i] : anc[k];
            //k为割顶的条件是： 
            //k不是根某儿子结点 i 的祖先比 k 的深度小
            //          即从 i 出发无到 k 祖先的后向边。 
            //k是根，其儿子的个数大于 1 
            if (k_father == 0 && tot > 1 || k_father != 0 && anc[i] >= dep[k])
                cut[k] = true;
        }
    }
    color[k] = 2; //染色为黑色 
}
int main()
{
    while(scanf("%d",&n),getchar(),n)
    {
        int top=-1;
        memset(vert,0,sizeof(vert));
        while(1){
            gets(str);
            string st(str);
            istringstream in(st);
            int m=0;
            while(in>>tem[m])m++;
            if(tem[0]==0)break;
            for(int i=1;i<m;i++){
                Add_Edge(tem[0],tem[i],top);
                Add_Edge(tem[i],tem[0],top);
            }
        }
        memset(color,0,sizeof(color));
        memset(cut,0,sizeof(cut));
        for(int i=1;i<=n;i++)
            if(!color[i])DFS(i,0,1);
        int ans=0;
        for(int i=1;i<=n;i++)
            if(cut[i]){
                //printf("%d ",i);
                ans++;
            }
        printf("%d\n",ans);
    }
    return 0;
}
