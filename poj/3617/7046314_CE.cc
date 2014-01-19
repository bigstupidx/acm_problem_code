#include <cstdio>
#include <cstring>

char str[30002], tem[3];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
	getchar();
	for (int i = 0; i < n; i++) {
	    str[i] = getchar();
	    getchar();
	}
	int front = 0, tail = n - 1, cnt = 0;
	while (front < tail) {
	    int i = front, j = tail;
	    while (i < j) {
		if (str[i] == str[j]) {
		    i++;
		    j--;
		} else if (str[i] < str[j]) {
		    putchar(str[front]);
		    front++;
		    break;
		} else {
		    putchar(str[tail]);
		    tail--;
		    break;
		}
	    }
	    if (i == j) {
		putchar(str[front]);
		front++;
	    }
	    if (++cnt == 80)puts("");
	}
	printf("%c\n", str[front]);
    }
    return 0;
}`