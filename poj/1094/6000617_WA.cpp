#include <cstdio>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;
struct edge{
    int to;
    edge *next;
}edg[1000],*vert[30];
int in[30],deg[30],n;
vector<int>ans;
void Add_Edge(int x,int y,int &top)
{
    //printf("%d -> %d \n",x,y);
    edge *p=&edg[++top];
    p->to=y;
    p->next=vert[x];    vert[x]=p;
}
int Determine()
{
    int tt=0;
    stack<int>S;
    ans.clear();
    for(int i=0;i<n;i++)in[i]=deg[i];
    for(int i=0;i<n;i++){
        if(in[i]==0){S.push(i);tt++;}
       // printf("%d ",in[i]);
    }
   // puts("");
    while(!S.empty())
    {
        int i=S.top();S.pop();
        ans.push_back(i);
        for(edge *p=vert[i];p;p=p->next)
        {
            in[p->to]--;
            if(in[p->to]==0)S.push(p->to);
        }
    }
   // for(int i=0;i<ans.size();i++)
     //   printf("%d ",ans[i]);
   // puts("");
    if(ans.size()!=n)return -1;
    if(tt!=1)return 0;
    if(ans.size()==n)return 1;
}
int main()
{
    int m;
    while(scanf("%d%d",&n,&m),getchar(),n||m)
    {
        char aa[10];
        int flag=0,cnt,top=-1;
        memset(deg,0,sizeof(deg));
        memset(vert,0,sizeof(vert));
        for(int i=1;i<=m;i++)
        {
            scanf("%s",aa);
            if(flag!=0)continue;
            if(aa[1]=='<'){
                Add_Edge(aa[0]-'A',aa[2]-'A',top);
                deg[aa[2]-'A']++;
            }
            else{
                Add_Edge(aa[2]-'A',aa[0]-'A',top);
                deg[aa[0]-'A']++;
            }
            int tem=Determine();
            if(tem==1){flag=1;cnt=i;}//第i步确定顺序 
            else if(tem==-1){flag=-1;cnt=i;}//第i步确定冲突 
        }
        if(flag==0)puts("Sorted sequence cannot be determined.");
        else if(flag==1){
          printf("Sorted sequence determined after %d relations: ",cnt);
          for(int i=0;i<n;i++)
              printf("%c",ans[i]+'A');
          puts(".");
        }
        else printf("Inconsistency found after %d relations.\n",cnt);
    }
    return 0;
}
