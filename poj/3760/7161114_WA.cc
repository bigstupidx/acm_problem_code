#include <cstdio>
#include <cstdlib>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

char camp[2][5] = {"red", "blue"};
char name[5][10] = {"dragon", "ninja", "iceman", "lion", "wolf"};

int dir[2][5] = {
	2, 3, 4, 1, 0,
	3, 0, 1, 2, 4
};
int xflag;
int knight[2][5], sum[2], T, tim, n, val[22], city[2][22], flag[22], wi[22], cnt[2];
int aa[22];

struct node {
	int kill, life, power;
} nod[2][10010];

void create_knight() {
	for (int i = 0; i < 2; i++) {
		int k = dir[i][cnt[i] % 5];
		if (sum[i] >= knight[0][k]) {
			printf("%.3d:00 %s %s %d born\n", tim / 60, camp[i], name[k], cnt[i] + 1);
			sum[i] -= knight[0][k];
			nod[i][cnt[i]].kill = 0;
			nod[i][cnt[i]].life = knight[0][k];
			nod[i][cnt[i]].power = knight[1][k];
			if (i == 0) {
				city[0][0] = cnt[i] + 1;
			}
			else {
				city[1][n + 1] = cnt[i] + 1;
			}
			cnt[i]++;
		}
	}
}
void move_one_step(){
	int k, idd=-1, tt=tim/60;
	for(int i=0;i<=n+1;i++){
		if(i!=n+1&&city[0][i]){
			k=city[0][i]-1;
			if(k%5==0){
				nod[0][k].kill++;
				if(nod[0][k].kill%2==0){
					nod[0][k].power+=20;
					if(nod[0][k].life>9){
						nod[0][k].life-=9;
					}
					else {
						nod[0][k].life=1;
					}
				}
			}
		}
		if(i!=0&&city[1][i]){
			k=city[1][i]-1;
			if(k%5==3){
				nod[1][k].kill++;
				if(nod[1][k].kill%2==0){
					nod[1][k].power+=20;
					if(nod[1][k].life>9){
						nod[1][k].life-=9;
					}
					else {
						nod[1][k].life=1;
					}
				}
			}
		}
	}
	if(city[1][1]){
		city[1][0]++;
		k=city[1][1] - 1;
		printf("%.3d:10 blue %s %d reached red headquarter with %d elements and force %d\n",
		tt, name[dir[1][k%5]], k+1, nod[1][k].life, nod[1][k].power);
		if(city[1][0]>=2){
			xflag=1;
			printf("%.3d:10 red headquarter was taken\n", tt);
		}
	}
	for(int i=1;i<=n;i++){
		city[1][i]=city[1][i+1];
	}
	city[1][n+1] = 0;
	if(city[0][n]){
		idd = city[0][n] - 1;
	}
	for(int i=n;i>0;i--){
		city[0][i]=city[0][i-1];
	}
	city[0][0]=0;
	for(int i=1;i<=n;i++){
		if(city[0][i]){
			k=city[0][i]-1;
			printf("%.3d:10 red %s %d marched to city %d with %d elements and force %d\n",
			tt, name[dir[0][k%5]], k+1, i, nod[0][k].life, nod[0][k].power);
		}
		if(city[1][i]){
			k=city[1][i]-1;
			printf("%.3d:10 blue %s %d marched to city %d with %d elements and force %d\n",
			tt, name[dir[1][k%5]], k+1, i, nod[1][k].life, nod[1][k].power);
		}
	}
	if(idd!=-1){
		city[0][n+1]++;
		printf("%.3d:10 red %s %d reached blue headquarter with %d elements and force %d\n",
		tt, name[dir[0][idd%5]], idd+1, nod[0][idd].life, nod[0][idd].power);
	}
	if(city[0][n+1]>=2){
		xflag=1;
		printf("%.3d:10 blue headquarter was taken\n", tt);
	}
}

