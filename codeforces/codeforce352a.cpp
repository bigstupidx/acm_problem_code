#include <cstdio>
#include <cstring>

using namespace std;

int main(){
	int n, cnt0, cnt5;
	while(scanf("%d", &n)!=EOF){
		cnt0 = 0;
		cnt5 = 0;
		for(int i = 0, temp;i<n;i++){
			scanf("%d", &temp);
			if(temp==5)++cnt5;
			else if(temp==0)++cnt0;	
		}
		
		if(cnt5>=9){
			if(cnt0==0){
				puts("-1");
			}else{
				for(int i = 0, m = (cnt5/9)*9;i<m;i++){
					putchar('5');
				}
				for(int i = 0;i<cnt0;i++){
					putchar('0');
				}
				puts("");
			}
		}else{
			cnt0==0?puts("-1"):puts("0");
		}
	}
	return 0;
}
