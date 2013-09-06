#include <cstdio>
#include <cstring>

char str[102], tem[102];
int arr[30], flag[30], mark[102], visit[30];

void solve(int k) {
    for (int i = 0; i < k; i++) {
	if (str[i] <= 'z' && str[i] >= 'a') {
	    if (i == 0) {
		int j = 1;
		while (j + 1 < k && str[j] == str[j + 1]) {
		    mark[j] = mark[j + 1] = 1;
		    if (str[j] == '+') {
			flag[str[i] - 'a']++;
		    }
		    else {
			flag[str[i] - 'a']--;
		    }
		    j += 2;
		}
	    }
	    else {
		int j = i - 1, x = 0;
		while (j - 1 >= 0 && str[j] == str[j - 1]) {
		    x = 1;
		    mark[j] = mark[j + 1] = 1;
		    if (str[j] == '+') {
			++arr[str[i] - 'a'];
		    }
		    else {
			--arr[str[i] - 'a'];
		    }
		    j -= 2;
		}
		if(!x){
		    j = i + 1;
		    while (j + 1 < k && str[j + 1] == str[j]) {
			mark[j + 1] = mark[j] = 1;
			if (str[j] == '-') {
			    flag[str[i] - 'a']--;
			}
			else {
			    flag[str[i] - 'a']++;
			}
			j += 2;
		    }
		}
	    }
	}
    }
    int ans = 0;
    char op = '+';
    for (int i = 0; i < k; i++) {
	if (str[i] <= 'z' && str[i] >= 'a') {
	    if (op == '+') {
		ans += arr[str[i] - 'a'];
	    } else {
		ans -= arr[str[i] - 'a'];
	    }
	    while (i < k && mark[i]) {
		i++;
	    }
	    op = str[i];
	}
    }
    printf("value = %d\n", ans);
    for (int i = 0; i < 26; i++) {
	if (visit[i]) {
	    printf("%c = ", i + 'a');
	    printf("%d\n", arr[i]+flag[i]);
	}
    }
}

int main() {
    int nca;
    scanf("%d", &nca);
    getchar();
    while (nca--) {
	memset(mark, 0, sizeof (mark));
	memset(flag, 0, sizeof (flag));
	memset(visit, 0, sizeof (visit));
	for (int i = 0; i < 26; i++) {
	    arr[i] = i + 1;
	}
	gets(tem);
	printf("Expression: %s\n", tem);
	int len = strlen(tem), k = 0;
	for (int i = 0; i < len; i++) {
	    if (tem[i] != ' ') {
		str[k] = tem[i];
		if (str[k] <= 'z' && str[k] >= 'a') {
		    visit[str[k] - 'a'] = 1;
		    mark[k] = 1;
		}
		k++;
	    }
	}
	solve(k);
    }
    return 0;
}
