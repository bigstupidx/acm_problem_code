#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct node {
	int area, score, mm, xx;
	int arr[52];
	double sc[52];
} nod[152];

struct FDU {
	int id;
	double score;

	bool operator<(const FDU & a)const {
		return a.score < score;
	}
} now, fdu[52][152];

int n, m, cnt[52], area[52], maxi[52], flag[152], school[152];

int main() {
	int nca;
	scanf("%d", &nca);
	while (nca--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) {
			scanf("%d%d%d", &nod[i].area, &nod[i].score, &nod[i].mm);
			for (int j = 0; j < nod[i].mm; j++) {
				scanf("%d", &nod[i].arr[j]);
			}
			nod[i].xx = 0;
		}
		for (int i = 1; i <= m; i++) {
			scanf("%d%d", area + i, maxi + i);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < nod[i].mm; j++) {
				if (nod[i].area != area[nod[i].arr[j]]) {
					nod[i].sc[j] = nod[i].score * 0.7;
				}
				else {
					nod[i].sc[j] = nod[i].score;
				}
			}
		}
		memset(cnt, 0, sizeof (cnt));
		memset(flag, 0, sizeof (flag));
		while (1) {
			for (int i = 0; i < n; i++) {
				if (nod[i].xx > nod[i].mm || nod[i].mm == 0)flag[i] = 1;
			}
			int yy = 0;
			for (int i = 0; i < n; i++) {
				if (flag[i] == 0) {
					now.id = i;
					now.score = nod[i].sc[nod[i].xx];
					int j = nod[i].arr[nod[i].xx++];
					fdu[j][cnt[j]++] = now;
					school[i] = j;
					flag[i] = 2;
					yy++;
				}
			}
			if (!yy)break;
			for (int i = 1; i <= m; i++) {
				sort(fdu[i], fdu[i] + cnt[i]);
				/*
				for(int j=0;j<cnt[i];j++){
					printf("%d %.0lf   ", fdu[i][j].id, fdu[i][j].score);
				}
				puts("");
				 */
				for (int j = maxi[i]; j < cnt[i]; j++) {
					flag[fdu[i][j].id] = 0;
				}
				if (maxi[i] < cnt[i]) {
					cnt[i] = maxi[i];
				}
			}
			//getchar();
		}
		for (int i = 0; i < n; i++) {
			if (flag[i] == 1) {
				puts("not accepted");
			}
			else {
				printf("%d\n", school[i]);
			}
		}
		if (nca != 0) {
			puts("");
		}
	}
	return 0;
}
