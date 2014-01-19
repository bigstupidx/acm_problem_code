#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
const int MAX_SIZE = 510;

class node {
public:
	int x, y;
	int state;
	int step;
	node(int x, int y, int state, int step) : x(x), y(y), state(state), step(step) {}
};

char mp[MAX_SIZE][MAX_SIZE];
bool mk[MAX_SIZE][MAX_SIZE][3];
int n, m;

bool search(queue <node> &q) {
	int x, y;
	while (!q.empty()) {
		if (q.front().state == 0) {
			for (int d = 0; d < 4; ++d) {
				x = q.front().x + dx[d];
				y = q.front().y + dy[d];
				if (mp[x][y] != '#') {
					if (d == 0) {
						if (!mk[x][y][2]) {
							mk[x][y][2] = 1;
							q.push(node(x, y, 2, q.front().step + 1));
						}
					} else if (d == 1) {
						if (!mk[x][y - 1][2]) {
							mk[x][y - 1][2] = 1;
							q.push(node(x, y - 1, 2, q.front().step + 1));
						}
					} else if (d == 2) {
						if (!mk[x][y][1]) {
							mk[x][y][1] = 1;
							q.push(node(x, y, 1, q.front().step + 1));
						}
					} else {
						if (!mk[x - 1][y][1]) {
							mk[x - 1][y][1] = 1;
							q.push(node(x - 1, y, 1, q.front().step + 1));
						}
					}
				}
			}
		} else if (q.front().state == 1) {
			for (int d = 0; d < 2; ++d) {
				x = q.front().x;
				y = q.front().y + dy[d];
				if (mp[x][y] != '#' && mp[x + 1][y] != '#' && !mk[x][y][1]) {
					mk[x][y][1] = 1;
					q.push(node(x, y, 1, q.front().step + 1));
				}
			}
			y = q.front().y;
			x = q.front().x - 1;
			if (mp[x][y] != '#' && mp[x][y] != 'E' && !mk[x][y][0]) {
				if (mp[x][y] == 'O') {
					printf("%d\n", q.front().step + 1);
					return 1;
				}
				mk[x][y][0] = 1;
				q.push(node(x, y, 0, q.front().step + 1));
			}
			x = q.front().x + 2;
			if (mp[x][y] != '#' && mp[x][y] != 'E' && !mk[x][y][0]) {
				if (mp[x][y] == 'O') {
					printf("%d\n", q.front().step + 1);
					return 1;
				}
				mk[x][y][0] = 1;
				q.push(node(x, y, 0, q.front().step + 1));
			}
		} else {
			for (int d = 2; d < 4; ++d) {
				x = q.front().x + dx[d];
				y = q.front().y;
				if (mp[x][y] != '#' && mp[x][y + 1] != '#' && !mk[x][y][2]) {
					mk[x][y][2] = 1;
					q.push(node(x, y, 2, q.front().step + 1));
				}
			}
			x = q.front().x;
			y = q.front().y - 1;
			if (mp[x][y] != '#' && mp[x][y] != 'E' && !mk[x][y][0]) {
				if (mp[x][y] == 'O') {
					printf("%d\n", q.front().step + 1);
					return 1;
				}
				mk[x][y][0] = 1;
				q.push(node(x, y, 0, q.front().step + 1));
			}
			y = q.front().y + 2;
			if (mp[x][y] != '#' && mp[x][y] != 'E' && !mk[x][y][0]) {
				if (mp[x][y] == 'O') {
					printf("%d\n", q.front().step + 1);
					return 1;
				}
				mk[x][y][0] = 1;
				q.push(node(x, y, 0, q.front().step + 1));
			}
		}
		q.pop();
	}
	return 0;
}

int main() {
	while (scanf("%d%d", &n, &m), n && m) {
		queue <node> q;
		memset(mk, 0, sizeof(mk));
		for (int i = 1; i <= n; ++i) scanf("%s", mp[i] + 1);
		int cnt = 0, x, y;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (mp[i][j] == 'X') {
					mp[i][j] = '.';
					x = i; y = j;
					++cnt;
				}
			}
		}
		if (cnt == 1) {
			mk[x][y][0] = 1;
			q.push(node(x, y, 0, 0));
		} else {
			if (mp[x + 1][y]) {
				mk[x][y][1] = 1;
				q.push(node(x, y, 1, 0));
			} else if (mp[x - 1][y]) {
				mk[x - 1][y][1] = 1;
				q.push(node(x - 1, y, 1, 0));
			} else if (mp[x][y + 1]) {
				mk[x][y][2] = 1;
				q.push(node(x, y, 2, 0));
			} else {
				mk[x][y - 1][2] = 1;
				q.push(node(x, y - 1, 2, 0));
			}
		}
		if (!search(q)) puts("Impossible");
	}
	return 0;
}
