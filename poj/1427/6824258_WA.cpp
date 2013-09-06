#include <cstdio>
#include <map>
#include <queue>
#include <cstdlib>
#include <cstring>

using namespace std;

char ncase[30];
int n, s, t, dis[12][12], tim, ppl[12], last[12];

struct QN {
	int cap, f, u, ser, cur;

	bool operator<(const QN & a)const {
		if (a.cur == cur)
			return a.ser > ser;
		return a.cur < cur;
	}
};

int main() {
	while (scanf("%s", ncase), strcmp(ncase, "TheEnd") != 0) {

		puts(ncase);
		scanf("%d%d%d", &n, &s, &t);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (j == i)dis[i][j] = 0;
				else
					scanf("%d", &dis[i][j]);
			}
		}
		int sum = 0, x = 0, k = 2;
		for (int i = 1; i < n; i++) {
			scanf("%d", ppl + i);
			sum += ppl[i];
		}
		scanf("%d", &tim);
		memset(last, -1, sizeof (last));

		QN now, tem;
		priority_queue<QN>Q;
		map<int,int>mp;
		map<int,int>::iterator p,q;
		now.cap = s > 3 ? s : 3;
		now.u = 1;
		now.f = 0;
		now.ser = dis[0][1];
		now.cur = dis[0][1];
		last[0]=1;
		Q.push(now);
		while (!Q.empty()) {
			now = Q.top();
			Q.pop();
			if(!mp.empty()){
				p=mp.begin();
				int flag=0;
				while(p->first<now.cur&&p!=mp.end()){
					tem.u = (last[0]+1)%n;
					if(tem.u==0)tem.u=(last[0]+1)%n;
					last[0]=tem.u;
					tem.cur=p->first+dis[0][tem.u];
					tem.f=0;
					tem.cap=s-(k-1)*t;k++;
					if(3>tem.cap)tem.cap=3;
					tem.ser=0;
					Q.push(tem);
					q = p++;
					mp.erase(q);
					flag=1;
				}
				if(flag){
					Q.push(now);
					continue;
				}
			}
			//printf("%d %d %d\n", now.u, now.cur, now.f);
			//getchar();
			
			if (now.cur > tim)break;
			int u = now.u;
			if (u == 0) {
				x += now.f;
				if (x == sum)break;
				now.f = 0;
				now.u = (last[0]+1)%n;
				if(now.u==0)now.u=(last[0]+2)%n;
				tem.cur+=dis[0][now.u];
				continue;
			}
			if(now.f+ppl[u]>now.cap){
				mp[now.cur+2]=1;
				ppl[u]-=now.cap-now.f;
				now.f=now.cap;
				now.u=0;
				now.cur+=dis[u][0];
				now.ser+=dis[u][0];
				last[u]=0;
				Q.push(now);
			}
			else{
				now.f+=ppl[u];
				ppl[u]=0;
				if(now.f==now.cap){
					last[u]=0;
					now.u=0;
					now.cur+=dis[u][0];
					now.ser+=dis[u][0];
					Q.push(now);
				}
				else{
					int v = (u+1)%n;
					if(last[u]!=-1){
						v=(last[u]+1)%n;
						if(v==u)
							v=(last[u]+2)%n;
					}
					last[u]=v;
					now.u=v;
					now.cur+=dis[u][v];
					now.ser+=dis[u][v];
					Q.push(now);
				}
			}
		}
		if (x == sum)printf("%d seconds needed\n", now.cur);
		else printf("%d contestants reached\n", x);
	}
	return 0;
}