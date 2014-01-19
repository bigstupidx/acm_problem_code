#include <cstdio>
#include <cstring>

using namespace std;

char str[102];

int main(){
	double cnt, price, ans = 0;
	while(scanf("%s %lf %lf", str, &cnt, &price)!=EOF){
		ans += cnt*price;
	}
	printf("%.1lf\n", ans);
	return 0;
}
