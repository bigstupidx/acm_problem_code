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
}

void right_align(int lf, int rt, int sum) {
	int y=75-sum;
	for(int i=0;i<y;i++){
		putchar(' ');
	}
	printf("%s", nod[lf].str);
	for(int i=lf+1;i<rt;i++){
		printf(" %s", nod[i].str);
	}
}

void center_align(int lf, int rt, int sum) {
	int y=(75-sum)/2;
	for(int i=0;i<y;i++){
		putchar(' ');
	}
	printf("%s", nod[lf].str);
	for(int i=lf+1;i<rt;i++){
		printf(" %s", nod[i].str);
	}
}

void justify_align(int lf, int rt, int sum) {
	if(rt==top){
		left_align(lf, rt, sum);
		return ;
	}
	int y=75-sum+rt-lf-1;
	printf("%s", nod[lf].str);
	if(rt==lf+1)return ;
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

void align(int i, int j, int sum) {
	if (map[0] == 'L') {
		left_align(i, j, sum);
	}
	else if (map[0] == 'R') {
		right_align(i, j, sum);
	}
	else if (map[0] == 'C') {
		center_align(i, j, sum);
	}
	else {
		justify_align(i, j, sum);
	}
	puts("");
}

void solve() {
	int sum = nod[0].len, j = 0;
	for (int i = 1; i < top; i++) {
		if (sum + nod[i].len + 1 > 75) {
			align(j, i, sum);
			sum = nod[i].len;
			j = i;
		}
		else {
			sum += nod[i].len + 1;
		}
	}
	align(j, top, sum);
}

int main() {
//	freopen("small.in", "r", stdin);
//	freopen("out.txt", "w", stdout);
	scanf("%s", map);
	while (scanf("%s", nod[top].str) != EOF) {
		nod[top].len = strlen(nod[top].str);
		top++;
	}
	solve();
	return 0;
}
