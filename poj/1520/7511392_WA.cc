#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct alpter {
	char str[100], ss[100];
	int st;

	bool operator<(const alpter & a)const {
		return strcmp(a.ss, ss) > 0;
	}
} alp[10010];

struct number {
	int num;
	int st;

	bool operator<(const number & a)const {
		return a.num > num;
	}
} num[10010];


char str[100010], ch;
int cnt1, cnt2, m, tag[1000010], rank[1000010];

int judge(int len, int &flag) {
	int i = 0, sign = 1, ans = 0;
	if (str[0] == '-')i++, sign *= -1;
	else if (str[0] == '+')i++;
	flag = 0;
	for (; i < len; i++) {
		if (str[i] > '9' || str[i] < '0') {
			flag = 1;
			break;
		}
		ans = ans * 10 + str[i] - '0';
	}
	return ans*sign;
}

void init() {
	int len = strlen(str) - 1, flag;
	ch = str[len];
	str[len] = 0;
	int tem = judge(len, flag);
	if (flag) {
		strcpy(alp[cnt1].str, str);
		for (int i = 0; i < len; i++) {
			if (str[i] <= 'Z') {
				alp[cnt1].ss[i] += 'a' - 'A';
			}
		}
		alp[cnt1].st = m;
		tag[m++] = 1;
		cnt1++;
	}
	else {
		num[cnt2].num = tem;
		num[cnt2].st = m++;
		cnt2++;
	}
}

void solve() {
	sort(alp, alp + cnt1);
	sort(num, num + cnt2);
	for (int j = 0, k = 0, i = 0; i < m; i++) {
		if (tag[i]) {
			printf("%s", alp[j++].str);
		}
		else
			printf("%d", num[k++].num);
		if (i != m - 1)
			printf(", ");
		else
			printf(".\n");
	}
}

int main() {
	while (scanf("%s", str) != EOF) {
		if (str[0] == '.')break;
		memset(tag, 0, sizeof (tag));
		cnt1 = 0, cnt2 = 0, m = 0;
		init();
		if (ch == '.')solve();
		else {
			while (scanf("%s", str) != EOF) {
				init();
				if (ch == '.')break;
			}
			solve();
		}
	}
	return 0;
}
