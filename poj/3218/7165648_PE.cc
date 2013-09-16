#include <cstdio>
#include <cstring>

char map[5];

struct node {
	int len;
	char str[200];
} nod[10010];

int top;

void left_align(int lf, int rt, int sum) {
	printf("%s", nod[lf].str);
	for(int i=lf+1; i<rt;i++){
		printf(" %s", nod[i].str);
	}
	puts("");
}

void right_align(int lf, int rt, int sum) {
	sum=75-sum;
	for(int i=0;i<sum;i++){
		putchar(' ');
	}
	printf("%s", nod[lf].str);
	for(int i=lf+1;i<rt;i++){
		printf(" %s", nod[i].str);
	}
	puts("");
}

void center_align(int lf, int rt, int sum) {
	int y=(75-sum)/2;
	y=75-sum-y;
	for(int i=0;i<y;i++){
		putchar(' ');
	}
	printf("%s", nod[lf].str);
	for(int i=lf+1;i<rt;i++){
		printf(" %s", nod[i].str);
	}
	y=75-sum-y;
	for(int i=0;i<y;i++){
		putchar(' ');
	}
	puts("");
}

void justify_align(int lf, int rt, int sum) {
	int y=74-sum+rt-lf;
	printf("%s", nod[lf].str);
	if(rt==top){
		for(int i=lf+1;i<rt;i++){
			printf(" %s", nod[i].str);
		}
	}
	else {
		if(rt==lf+1){
			sum=75-sum;
			for(int i=0;i<sum;i++){
				putchar(' ');
			}
		}
		else {
			int x=rt-lf-1, z=y/x, cnt=y%x;
			for(int i=lf+1;i<rt;i++){
				for(int j=0;j<z;j++){
					putchar(' ');
				}
				if(cnt){
					cnt--;
					putchar(' ');
				}
				printf("%s", nod[i].str);
			}
		}
	}
	puts("");
}

void align(int i, int j, int sum) {
	if (map[0] == 'L') {
		left_align(i, j+1, sum);
	}
	else if (map[0] == 'R') {
		right_align(i, j+1, sum);
	}
	else if (map[0] == 'C') {
		center_align(i, j+1, sum);
	}
	else {
		justify_align(i, j+1, sum);
	}
}

void solve() {
	int sum = nod[0].len, j = 0;
	for (int i = 1; i < top; i++) {
		if (sum + nod[i].len + 1 > 75) {
			align(j, i - 1, sum);
			sum = nod[i].len;
			j = i;
		}
		else {
			sum += nod[i].len + 1;
		}
	}
	align(j, top - 1, sum);
}

int main() {
//	freopen("small.in", "r", stdin);
//	freopen("out.txt", "w", stdout);
	scanf("%s", map);
	while (scanf("%s", nod[top].str) != EOF) {
		nod[top].len = strlen(nod[top].str);
		top++;
	}
//	for(int i=0;i<top;i++){
//		printf("%d %s\n", nod[i].len, nod[i].str);
//	}
	solve();
	return 0;
}
