#include <cstdio>
#include <cstring>
#define maxn 1000010

int wa[maxn], wv[maxn], wb[maxn], ws[1001];

bool cmp(int *r, int a, int b, int l) {
	return r[a] == r[b] && r[a + l] == r[b + l];
}

void da(int *r, int *sa, int n, int m) {
	int *x = wa, *y = wb, *t;
	for (int i = 0; i < m; i++) {
		ws[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		x[i] = r[i];
		ws[r[i]]++;
	}
	for (int i = 1; i < m; i++) {
		ws[i] += ws[i - 1];
	}
	for (int i = n - 1; i >= 0; i--) {
		sa[--ws[r[i]]] = i;
	}
	for (int p = 1, j = 1, i; p < n; m = p, j <<= 1) {
		for (p = 0, i = n - j; i < n; i++) {
			y[p++] = i;
		}
		for (i = 0; i < n; i++) {
			if (sa[i] >= j) {
				y[p++] = sa[i] - j;
			}
		}
		for (i = 0; i < n; i++) {
			wv[i] = x[y[i]];
		}
		for (i = 0; i < m; i++) {
			ws[i] = 0;
		}
		for (i = 0; i < n; i++) {
			ws[wv[i]]++;
		}
		for (i = 1; i < m; i++) {
			ws[i] += ws[i - 1];
		}
		for (i = n - 1; i >= 0; i--) {
			sa[--ws[wv[i]]] = y[i];
		}
		t = x, x = y, y = t;
		x[sa[0]] = 0;
		for (p = 1, i = 1; i < n; i++) {
			x[sa[i]] = cmp(y, sa[i], sa[i - 1], j) ? p - 1 : p++;
		}
	}
	return;
}

int rank[maxn], height[maxn];

void calheight(int *r, int *sa, int n) {
	for (int i = 1; i <= n; i++) {
		rank[sa[i]] = i;
	}
	for (int k = 0, i = 0; i < n; height[rank[i++]] = k) {
		if (k)k--;
		for (int j = sa[rank[i] - 1];; k++) {
			if (r[i + k] != r[j + k]) {
				break;
			}
		}
	}
}

char str[maxn];
int r[maxn], sa[maxn], map[maxn];

void make_rmq(int n) {
	int mid = rank[0], mini = height[mid], i = mid - 1;
	while (i > 0) {
		map[i] = mini;
		if (mini > height[i])mini = height[i];
		i--;
	}
	mini = height[mid + 1], i = mid + 1;
	while (i <= n) {
		map[i] = mini;
		if (mini > height[i])mini = height[i];
		i++;
	}
}

int main() {
	while (scanf("%s", str), strcmp(str, ".") != 0) {
		int len = strlen(str);
		for (int i = 0; i < len; i++) {
			r[i] = str[i];
		}
		r[len] = 0;
		da(r, sa, len + 1, 300);
		calheight(r, sa, len);
		/*
		for(int i=0;i<=len;i++){
			printf("%d ", sa[i]);
		}
		puts("");
		for(int i=0;i<len;i++){
			printf("%d ", rank[i]);
		}
		puts("");
		for(int i=1;i<=len;i++){
			printf("%d ", height[i]);
		}
		puts("");
		//*/
		make_rmq(len);
		//		for (int i = 1; i <= len; i++) {
		//			printf("%d ", map[i]);
		//		}
		//		puts("");
		int ans = 1;
		for (int i = 1; i < len; i++) {
			if (len % i)continue;
			if (len - i == map[rank[i]]) {
				ans = len / i;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
