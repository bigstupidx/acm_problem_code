#include <cstdio>
#include <cstring>

int n, arr[100010];
long long sum[100010], total;

bool judge(int mid){
	for(int i=mid;i<=n;i++){
		if(sum[i]-sum[i-mid]>total){
			return true;
		}
	}
	return false;
}

int main(){
	int nca;
	scanf("%d", &nca);
	while(nca--){
		int tem;
		scanf("%d%I64d", &n, &total);
		scanf("%d", &arr[1]);
		sum[0]=0;
		sum[1]=arr[1];
		for(int i=2;i<=n;i++){
			scanf("%d", &arr[i]);
			sum[i]=sum[i-1]+arr[i];
		}
		int lf=1, rt=n;
		while(lf<=rt){
			int mid=(lf+rt)/2;
			//printf("try mid:%d\n", mid);
			if(judge(mid))rt=mid-1;
			else lf=mid+1;
		}
		if(lf>n)lf=0;
		printf("%d\n", lf);
	}
	return 0;
}
