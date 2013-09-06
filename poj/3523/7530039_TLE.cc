#include <cstdio>
#include <cstring>
#define M 5000000
#define prime 1000007
#define N 17

char p[N][N];

struct node {
	int state, step;
	node *next;
}t[M], *h[prime];

int que[M], cnt, n, m, left, right, d[5][2] = {0, 0, 0, 1, 1, 0, 0, -1, -1, 0};

void insert(int state, int step) {
	int hash = state % prime;
	t[cnt].next = h[hash];
	t[cnt].state = state;
	t[cnt].step = step;
	h[hash] = &t[cnt++];
	que[right++] = state;
}

int inside(int state) {
	for(node *p = h[state % prime]; p; p = p->next) {
		if(state == p->state) {
			return p->step;
		}
	}
	return 0;
}

bool in(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m && p[x][y] == ' ';
}

int check(int begin, int state, int k) {
	if(k == 2) {
		int bb = begin >> 8, ba = begin & 0xff;
		int sb = state >> 8, sa = state & 0xff;
		if(sa == sb || sa == bb && sb == ba) return 0;
	} else if(k == 3) {
		int bc = begin >> 16, bb = begin >> 8 & 0xff, ba = begin & 0xff;
		int sc = state >> 16, sb = state >> 8 & 0xff, sa = state & 0xff;
		if(sa == sb || sa == sc || sb == sc) return 0;
		if(sa == bb && ba == sb || sb == bc && sc == bb || sc == ba && sa == bc) {
			return 0;
		}
	}
	int stepb = inside(begin), steps = inside(state);
	if(steps == 0) {
		insert(state, stepb + 2);
	} else if(stepb % 2 != steps % 2){
		return stepb / 2 + steps / 2 - 1;
	}
	return 0;
}

int DFS(int begin, int state, int c, int k) {
	if(c == k) {
		return check(begin, state, k);
	}
	int tp = (begin >> (c << 3)) & 0xff, x, y, nx, ny, ans;
	x = tp >> 4, y = tp & 0xf;
	for(int i = 0; i < 5; ++i) {
		nx = x + d[i][0], ny = y + d[i][1];
		if(in(nx, ny)) {
			ans = DFS(begin, state | (((nx << 4) + ny) << (c<<3)), c + 1, k);
			if(ans) return ans;
		}
	}
	return 0;
}

int solve(int k) {
	int begin = 0, end = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if('A' <= p[i][j] && p[i][j] < 'A' + k) {
				end |= ((i<<4) + j) <<((p[i][j] - 'A')<<3);
				p[i][j] = ' ';
			} else if('a' <= p[i][j] && p[i][j] < 'a' + k) {
				begin |= ((i<<4) + j) <<((p[i][j] - 'a')<<3);
				p[i][j] = ' ';
			}
		}
	}
	left = right = 0;
	cnt = 0;
	memset(h, 0, sizeof(h));
	insert(begin, 3);
	insert(end, 2);
	int step, state;
	while(left < right) {
		state = que[left++];
		if(step = DFS(state, 0, 0, k)) {
			return step;
		}
	}
	return -1;
}
int main() {
	int k;
	while(scanf("%d%d%d", &m, &n, &k), n) {
		gets(p[0]);
		for(int i = 0; i < n; ++i) {
			gets(p[i]);
		}
		printf("%d\n", solve(k));
	}
}
