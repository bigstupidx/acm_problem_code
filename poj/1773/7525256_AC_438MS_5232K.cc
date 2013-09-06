#include <cstdio>
#include <map>
#include <string>
#include <cstring>

using namespace std;

int flag[400010], n;
char name[20], str[100010], ch;

int get_num(int len) {
	int ans = 0;
	for (int i = 1; i < len; i++) {
		ans *= 10;
		ans += str[i] - '0';
	}
	return ans;
}

void solve() {
	map <string, int> mp;
	map <string, int> ::iterator p;

	memset(flag, -1, sizeof (flag));

	for (int d, i = 0; i < n; i++) {
		scanf("%s%d", name, &d);
		mp.insert(make_pair(name, d));
	}

	while ((ch = getchar()) != '\n');

	gets(str);
	int len = strlen(str);
	if (str[0] == '#' && str[1] == '-')return;
	int inpot = get_num(len), xflag = 0, yflag = -1;

	while (gets(str)) {
		len = strlen(str);
		if (!xflag) {
			//			puts("");
			//			printf("%d %d %s\n", inpot, xflag, str);
			if (str[0] == '#') {
				if (str[1] == '-')return;
				yflag = inpot;
				inpot = get_num(len);
			}
			else if (str[0] == 'T' && str[1] == 'O' && str[2] == ':') {
				for (int i = 3; i < len; i++) {
					name[i - 3] = str[i];
				}
				name[len - 3] = 0;
				p = mp.find(name);
				if (p == mp.end()) {
					if (yflag != inpot) {
						yflag = inpot;
						printf("#%d\n", inpot);
					}
					puts("301");
				}
				else {
					if (p->second == inpot) {
						if (inpot != yflag) {
							yflag = inpot;
							printf("#%d\n", inpot);
						}
						puts("303");
					}
					else {
						if (flag[inpot] != -1) {
							if (flag[inpot] != 0) {
								if (yflag != flag[inpot]) {
									yflag = flag[inpot];
									printf("#%d\n", flag[inpot]);
								}
								puts("QUIT");
							}
						}
						flag[inpot] = p->second;
						if (p->second == 0) {
							if (yflag != inpot) {
								yflag = inpot;
								printf("#%d\n", inpot);
							}
							puts("101");
						}
						else {
							if (yflag != p->second) {
								yflag = p->second;
								printf("#%d\n", p->second);
							}
							puts(str);
							if (yflag != inpot) {
								yflag = inpot;
								printf("#%d\n", inpot);
							}
							puts("100");
						}
					}
				}
			}
			else if (strcmp(str, "DATA") == 0) {
				xflag = 1;
				if (flag[inpot] == -1) {
					if (inpot != yflag) {
						yflag = inpot;
						printf("#%d\n", inpot);
					}
					puts("302");
					continue;
				}
				else {
					if (flag[inpot] == 0) {
						if (yflag != inpot) {
							yflag = inpot;
							printf("#%d\n", inpot);
						}
						puts("101");
					}
					else {
						if (yflag != flag[inpot]) {
							yflag = flag[inpot];
							printf("#%d\n", flag[inpot]);
						}
						puts("DATA");
					}
				}
			}
			else if (strcmp(str, "QUIT") == 0) {
				if (flag[inpot] == -1) {
					if (yflag != inpot) {
						yflag = inpot;
						printf("#%d\n", inpot);
					}
					puts("302");
				}
				else {
					if (flag[inpot] > 0) {
						if (yflag != flag[inpot]) {
							yflag = flag[inpot];
							printf("#%d\n", flag[inpot]);
						}
						puts("QUIT");
						printf("#%d\n200\n", inpot);
						yflag = inpot;
					}
					else {
						if (yflag != inpot) {
							yflag = inpot;
							printf("#%d\n", inpot);
						}
						puts("200");
					}
					flag[inpot] = -1;
				}
			}
			else {
				if (yflag != inpot) {
					yflag = inpot;
					printf("#%d\n", inpot);
				}
				puts("300");
			}
		}
		else {
			if (flag[inpot] > 0)puts(str);
			if (str[len - 1] == '.') {
				int cnt = 0;
				for (int i = len - 2; i >= 0; i--) {
					if (str[i] == '\\')cnt++;
					else break;
				}
				if (cnt % 2 == 0) {
					xflag = 0;
					if (flag[inpot] < 1)continue;
					yflag = inpot;
					printf("#%d\n100\n", inpot);
				}
			}
		}
	}
}

int main() {
	//freopen("out.txt", "w", stdout);
	while (scanf("%d", &n), n) {
		solve();
		puts("#-1");
	}
	return 0;
}
