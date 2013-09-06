#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
#include <cstring>
#define inf 0x7fffffff

using namespace std;

/*struct node
{
	int id;
	int dis;
	friend bool operator <(node a,node b)
	{
		return a.dis>b.dis;
	}
}no1,no2;*/
struct adj {
	int id;
	int dis;
	adj *next;
} edge[150005], * head[30002];

void add_edge(int a, int b, int dis, int &total) {
	adj *temp = &edge[total++];
	temp->id = b;
	temp->dis = dis;
	temp->next = head[a], head[a] = temp;
}

int dis[30002];
bool visit[30002];
int Q[30002];
int n, m;

int spfa() {
	for (int i = 1; i <= n; i++) {
		dis[i] = inf;
		visit[i] = false;
	}
	visit[1] = true;
	dis[1] = 0;
	//stack <int> s;
	//s.push(1);
	int first = 0, tail = 1;
	Q[0] = 1;
	while (first != tail) {
		int u = Q[first % n];
		first++;
		visit[u] = false;
		for (adj *p = head[u]; p; p = p->next) {
			if (dis[p->id] > dis[u] + p->dis) {
				dis[p->id] = dis[u] + p->dis;
				if (!visit[p->id]) {
					Q[tail % n] = p->id;
					tail++;
					visit[p->id] = true;
				}
			}
		}
	}
	return dis[n];
}

/*int dijkstra()
{
	for(int i=1;i<=n;i++)
	{
		dis[i]=inf;
		visit[i]=false;
	}
	dis[1]=0;
	no1.dis=0;no1.id=1;
	priority_queue <node> Q;
	Q.push(no1);
	while(!Q.empty())
	{
		no1=Q.top();
		Q.pop();
		int u=no1.id;
		if(visit[u])continue;
		visit[u]=true;
		for(adj *p=head[u];p;p=p->next)
		{
			if(!visit[p->id]&&dis[p->id]>dis[u]+p->dis)
			{
				dis[p->id]=dis[u]+p->dis;
				no2.id=p->id;
				no2.dis=dis[p->dis];
				Q.push(no2);
			}
		}
	}
	return dis[n];
}*/
int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		memset(head, 0, sizeof (head));
		int total = 0;
		for (int i = 1; i <= m; i++) {
			int a, b, dis;
			scanf("%d%d%d", &a, &b, &dis);
			add_edge(a, b, dis, total);
		}
		printf("%d\n", spfa());
	}
	return 0;
}
