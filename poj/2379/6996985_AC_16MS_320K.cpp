#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
struct node{
	int id;
	int cnt;
	int time;
	int flag[22], tried[22];
	bool operator <(const node &a)const{
		if(a.cnt==cnt){
			if(a.time==time){
				return a.id > id;
			}
			return a.time > time;
		}
		return a.cnt < cnt;
	}
}nod[1002];

struct Input{
	int ci, ri, ti, pi;
	bool operator <(const Input &a)const{
		return a.ti > ti;
	}
}input[1002];

int c, n;

int main(){
	while(scanf("%d%d", &c, &n)!=EOF){
		for(int i=1;i<=c;i++){
			nod[i].id=i;
			nod[i].cnt=0;
			nod[i].time=0;
			memset(nod[i].flag, 0, sizeof(nod[i].flag));
			memset(nod[i].tried, 0, sizeof(nod[i].tried));
		}
		for(int i=0;i<n;i++){
			int ci, pi, ti, ri;
			scanf("%d%d%d%d", &ci, &pi, &ti, &ri);
			input[i].ci=ci;
			input[i].pi=pi;
			input[i].ti=ti;
			input[i].ri=ri;
		}
		sort(input, input+n);
		for(int i=0;i<n;i++){
			int ci=input[i].ci;
			int pi=input[i].pi;
			int ti=input[i].ti;
			int ri=input[i].ri;
			//printf("%d %d %d %d\n", ci, pi, ti, ri);
			if(nod[ci].flag[pi])continue;
			else{
				if(ri){
					nod[ci].cnt++;
					nod[ci].time+=nod[ci].tried[pi]*1200 + ti;
					nod[ci].flag[pi]=1;
				}
				else{
					nod[ci].tried[pi]++;
				}
			}
		}
		sort(nod+1, nod+c+1);
		for(int i=1;i<=c;i++){
			printf("%d ", nod[i].id);
		}
		puts("");
	}
	return 0;
}
