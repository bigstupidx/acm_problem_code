#include <cstdio>
#include <cstring>

struct node{
	int x, y, z;
}nod[10010];

char str[120];

int top;

void get_num(){
	int len=strlen(str), j=0;
	str[len]=' ';
	len++;
	while(str[j]==' ')j++;
	nod[top].x=0;
	for(;j<len;j++){
		if(str[j]==' ')break;
		nod[top].x*=10;
		nod[top].x+=str[j]-'0';
	}
	while(str[j]==' ')j++;
	nod[top].y=0;
	for(;j<len;j++){
		if(str[j]==' ')break;
		nod[top].y*=10;
		nod[top].y+=str[j]-'0';
	}
	while(str[j]==' ')j++;
	nod[top].z=0;
	for(;j<len;j++){
		if(str[j]==' ')break;
		nod[top].z*=10;
		nod[top].z+=str[j]-'0';
	}
	return ;
}

bool check(int mid){
	int cnt=0;
	for(int i=0;i<top;i++){
		if(nod[i].x>mid)continue;
		int tem=nod[i].y < mid? nod[i].y: mid;
		cnt+=(tem-nod[i].x)/nod[i].z+1;
	}
	return cnt%2==0;
}

void solve(){
	int lf=1, rt=-1, mid, maxi;
	for(int i=0;i<top;i++){
		if(rt<nod[i].y){
			rt=nod[i].y;
		}
	}
	maxi=rt;
	while(lf<=rt){
		mid=(lf+rt)/2;
		if(check(mid)){
			lf=mid+1;
		}
		else {
			rt=mid-1;
		}
	}
	rt++;
	if(rt>maxi){
		puts("no corruption");
	}
	else {
		int cnt=0;
		for(int i=0;i<top;i++){
			if(nod[i].x<=rt&&nod[i].y>=rt){
				if((rt-nod[i].x)%nod[i].z==0){
					cnt++;
				}
			}
		}
		printf("%d %d\n", rt, cnt);
	}
}

int main(){
//	freopen("small.in", "r", stdin);
//	freopen("small.out", "w", stdout);
	while(gets(str)){
		top=0;
		if(strcmp(str, "")==0)continue;
		get_num();
		top++;
		while(gets(str)){
			if(strcmp(str, "")==0)break;
			get_num();
			top++;
		}
		solve();
		top=0;
	}
	if(top){
		solve();
	}
	return 0;
}
