#include <cstdio>
#include <cstring>

char str[30002];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
	for (int i = 0; i < n; i++) {
	    scanf("%s", str+i);
	}
	int i=0, j=n-1, x, y, cnt=0;
	while (i < j) {
	    x=i, y=j;
	    while (x <= y) {
		if (str[x] == str[y]) {
		    x++;
		    y--;
		} else if (str[x] < str[y]) {
		    putchar(str[i]);
		    i++;
		    break;
		} else {
		    putchar(str[j]);
		    j--;
		    break;
		}
	    }
	    if (x > y) {
		putchar(str[i]);
		i++;
	    }
	    if (cnt%80 == 79){
		puts("");
	    }
	    cnt++;
	}
	printf("%c\n", str[i]);
    }
    return 0;
}