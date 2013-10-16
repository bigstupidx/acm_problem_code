#include <cstdio>
#include <cstring>

char str[30002], tem[2];

int main(){
    int n;
    while(scanf("%d", &n)!=EOF){
	for(int i=0;i<n;i++){
	    scanf("%s", tem);
	    str[i]=tem[0];
	}
	int front=0, tail=n-1;
	while(front<tail){
	    if(str[front]>str[tail]){
		putchar(str[tail]);
		tail--;
	    }
	    else if(str[front]<str[tail]){
		putchar(str[front]);
		front++;
	    }
	    else {
		int i=front, j=tail;
		while(i<j){
		    if(str[i]==str[j]){
			i++;
			j--;
		    }
		    else if(str[i]<str[j]){
			putchar(str[front]);
			front++;
			break;
		    }
		    else {
			putchar(str[tail]);
			tail--;
			break;
		    }
		}
		if(i==j){
		    putchar(str[front]);
		    front++;
		}
	    }
	}
	printf("%c\n", str[front]);
    }
    return 0;
}