#include <cstdio>
#include <cstring>

char str[30002], tem[3];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
	for (int i = 0; i < n; i++) {
	    scanf("%s", tem);
	    str[i]=tem[0];
	}
	int front=0, tail=n-1, cnt=0;
	while(front<tail){
	    if(str[front]<str[tail]){
		printf("%c", str[front]);
		front++;
	    }
	    else if(str[front]>str[tail]){
		printf("%c", str[tail]);
		tail--;
	    }
	    else {
		int i=front+1, j=tail-1;
		while(i<=j){
		    if(str[i]>str[j]){
			printf("%c", str[tail]);
			tail--;
			break;
		    }
		    else if(str[i]< str[j]){
			printf("%c", str[front]);
			front++;
			break;
		    }
		    i++;
		    j--;
		}
		if(i>j){
		    printf("%c", str[front]);
		    front++;
		}
	    }
	    if(++cnt==80){
		cnt=0;
		puts("");
	    }
	}
	printf("%c\n", str[front]);
    }
    return 0;
}