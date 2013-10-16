#include <cstdio>
#include <queue>
#include <map>
#include <cstring>

using namespace std;

struct edge{
    int to;
    int d;
    edge *next;
}edg[200010], *vert[800];

char str[1002];
const int inf = 1000000000;
double dis[800];
int flag[800], cnt[800], m;
void add_edge(int x, int y, int va, int &top){
    //printf("%d -> %d %d\n", x, y, va);
    edge *p=&edg[++top];
    p->to=y;
    p->d=va;
    p->next=vert[x];	vert[x]=p;
}

bool spfa(double mid){
    queue<int>Q;
    for(int i=0;i<m;i++){
	dis[i]=0;
	flag[i]=1;
	cnt[i]=0;
	Q.push(i);
    }
    while(!Q.empty()){
	int s=Q.front();Q.pop();
	flag[s]=0;
	for(edge *p=vert[s];p;p=p->next){
	    if(dis[p->to]<dis[s]+p->d-mid){
		dis[p->to]=dis[s]+p->d-mid;
		if(!flag[p->to]){
		    if(++cnt[p->to]>m)return true;
		    Q.push(p->to);
		    flag[p->to]=1;
		}
	    }
	}
    }
    return false;
}

int main(){
    int n;
    while(scanf("%d", &n),n){
	int top=-1, id=0;
	double lf=1000000, rt=-1;
	memset(vert, 0, sizeof(vert));
	map<int,int>mp;
	map<int,int>::iterator p;
	for(int i=0;i<n;i++){
	    scanf("%s", str);
	    int len=strlen(str);
	    int u=(str[0]-'a')*26+str[1]-'a';
	    int v=str[len-1]-'a'+(str[len-2]-'a')*26;
	    p=mp.find(u);
	    if(p==mp.end()){
		mp[u]=id;
		u=id++;
	    }
	    else u=p->second;
	    p=mp.find(v);
	    if(p==mp.end()){
		mp[v]=id;
		v=id++;
	    }
	    else v=p->second;
	    add_edge(u, v, len, top);
	    if(rt<len){
		rt=len;
	    }
	    if(lf>len){
		lf=len;
	    }
	}
	m=id;
	int x=0;
	while(rt>lf+1e-5){
	    double mid=(lf+rt)/2;
	    //printf("try: %lf\n", mid);
	    if(spfa(mid)){
		x=1;
		lf=mid;
	    }
	    else{
		rt=mid;
	    }
	}
	if(!x)puts("No solution.");
	else{
	    printf("%.2lf\n", lf);
	}
    }
    return 0;
}