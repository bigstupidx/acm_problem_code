#include <cstdio>
#include <cstring>

char ch, str[10010];
double uu, ii, pp;

double get_num(int start) {
	double ans = 0, k = -1;
	for (int i = start; str[i] != 'W' && str[i] != 'A' && str[i] != 'V'; i++) {
		if (str[i] == '.')k = 1;
		else if (str[i] <= '9' && str[i] >= '0') {
			if (k != -1)k *= 10;
			ans = ans * 10 + str[i] - '0';
		}
		else ch = str[i];
	}
	if (k != -1)ans /= k;
	if (ch == 'm')ans /= 1000;
	else if (ch == 'k')ans *= 1000;
	else if (ch == 'M')ans *= 1000000;
	return ans;
}

void solve(int &uflag, int &iflag, int &pflag) {
	int len = strlen(str);
	for (int j, i = 0; i < len; i++) {
		if (str[i] == '=') {
			if (str[i - 1] == 'P') {
				pflag = 1;
				pp = get_num(i + 1);
			}
			else if (str[i - 1] == 'I') {
				iflag = 1;
				ii = get_num(i + 1);
				//printf("II: %d %.2lf\n", k, ii);
			}
			else {
				uflag = 1;
				uu = get_num(i + 1);
				//printf("UU: %d %.2lf\n", k, uu);
			}
		}
	}
}

int main() {
	int nca;
	scanf("%d", &nca);
	while ((ch = getchar()) != '\n');
	for (int i = 1; i <= nca; i++) {
		int uflag = 0, iflag = 0, pflag = 0;
		gets(str);
		solve(uflag, iflag, pflag);
		printf("Problem #%d\n", i);
		if (!uflag) {
			printf("U=%.2fV\n", pp / ii);
		}
		else if (!iflag) {
			printf("I=%.2fA\n", pp / uu);
		}
		else {
			printf("P=%.2fW\n", uu * ii);
		}
		puts("");
	}
	return 0;
}
