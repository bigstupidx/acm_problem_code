#include <cstdio>
#include <cstring>
#define maxn 200010

using namespace std;

int wa[maxn], wb[maxn], wv[maxn], ws[300];

bool cmp(int *r, int a, int b, int l){
	return r[a]==r[b]&&r[a+l]==r[b+l];
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
	for(int p=1, i, j=1;p<n;m=p, j*=2){
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
		for(i=1,p=1;i<n;i++){
			x[sa[i]]=cmp(y, sa[i-1], sa[i], j)?p-1:p++;
		}
	}
	return ;
}

int rank[maxn], height[maxn];

void calheight(int *r, int *sa, int n){
	for(int i=1;i<=n;i++){
		rank[sa[i]]=i;
	}
	for(int k=0, i=0;i<n;height[rank[i++]]=k){
		if(k)k--;
		for(int j=sa[rank[i]-1];;k++){
			if(r[i+k]!=r[j+k]){
				break;
			}
		}
	}
}

char str[maxn];
int r[maxn], sa[maxn];

int main(){
	while(scanf("%s", str)!=EOF){
		int len=strlen(str), n;
		str[len]='#';
		n=len;
		scanf("%s", str+len+1);
		len=strlen(str);
//		puts(str);
		for(int i=0;i<len;i++){
			r[i]=str[i];
		}
		r[len]=0;
		da(r, sa, len+1, 300);
		calheight(r, sa, len);
		/*
		for(int i=0;i<=len;i++){
			printf("%d ", sa[i]);
		}
		puts("");
		for(int i=0;i<len;i++){
			printf("%d ", rank[i]);
		}
		puts("");
		for(int i=1;i<=len;i++){
			printf("%d ", height[i]);
		}
		puts("");
		*/
		int ans=-1;
		for(int i=1;i<=len;i++){
			if(height[i]>ans){
				if(sa[i-1]<n&&sa[i]>n||sa[i]<n&&sa[i-1]>n){
					ans=height[i];
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
