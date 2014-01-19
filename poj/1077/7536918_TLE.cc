#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cstring>

using namespace std;

struct Qnode {
	char arr[10];
	int len;
	char ans[1010];
} now, next;

int arr[9], fic[9] = {1, 1, 2, 6, 24, 120, 720, 5140, 41120};
bool hash[500010];

bool check() {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 8; j++) {
			if (arr[j] < arr[i]) {
				cnt++;
			}
		}
	}
	return cnt % 2 == 0;
}

int Hash(char arr[]) {
	int x[9], ans = 0;
	memset(x, 0, sizeof (x));
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (arr[i] > arr[j]) {
				x[j]++;
			}
		}
	}
	for (int i = 0; i < 8; i++) {
		ans += x[i] * fic[i];
	}
	ans += ('9' - arr[8]) * fic[8];
	return ans;
}

char str[3], ch;

void solve() {
	queue <Qnode> Q;
	for (int i = 0; i < 9; i++) {
		now.arr[i] = arr[i] + '0';
	}
	now.len = -1;
	Q.push(now);
	int hh = Hash(now.arr);
	hash[hh] = true;
	while (!Q.empty()) {
		now = Q.front();
		Q.pop();
		if (strcmp("123456788", now.arr) == 0) {
			puts(now.ans);
			return;
		}
		next.len = now.len + 1;
		strcpy(next.ans, now.ans);
		strcpy(next.arr, now.arr);
		int temp = now.arr[8] - '0';
		if (temp % 3 != 0) {
			--next.arr[8];
			hh = Hash(next.arr);
			if (!hash[hh]) {
				hash[hh] = true;
				next.ans[next.len] = 'l';
				Q.push(next);
			}
			++next.arr[8];
		}
		if (temp % 3 != 2) {
			++next.arr[8];
			hh = Hash(next.arr);
			if (!hash[hh]) {
				hash[hh] = true;
				next.ans[next.len] = 'r';
				Q.push(next);
			}
			--next.arr[8];
		}
		if (temp > 2) {
			next.arr[8] -= 3;
			ch = next.arr[temp-3];
			next.arr[temp - 3] = next.arr[temp - 2];
			next.arr[temp - 2] = next.arr[temp - 1];
			next.arr[temp - 1] = ch;
			hh = Hash(next.arr);
			if (!hash[hh]) {
				hash[hh] = true;
				next.ans[next.len] = 'u';
				Q.push(next);
			}
		}
		if (temp < 6) {
			strcpy(next.arr, now.arr);
			next.arr[8] += 3;
			ch = next.arr[temp + 2];
			next.arr[temp + 2] = next.arr[temp + 1];
			next.arr[temp + 1] = next.arr[temp];
			next.arr[temp] = ch;
			hh = Hash(next.arr);
			if (!hash[hh]) {
				hash[hh] = true;
				next.ans[next.len] = 'd';
				Q.push(next);
			}
		}
	}
}

int main() {
	int k = -1;
	for (int i = 0; i < 9; ++i) {
		scanf("%s", str);
		if (str[0] == 'x') {
			arr[8] = i;
		}
		else {
			arr[++k] = str[0] - '0';
		}
	}
	//	for (int i = 0; i < 9; ++i) {
	//		printf("%d ", arr[i]);
	//	}
	if (check()) {
		memset(hash, 0, sizeof (hash));
		solve();
	}
	else {
		puts("unsolvable");
	}
	system("pause");
	return 0;
}
