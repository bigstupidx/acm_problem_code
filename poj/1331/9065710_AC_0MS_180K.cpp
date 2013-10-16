#include <cstdio>
#include <cstring>


using namespace std;

int cnt[3], arr[3][100];

bool solve(int a, int b, int c, int base){
	memset(cnt, 0, sizeof(cnt));
	memset(arr, 0, sizeof(arr));
	int temp = a;
	long long aa = 0, bb  =0 , cc = 0;
	while(temp){
		arr[0][cnt[0]] = temp % 10;
		if(arr[0][cnt[0]]>=base)return false;
		temp /= 10;
		cnt[0]++;
	}
	for(int i = cnt[0]-1;i>=0;i--){
		aa *=base;
		aa += arr[0][i];
	}
	temp = b;
	while(temp){
		arr[1][cnt[1]] = temp % 10;
		if(arr[1][cnt[1]]>=base)return false;
		temp/=10;
		cnt[1]++;
	}
	for(int i =cnt[1]-1;i>=0;i--){
		bb *=base;
		bb+=arr[1][i];
	}
	temp = c;
	while(temp){
		arr[2][cnt[2]] = temp % 10;
		if(arr[2][cnt[2]]>=base)return false;
		temp/=10;
		cnt[2]++;
	
	}
	for(int i = cnt[2]-1;i>=0;i--){
		cc *=base;
		cc+= arr[2][i];
	}
	//printf(" %d %lld %lld %lld\n", base, aa, bb, cc);
	if(aa*bb==cc)return true;
	return false;
}

int main(){
	int nca;
	scanf("%d", &nca);
	while(nca--){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		bool flag = false;
		for(int i = 2;i<=16;i++){
			if(solve(a, b, c, i)){
				printf("%d\n", i);
				flag = true;
				break;
			}
		}
		if(!flag)puts("0");
	}
	return 0;
}