#include <cstdio>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

char str[10002], ch;
int n, m, arr[22][12], cnt[22];

int main() {
	//freopen("in.txt", "r", stdin);
	while (scanf("%s", str), strcmp(str, "ENDOFINPUT") != 0) {
		scanf("%d", &n);
		while ((ch = getchar()) != '\n');
		for (int i = 0; i < n; i++) {
			gets(str);
			string st(str);
			istringstream in(st);
			m = 0;
			while (in >> arr[i][m])m++;
			cnt[i] = m;
		}
		int tim;
		scanf("%d", &tim);
		scanf("%s", str);
		if (tim == 0) {
			puts("0");
			continue;
		}
		int ans = 100000000;
		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = 0; j < cnt[i]; j++) {
				sum += arr[i][j];
			}
			int tem = tim % sum;
			if (tem == 0) {
				ans = 0;
				break;
			}
			sum = 0;
			for (int j = 0; j < cnt[i]; j++) {
				if (sum + arr[i][j] >= tem) {
					sum = sum + arr[i][j] - tem;
					//printf("%d\n", sum);
					if (sum < ans)ans = sum;
					break;
				}
				else sum += arr[i][j];
			}
		}
		printf("%d\n", ans);
	}
	system("pause");
	return 0;
}
