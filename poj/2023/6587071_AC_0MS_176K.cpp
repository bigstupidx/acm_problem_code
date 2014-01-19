#include <cstdio>
#include <cstring>
using namespace std;
struct edge{
    int to;
    edge *next;
}edg[10010],*vert[102];
char str[102][300];
int n,flag[102],visit[102],next[102];
void add_edge(int x,int y,int &top){
    edge *p=&edg[++top];
    p->to=y;
    p->next=vert[x];    vert[x]=p;
}
bool DFS(int s){
    visit[s]=1;
    if(flag[s])return true;
    for(edge *p=vert[s];p;p=p->next){
        if(DFS(p->to)){
            next[s]=p->to;
            return true;
        }
    }
    return false;
}
int main(){
    int nca;
    scanf("%d",&nca);
    for(int ii=1;ii<=nca;ii++){
        char ch[12];
        int top = -1;
        scanf("%d",&n);
        memset(flag,0,sizeof(flag));
        memset(vert,0,sizeof(vert));
        for(int i=1;i<=n;i++){
            scanf("%s",ch);
            while(getchar()!='"');
            int j=0;
            while((str[i][j]=getchar())!='"')j++;
            str[i][j]=0;
            //puts(str[i]);
            if(ch[0]=='C'){
                int u,v;
                scanf("%d%d",&u,&v);
                add_edge(i,u,top);
                add_edge(i,v,top);
            }
            else{
                scanf("%s",ch);
                if(strcmp(ch,"HAPPY")==0)
                    flag[i]=1;
            }
        }
        memset(next,0,sizeof(next));
        memset(visit,0,sizeof(visit));
        printf("STORY %d\n",ii);DFS(1);
        for(int i=1;i;i=next[i])
            puts(str[i]); 
    }
    return 0;
}
