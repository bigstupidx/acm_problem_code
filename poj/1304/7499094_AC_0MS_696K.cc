#include <cstdio>
#include <sstream>
#include <string>
#include <cstring>

using namespace std;

char str[100010];

int n, arr[22][20];

int main() {
	//freopen("small.in", "r", stdin);
	while (scanf("%s", str), strcmp(str, "ENDOFINPUT") != 0) {
		scanf("%d", &n);
		char ch;
		while ((ch = getchar()) != '\n');
		for (int i = 0; i < n; i++) {
			gets(str);
			string st(str);
			istringstream in(st);
			int m = 1;
			while (in >> arr[i][m])m++;
			arr[i][0] = m;
		}
		int tim;
		scanf("%d%s", &tim, str);
		int mini = 1000000000;
		for (int i = 0; i < n; i++) {
			int sum = 0, j;
			for (int j = 1; j < arr[i][0]; j++) {
				sum += arr[i][j];
			}
			int tem = tim % sum;
			sum = 0;
			for (int j = 1; j < arr[i][0]; j++) {
				if (sum >= tem) {
					break;
				}
				else sum += arr[i][j];
			}
			if (sum - tem < mini)mini = sum - tem;
		}
		printf("%d\n", mini);
	}
	return 0;
}