void get_value(){
	int k, tt=tim/60;
	for(int i=1;i<=n;i++){
		if(city[0][i]&&!city[1][i]){
			k=city[0][i]-1;
			printf("%.3d:30 red %s %d earned %d elements for his headquarter\n",
			tt, name[dir[0][k%5]], k+1, val[i]);
			sum[0]+=val[i];
			val[i]=0;
		}
		else if(city[1][i]&&!city[0][i]){
			k=city[1][i]-1;
			printf("%.3d:30 blue %s %d earned %d elements for his headquarter\n",
			tt, name[dir[1][k%5]], k+1, val[i]);
			sum[1]+=val[i];
			val[i]=0;
		}
	}
}
void fighting(){
	int k1, k2, tem, tt=tim/60;
	int total1=0, total2=0;
	memset(aa, 0, sizeof(aa));
	for(int i=1;i<=n;i++){
		if(city[0][i]&&city[1][i]){
			/*插红旗或者无旗,但是奇数的城市, 红武士发动进攻*/
			k1=city[0][i]-1;
			k2=city[1][i]-1;
			if(flag[i]==1||flag[i]==0&&i%2==1){
				printf("%.3d:40 red %s %d attacked blue %s %d in city %d with %d elements and force %d\n",
				tt, name[dir[0][k1%5]], k1+1, name[dir[1][k2%5]], k2+1, i, nod[0][k1].life, nod[0][k1].power);
				tem=nod[1][k2].life;
				nod[1][k2].life-=nod[0][k1].power;
				if(nod[1][k2].life<=0){
					city[1][i]=0;
					printf("%.3d:40 blue %s %d was killed in city %d\n", tt, name[dir[1][k2%5]], k2+1, i);
					if(k1%5==2){
						if((++nod[0][k1].kill)%2==0){
							nod[0][k1].life*=2;
							nod[0][k1].power*=2;
						}
					}
					if(k2%5==0){
						nod[0][k1].life+=tem;
					}
					aa[i]=1;
				}
				else {
					if(k2%5!=2){
						printf("%.3d:40 blue %s %d fought back against red %s %d in city %d\n",
						tt, name[dir[1][k2%5]], k2+1, name[dir[0][k1%5]], k1+1, i);
						tem=nod[0][k1].life;
						nod[0][k1].life-=nod[1][k2].power/2;
						if(nod[0][k1].life<=0){
							city[0][i]=0;
							printf("%.3d:40 red %s %d was killed in city %d\n", tt, name[dir[0][k1%5]], k1+1, i);
							if(k1%5==1){
								nod[1][k2].life+=tem;
							}
							if(sum[1]>=8){
								sum[1]-=8;
								nod[1][k2].life+=8;
							}
						}
					}
				}
				if(k1%5==4&&city[0][i]){
					printf("%.3d:40 red dragon %d yelled in city %d\n", tt, k1+1, i);
				}
			}
			else {
				printf("%.3d:40 blue %s %d attacked red %s %d in city %d with %d elements and force %d\n",
				tt, name[dir[1][k2%5]], k2+1, name[dir[0][k1%5]], k1+1, i, nod[1][k2].life, nod[1][k2].power);
				tem=nod[0][k1].life;
				nod[0][k1].life-=nod[1][k2].power;
				if(nod[0][k1].life<=0){
					city[0][i]=0;
					printf("%.3d:40 red %s %d was killed in city %d\n", tt, name[dir[0][k1%5]], k1+1, i);
					if(k2%5==4){
						if((++nod[1][k2].kill)%2==0){
							nod[1][k2].life*=2;
							nod[1][k2].power*=2;
						}
					}
					if(k1%5==1){
						nod[1][k2].life+=tem;
					}
					if(sum[1]>=8){
						sum[1]-=8;
						nod[1][k2].life+=8;
					}
				}
				else {
					if(k1%5!=3){
						printf("%.3d:40 red %s %d fought back against blue %s %d in city %d\n",
						tt, name[dir[0][k1%5]], k1+1, name[dir[1][k2%5]], k2+1, i);
						tem=nod[1][k2].life;
						nod[1][k2].life-=nod[0][k1].power/2;
						if(nod[1][k2].life<=0){
							city[1][i]=0;
							printf("%.3d:40 blue %s %d was killed in city %d\n",
							tt, name[dir[1][k2%5]], k2+1, i);
							if(k2%5==0){
								nod[0][k1].life+=tem;
							}
							aa[i]=1;
						}
					}
				}
				if(k2%5==1&&city[1][i]){
					printf("%.3d:40 blue dragon %d yelled in city %d\n", tt, k2+1, i);
				}
			}
			if(city[0][i]&&!city[1][i]){
				total1+=val[i];
				printf("%.3d:40 red %s %d earned %d elements for his headquarter\n", 
				tt, name[dir[0][k1%5]], k1+1, val[i]);
				val[i]=0;
				if(wi[i]>=0){
					wi[i]++;
					if(wi[i]>=2&&flag[i]!=1){
						flag[i]=1;
						printf("%.3d:40 red flag raised in city %d\n", tt, i);
					}
				}
				else {
					wi[i]=1;
				}
			}
			else if(city[1][i]&&!city[0][i]){
				total2+=val[i];
				printf("%.3d:40 blue %s %d earned %d elements for his headquarter\n",
				tt,	name[dir[1][k2%5]], k2+1, val[i]);
				val[i]=0;
				if(wi[i]<=0){
					wi[i]--;
					if(wi[i]<=-2&&flag[i]!=2){
						flag[i]=2;
						printf("%.3d:40 blue flag raised in city %d\n", tt, i);
					}
				}
				else {
					wi[i]=-1;
				}
			}
			else {
				flag[i]=0;
				wi[i]=0;
			}
		}
	}
	for(int i=n;i>0;i--){
		if(aa[i]){
			if(sum[0]>=8){
				sum[0]-=8;
				nod[0][city[0][i]-1].life+=8;
			}
		}
	}
	sum[0]+=total1, sum[1]+=total2;
}

void solve() {
	xflag=0;
	sum[1]=sum[0];
	memset(wi, 0, sizeof (wi));
	memset(val, 0, sizeof (val));
	memset(cnt, 0, sizeof (cnt));
	memset(city, 0, sizeof (city));
	memset(flag, 0, sizeof (flag));
	for (tim = 0; tim <= T && !xflag; tim += 10) {
		if (tim % 60 == 0) {
			create_knight();
		}
		else if (tim % 60 == 10) {
			move_one_step();
		}
		else if (tim % 60 == 20) {
			for (int i = 1; i <= n; i++) {
				val[i] += 10;
			}
		}
		else if (tim % 60 == 30) {
			get_value();
		}
		else if (tim % 60 == 40) {
			fighting();
		}
		else {
			for(int i=0;i<2;i++){
				printf("%.3d:50 %d elements in %s headquarter\n", tim/60, sum[i], camp[i]);
			}
		}
	}
}

int main() {
	int nca;
	scanf("%d", &nca);
	for (int ii = 1; ii <= nca; ii++) {
		scanf("%d%d%d", &sum[0], &n, &T);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 5; j++) {
				scanf("%d", &knight[i][j]);
			}
		}
		printf("Case:%d\n", ii);
		solve();
	}
	return 0;
}