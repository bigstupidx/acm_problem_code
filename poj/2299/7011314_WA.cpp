#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct node{
    int ii;
    int id;
    int x;
}nod[500002];

int n, c[500002];

bool cmp1(const node &a, const node &b){
    return a.x < b.x;
}

bool cmp2(const node &a, const node &b){
    return a.ii < b.ii;
}

int lowbit(int x){
    return (x&(-x));
}

int main(){
    while(scanf("%d", &n), n){
	for(int i=0;i<n;i++){
	    scanf("%d", &nod[i].x);
	    nod[i].ii=i;
	}
	sort(nod, nod+n, cmp1);
	nod[0].id=1;
	for(int i=1;i<n;i++){
	    if(nod[i].x==nod[i-1].x){
		nod[i].id=nod[i-1].id;
	    }
	    else {
		nod[i].id=i+1;
	    }
	}
	sort(nod, nod+n, cmp2);
	int ans=0;
	memset(c, 0, sizeof(c));
	for(int i=0;i<n;i++){
	    ans += i;
	    int j=nod[i].id;
	    while(j>0){
		ans-=c[j];
		j-=lowbit(j);
	    }
	    j=nod[i].id;
	    while(j<=n){
		c[j]++;
		j+=lowbit(j);
	    }
	}
	printf("%d\n", ans);
    }
    return 0;
}