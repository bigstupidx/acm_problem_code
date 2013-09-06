#include <cstring>
#include <cstdio>

int gcm(int x, int y){
	if(x==0)return y;
	return gcm(y%x, x);
}

int main(){
	int x, y, a, b;
	while(scanf("%d%d%d%d", &x, &y, &a, &b)!=EOF){
		int xy = x*y/gcm(x, y);
		if(a%xy==0)
			printf("%d\n", b/xy - a/xy +1);
		else
			printf("%d\n", b/xy - a/xy);
	}
	return 0;
}
