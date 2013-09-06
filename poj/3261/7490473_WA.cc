/* 
 * File:   pku-3261.cpp
 * Author: xhSong
 * Created on 2010年8月19日, 下午8:41
 * Time Complexity :
 * Space Complexity : 
 * Describe : 
 */

#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#define maxn 20050

using namespace std;

/*
 待排序的字符串放在a[]中，从a[0]到a[n-1]，长度为n，且最大值小于m。
为了函数操作的方便，约定除a[n-1]外所有的a[i]都大于0, a[n-1]=0。
tmpb[]、tmpv[]和num[]均为临时数组
函数结束得到sa[]和rank[]
 */

int tmpb[maxn], tmpv[maxn], num[maxn];
int a[maxn], sa[maxn], rank[maxn], height[maxn], que[maxn];

int cmp(int r[], int i, int j, int k) {
	return r[i] == r[j] && r[i + k] == r[j + k];
}

void da(int a[], int n, int m) {
	int i, j, p, *x = rank, *y = tmpb, *t;
	for (i = 0; i < m; i++) num[i] = 0;
	for (i = 0; i < n; i++) num[x[i] = a[i]]++;
	for (i = 1; i < m; i++) num[i] += num[i - 1];
	for (i = n - 1; i >= 0; i--) sa[--num[x[i]]] = i;
	for (j = 1, p = 1; p < n; j *= 2, m = p) {
		for (p = 0, i = n - j; i < n; i++) y[p++] = i;
		for (i = 0; i < n; i++) if (sa[i] >= j) y[p++] = sa[i] - j;
		for (i = 0; i < n; i++) tmpv[i] = x[y[i]];
		for (i = 0; i < m; i++) num[i] = 0;
		for (i = 0; i < n; i++) num[tmpv[i]]++;
		for (i = 1; i < m; i++) num[i] += num[i - 1];
		for (i = n - 1; i >= 0; i--) sa[--num[tmpv[i]]] = y[i];
		for (t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
			x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
	}
	for(i = 0; i < n; ++i) rank[sa[i]] = i;
}

void calheight(int a[], int n) {
	int i, j, k = 0;
	for (i = 0; i < n; height[rank[i++]] = k)
		for (k ? k-- : 0, j = sa[rank[i] - 1]; a[i + k] == a[j + k]; k++);
}

int solve(int n, int k) {
	int left = 0, right = 0, maxlen = 0;
	for(int i = 2; i <= n; ++i) {
		while(left < right && height[que[left]] < height[i]) {
			right --;
		}
		que[left ++] = i;
		if(que[left] + k <= i) {
			left --;
		}
		maxlen = max(maxlen, height[que[left]]);
	}
	return maxlen;
}

int main(int argc, char** argv) {
	int n, k;
	while(scanf("%d%d", &n, &k) != EOF) {
		int maxm = 0;
		for(int i = 0; i < n; ++i) {
			scanf("%d", a + i);
			a[i] ++;
			maxm = max(maxm, a[i]);
		}
		a[n] = 0;
		da(a, n + 1, maxm + 1);
		calheight(a, n);
		printf("%d\n", solve(n, k));
	}
	return 0;
}
