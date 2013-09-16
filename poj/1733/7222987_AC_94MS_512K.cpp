#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

struct node{
	int x, y;
	int d;
}nod[5010]; 

char str[5];
int n, m, par[20010];

int my_find(int x){
	if(par[x]==x){
		return x;
	}
	return par[x]=my_find(par[x]);
}

int main(){
	while(scanf("%d", &n)!=EOF){
		
		map <int, int> mp;
		map <int, int> ::iterator p;
		
		scanf("%d", &m);
		for(int i=0;i<m;i++){
			scanf("%d%d%s", &nod[i].x, &nod[i].y, str);
			nod[i].x--;
			if(mp.find(nod[i].x)==mp.end()){
				mp[nod[i].x]=1;
			}
			if(mp.find(nod[i].y)==mp.end()){
				mp[nod[i].y]=1;
			}
			if(str[0]=='o'){
				nod[i].d=1;
			}
			else {
				nod[i].d=0;
			}
		}
		int id=0;
		for(p=mp.begin();p!=mp.end();p++){
			p->second=id++;
		}
		int ans=m;
		id<<=1;
		for(int i=0;i<id;i++){
			par[i]=i;
		}
		for(int i=0;i<m;i++){
			nod[i].x=mp.find(nod[i].x)->second;
			nod[i].y=mp.find(nod[i].y)->second;
			int ii=my_find(2*nod[i].x);
			int jj=my_find(2*nod[i].y);
			int xx=my_find(2*nod[i].x+1);
			int yy=my_find(2*nod[i].y+1);
//			printf("%d %d\n", nod[i].x, nod[i].y);
//			printf("%d %d %d %d\n", ii, xx, jj, yy);
			if(nod[i].d==0){
				if(ii==yy||xx==jj){
					ans=i;
					break;
				}
				par[ii]=jj;
				par[xx]=yy;
			}
			else {
				if(ii==jj||xx==yy){
					ans=i;
					break;
				}
				par[ii]=yy;
				par[xx]=jj;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
