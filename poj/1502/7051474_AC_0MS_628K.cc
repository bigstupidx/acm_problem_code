#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

struct edge{
    int to;
    int d;
    edge *next;
}edg[20010], *vert[102];

char str[20];
const int inf = 1000000000;
int n, dis[102],flag[102];

struct QN{
    int ii;
    bool operator <(const QN &a)const{
	return dis[a.ii] < dis[ii];
    }
}now;

int change_to_int(){
    int ans=0;
    int len=strlen(str);
    for(int i=0;i<len;i++){
	ans*=10;
	ans+=str[i]-'0';
    }
    return ans;
}

void add_edge(int x, int y, int va, int &top){
//    printf("%d->%d %d\n", x, y, va);
    edge *p=&edg[++top];
    p->to=y;
    p->d=va;
    p->next=vert[x];	vert[x]=p;
}

void dijkstra(int s){
    priority_queue<QN>Q;
    for(int i=1;i<=n;i++){
	dis[i]=inf;
	flag[i]=0;
    }
    now.ii=s;
    Q.push(now);
    dis[s]=0;
    flag[s]=1;
    while(!Q.empty()){
	now=Q.top();Q.pop();
	int k=now.ii;
	for(edge *p=vert[k];p;p=p->next){
	    if(dis[p->to]>dis[k]+p->d){
		dis[p->to]=dis[k]+p->d;
		if(!flag[p->to]){
		    flag[p->to]=1;
		    now.ii=p->to;
		    Q.push(now);
		}
	    }
	}
	flag[k]=0;
    }
}

int main(){
    while(scanf("%d", &n)!=EOF){
	int top=-1;
	memset(vert, 0, sizeof(vert));
	for(int i=2;i<=n;i++){
	    for(int j=1;j<i;j++){
		scanf("%s", str);
		if(strcmp(str, "x")!=0){
		    int tem=change_to_int();
		    add_edge(i, j, tem, top);
		    add_edge(j, i, tem, top);
		}
	    }
	}
	dijkstra(1);
	int maxi=-1;
	for(int i=2;i<=n;i++){
	    //printf("%d ", dis[i]);
	    if(dis[i]>maxi){
		maxi=dis[i];
	    }
	}
	printf("%d\n", maxi);
    }
    return 0;
}