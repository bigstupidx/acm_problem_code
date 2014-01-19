#include <cstdio>
#include <cstring>

char str[1010], ch;

int arr[26] = {
	1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4
};

int pos[26] = {
	1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8
};

int main() {
	int nca;
	scanf("%d", &nca);
	while (nca--) {
		int t1, t2;
		scanf("%d%d", &t1, &t2);
		while ((ch = getchar()) != '\n');
		gets(str);
		int len = strlen(str), ans = t1 * arr[str[0] - 'A'];
		for (int i = 1; i < len; i++) {
			if (str[i] == ' ')ans += t1;
			else {
				if (str[i - 1] != ' ') {
					if (pos[str[i] - 'A'] == pos[str[i - 1] - 'A']) {
						ans += t2;
					}
				}
				ans += t1 * arr[str[i] - 'A'];
			}
			//			printf("%d ", ans);
		}
		printf("%d\n", ans);
	}
	return 0;
}
