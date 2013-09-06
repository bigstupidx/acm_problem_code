#include <cstdio>
#include <cstring>

char str[10];
int map[10][40], ans[40], tem[40];

int get_char(char ch) {
	if (ch <= '9' && ch >= '0') {
		return ch - '0';
	}
	return ch - 'a' + 10;
}

void solve() {
	memset(tem, 0, sizeof(tem));
	memset(ans, 0, sizeof (ans));
	for (int i = 31; i >= 0; i--) {
		int cnt1 = 0, cnt2 = 0, sub, j;
		for (j = 0; j < 8; j++) {
			if (map[j][i]) {
				cnt1++;
			}
			else {
				cnt2++;
			}
		}
		if ((cnt1 + tem[i]) % 2 != map[8][i]) {
			ans[i] = 1;
			sub = cnt2;
		}
		else {
			sub = cnt1;
		}
		j=i;
		sub+=tem[i];
		while(sub){
			tem[j--]+=sub%2;
			sub/=2;
		}
	}
}

int main() {
	int nca;
	scanf("%d", &nca);
	while (nca--) {
		memset(map, 0, sizeof (map));
		for (int i = 0; i < 9; i++) {
			scanf("%s", str);
			int len = strlen(str), x = 28;
			for (int j = len - 1; j >= 0; j--, x -= 4) {
				int num = get_char(str[j]), k = 3;
				while (num) {
					map[i][x + k] = num % 2;
					num /= 2;
					k--;
				}
			}
		}
		solve();
//		for (int i = 0; i < 32; i++) {
//			printf("%d ", ans[i]);
//		}
		int i=0, flag = 0;
		for(int j=0;j<8;j++){
			int k=j*4, num=0;
			for(int z=k;z<k+4;z++){
				num*=2;
				num+=ans[z];
			}
			if(num!=0){
				//printf("%d", num);
				flag=1;
				if(num<10){
					printf("%d", num);
				}
				else {
					printf("%c", num-10+'a');
				}
			}
			else {
				if(flag){
					printf("0");
				}
			}
		}
		if(!flag){
			printf("0");
		}
		puts("");
	}
	return 0;
}
