#include <cstdio>
#include <cstring>
#define MAXN 20001

int ws[MAXN], wa[MAXN], wb[MAXN], wv[MAXN];

bool cmp(int *r, int a, int b, int len){
	return r[a]==r[b]&&r[a+len]==r[b+len];
}

void da(int *r, int *sa, int n, int m){
	int *x=wa, *y=wb, *t;
	for(int i=0;i<m;i++){
		ws[i]=0;
	}
	for(int i=0;i<n;i++){
		x[i]=r[i];
		ws[r[i]]++;
	}
	for(int i=1;i<m;i++){
		ws[i]+=ws[i-1];
	}
	for(int i=n-1;i>=0;i--){
		sa[--ws[x[i]]]=i;
	}
	for(int i, j=1, p=1;p<n;j*=2, m=p){
		for(p=0, i=n-j;i<n;i++){
			y[p++]=i;
		}
		for(i=0;i<n;i++){
			if(sa[i]>=j){
				y[p++]=sa[i]-j;
			}
		}
		for(i=0;i<n;i++){
			wv[i]=x[y[i]];
		}
		for(i=0;i<m;i++){
			ws[i]=0;
		}
		for(i=0;i<n;i++){
			ws[wv[i]]++;
		}
		for(i=1;i<m;i++){
			ws[i]+=ws[i-1];
		}
		for(i=n-1;i>=0;i--){
			sa[--ws[wv[i]]]=y[i];
		}
		t=x, x=y, y=t;
		x[sa[0]]=0;
		for(p=1, i=1;i<n;i++){
			x[sa[i]]=cmp(y, sa[i-1], sa[i], j)?p-1:p++;
		}
	}
	return ;
}

int rank[MAXN], height[MAXN];
void calheight(int *r, int *sa, int n){
	for(int i=1;i<=n;i++){
		rank[sa[i]]=i;
	}
	for(int k=0, i=0;i<n;height[rank[i++]]=k){
		if(k)k--;
		for(int j=sa[rank[i]-1];;k++){
			if(r[j+k]!=r[i+k]){
				break;
			}
		}
	}
	/*
	for(int i=0;i<n;i++){
		printf("%d ", rank[i]);
	}
	puts("");
	for(int i=1;i<=n;i++){
		printf("%d %d ", i, height[i]);
	}
	puts("");
	*/
}

int r[MAXN], sa[MAXN], n;

bool check(int mid){
	int maxi, mini;
	for(int i=1;i<n;i++){
		if(height[i]>=mid){
			if(mini>sa[i]){
				mini=sa[i];
			}
			if(maxi<sa[i]){
				maxi=sa[i];
			}
		}
		else {
			maxi=sa[i];
			mini=sa[i];
		}
		if(maxi-mini>=mid){
			return true;
		}
	}
	return false;
}

void solve(){
	int lf=4, rt=n, mid;
	while(lf<=rt){
		mid=(lf+rt)/2;
		if(check(mid)){
			lf=mid+1;
		}
		else {
			rt=mid-1;
		}
	}
	if(lf>4){
		printf("%d\n", lf);
	}
	else {
		puts("0");
	}
}

int main(){
	while(scanf("%d", &n), n){
		int pre, next;
		scanf("%d", &pre);
		n--;
		for(int i=0;i<n;i++){
			scanf("%d", &next);
			r[i]=next-pre+100;
			pre=next;
		}
		r[n]=0;
		da(r, sa, n+1, 200);
		//for(int i=0;i<n;i++){
		//	printf("%d ", sa[i]);
		//}
		//puts("");
		calheight(r, sa, n);
		solve();
	}
	return 0;
}
