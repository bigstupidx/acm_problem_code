#include <cstdio>
#include <cstring>

char ch, str[10010];
double uu, ii, pp;
int fic[20] = {};

void solve(int &uflag, int &iflag, int &pflag) {
	int len = strlen(str);
	for (int j, k, i = 0; i < len; i++) {
		if (str[i] == '=') {
			if (str[i - 1] == 'P') {
				pflag = 1;
				pp = 0, k = -1, j = i + 1;
				for (j = i + 1; str[j] != 'W'; j++) {
					if (str[j] == '.') {
						k = 1;
					}
					if (str[j] <= '9' && str[j] >= '0') {
						if (k != -1)k *= 10;
						pp = (pp * 10) + str[j] - '0';
					}
				}
				if (str[j - 1] == 'm')pp /= 1000;
				if (str[j - 1] == 'k')pp *= 1000;
				if (str[j - 1] == 'M')pp *= 1000000;
				if (k != -1)pp /= k;
				//printf("PP: %d %.2lf\n", k, pp);
			}
			else if (str[i - 1] == 'I') {
				iflag = 1;
				ii = 0, k = -1, j = i + 1;
				for (j = i + 1; str[j] != 'A'; j++) {
					if (str[j] == '.') {
						k = 1;
					}
					if (str[j] <= '9' && str[j] >= '0') {
						if (k != -1)k *= 10;
						ii = (ii * 10) + str[j] - '0';
					}
				}
				if (str[j - 1] == 'm')ii /= 1000;
				if (str[j - 1] == 'k')ii *= 1000;
				if (str[j - 1] == 'M')ii *= 1000000;
				if (k != -1)ii /= k;
				//printf("II: %d %.2lf\n", k, ii);
			}
			else {
				uflag = 1;
				uu = 0, k = -1, j = i + 1;
				for (j = i + 1; str[j] != 'V'; j++) {
					if (str[j] == '.') {
						k = 1;
					}
					if (str[j] <= '9' && str[j] >= '0') {
						if (k != -1)k *= 10;
						uu = (uu * 10) + str[j] - '0';
					}
				}
				if (str[j - 1] == 'm')uu /= 1000;
				if (str[j - 1] == 'k')uu *= 1000;
				if (str[j - 1] == 'M')uu *= 1000000;
				if (k != -1)uu /= k;
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
			printf("U=%.2lfV\n", pp / ii);
		}
		else if (!iflag) {
			printf("I=%.2lfA\n", pp / uu);
		}
		else {
			printf("P=%.2lfW\n", uu * ii);
		}
		puts("");
	}
	return 0;
}
