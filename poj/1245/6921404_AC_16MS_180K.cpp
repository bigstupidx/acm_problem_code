#include <cstdio>
#include <string>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

struct node{
	char name[20];
	int cnt, sum, arr[8], aver, rank;
	bool operator <(const node &a)const{
		if(a.cnt==cnt){
			if(a.sum==sum){
				if(a.aver==aver)
					return strcmp(a.name, name) > 0;
				return a.aver > aver;
			}
			return a.sum > sum;
		}
		return a.cnt < cnt;
	}
}nod[22];

char team[20];
const double e = 2.718281828;
int main()
{
	int n, nca=1, x;
	while(scanf("%d", &n), n){
		double tem;
		for(int i=0;i<n;i++){
			scanf("%s", team);
			strcpy(nod[i].name, team);
			nod[i].cnt=0;
			nod[i].sum=0;
			tem = 0;
			for(int j=0;j<7;j++){
				scanf("%d", &x);
				nod[i].arr[j]=x;
				if(x){
					nod[i].cnt++;
					nod[i].sum+=x;
					tem+=log(x*1.0);
				}
			}
			if(nod[i].cnt == 0)nod[i].aver=0;
			else{
				//printf("%lf %lf\n", tem, pow(e,tem/7));
				nod[i].aver =(int)(pow(e,tem/nod[i].cnt)+0.5);
			}
		}
		sort(nod, nod+n);
		nod[0].rank=1;
		for(int i=1;i<n;i++){
			if(nod[i].cnt==nod[i-1].cnt&&nod[i].sum==nod[i-1].sum&&nod[i].aver==nod[i-1].aver){
				nod[i].rank=nod[i-1].rank;
			}
			else
				nod[i].rank=i+1;
		}
		printf("CONTEST %d\n", nca++);
		for(int i=0;i<n;i++){
			printf("%.2d %s", nod[i].rank, nod[i].name);
			int len=11-strlen(nod[i].name);
			for(int j=0;j<len;j++)putchar(' ');
			printf("%d %4d %3d", nod[i].cnt, nod[i].sum, nod[i].aver);
			for(int j=0;j<7;j++){
				printf(" %3d", nod[i].arr[j]);
			}
			puts("");
		}
	}
	return 0;
}