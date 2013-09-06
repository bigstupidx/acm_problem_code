#include <cstdio>
#include <map>
#include <string>
#include <cstring>

using namespace std;

char dig[30], numb[40];
int flag[300], num[40], aa[1002], bb[1002];

void _multi(int base){
	int count=0;
	for(int i=0;i<1000;i++){
		bb[i]*=base;
		bb[i]+=count;
		count=bb[i]/10;
		bb[i]%=10;
	}
}

void _add(){
	int count=0;
	for(int i=0;i<1000;i++){
		aa[i]+=bb[i]+count;
		count=aa[i]/10;
		aa[i]%=10;
	}
}

void solve(int base) {
	int len = strlen(numb), k = 0;
	for (int i = 0; i < len; i++) {
		if (numb[i] != ' ') {
			numb[k++] = numb[i];
		}
	}
	len = k, k = 0;
	for (int i = 0; i < len; i++) {
		num[i] = flag[numb[i]];
		if (k < flag[numb[i]]) {
			k = flag[numb[i]];
		}
	}
	memset(aa, 0, sizeof(aa));
	for (++k; k <= base; k++) {
		memset(bb, 0, sizeof(bb));
		for (int i = 0; i < len; i++) {
			_multi(k);
			bb[0]+=num[i];
		}
		_add();
	}
	k=0;
	for(int i=1000;i>=0;i--){
		if(aa[i]){
			k=i;
			break;
		}
	}
	for(;k>=0;k--){
		printf("%d", aa[k]);
	}
	puts("");
}

int main() {
	while (gets(dig)) {
		if (strcmp(dig, "") == 0)continue;
		memset(flag, 0, sizeof (flag));
		int len = strlen(dig);
		for (int i = 0; i < len; i++) {
			flag[dig[i]] = i;
		}
		while (gets(numb)) {
			if (strcmp(numb, "") == 0)break;
			solve(len);
		}
	}
	return 0;
}
