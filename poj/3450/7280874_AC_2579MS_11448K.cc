#include <cstdio>
#include <cstring>
#define maxn 1000010

int wa[maxn], wb[maxn], wv[maxn], ws[maxn];

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
	for (int p = 1, i, j = 1; p < n; m = p, j <<= 1) {
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

char str[202];
int r[maxn], sa[maxn], flag[maxn], id[maxn];

bool check(int mid, int n, int m, int &ans) {
	int cnt, start = -1, lf;
	memset(flag, 0, sizeof (flag));
	for (int i = 1; i <= n; i++) {
		if (height[i] >= mid) {
			if (start == -1) {
				lf = i-1;
				cnt = 0;
				start = 1;
				ans = sa[i - 1];
				if (id[sa[i - 1]] > 0) {
					flag[id[sa[i - 1]]] = i;
					cnt++;
				}
				if (id[sa[i]] > 0 && flag[id[sa[i]]] < lf) {
					flag[id[sa[i]]] = i;
					if (++cnt == m)return true;
				}
				if(cnt != 2){
					start = -1;
				}
			}
			else {
				if (id[sa[i]] > 0 && flag[id[sa[i]]] < lf) {
					flag[id[sa[i]]] = i;
					if (++cnt == m)return true;
				}
			}
		}
		else {
			start = -1;
		}
	}
	return false;
}

int main() {
	int n;
	while (scanf("%d", &n), n) {
		int top = 0;
		memset(id, 0, sizeof (id));
		for (int i = 0; i < n; i++) {
			scanf("%s", str);
			int len = strlen(str);
			for (int j = 0; j < len; j++) {
				r[top] = str[j];
				id[top++] = i + 1;
			}
			r[top++] = '#';
		}
		top--;
		r[top] = 0;
		da(r, sa, top + 1, 300);
		calheight(r, sa, top);
		/*
		for(int i=0;i<=top;i++){
			printf("%d ", sa[i]);
		}
		puts("");
		for(int i=0;i<top;i++){
			printf("%d ", rank[i]);
		}
		puts("");
		
		for (int i = 1; i <= top; i++) {
			printf("%d ", height[i]);
		}
		puts("");
		
		for(int i=1;i<=top;i++){
			printf("%d ", id[sa[i]]);
		}
		puts("");
		*/
		int lf = 0, rt = 202, ans, tem;
		while (lf <= rt) {
			int mid = (lf + rt) / 2;
			//printf("try mid %d: ", mid);
			if (check(mid, top, n, tem)) {
				ans = tem;
				//printf("%d\n", tem);
				lf = mid + 1;
			}
			else {
				rt = mid - 1;
			}
		}
		lf--;
		//printf("%d ", lf);
		if (lf == 0) {
			puts("IDENTITY LOST");
		}
		else {
			for (int i = ans; i < ans + lf; i++) {
				printf("%c", r[i]);
			}
			puts("");
		}
	}
	return 0;
}
