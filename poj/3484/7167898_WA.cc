#include <cstdio>
#include <cstring>

struct node{
	long long x, y, z;
}nod[10010];

char str[10010];
int top;

void get_num(){
	int len=strlen(str)+1, j=0;
	nod[top].x=0;
	nod[top].y=0;
	nod[top].z=0;
	str[len-1]=' ';
	while(str[j]==' ')j++;
	for(;j<len;j++){
		if(str[j]==' ')break;
		nod[top].x*=10;
		nod[top].x+=str[j]-'0';
	}
	while(str[j]==' ')j++;
	for(;j<len;j++){
		if(str[j]==' ')break;
		nod[top].y*=10;
		nod[top].y+=str[j]-'0';
	}
	while(str[j]==' ')j++;
	for(;j<len;j++){
		if(str[j]==' ')break;
		nod[top].z*=10;
		nod[top].z+=str[j]-'0';
	}
}

bool check(long long mid, long long maxi){
	long long cnt=0;
	for(int i=0;i<top;i++){
		if(nod[i].y<mid){
			continue;
		}
		if(nod[i].x>=mid){
			cnt+=(nod[i].y-nod[i].x)/nod[i].z+1;
		}
		else {
			int tem=(mid-nod[i].x)/nod[i].z;
			if((mid-nod[i].x)%nod[i].z==0){
				cnt+=1+(nod[i].y-mid)/nod[i].z;
			}
			else {
				tem++;
				if(nod[i].y>=tem*nod[i].z){
					cnt+=(nod[i].y-tem*nod[i].z)/nod[i].z+1;
				}
			}
		}
	}
	return cnt%2==0;
}

void solve(){
	long long lf=0, rt=-1, mid;
	for(int i=0;i<top;i++){
		if(rt<nod[i].y){
			rt=nod[i].y;
		}
	}
	int maxi=rt;
	while(lf<=rt){
		mid=(lf+rt)/2;
		if(check(mid, maxi)){
			rt=mid-1;
		}
		else {
			lf=mid+1;
		}
	}
	lf--;
	if(lf==-1){
		puts("no corruption");
		return ;
	}
	int cnt=0;
	for(int i=0;i<top;i++){
		if(nod[i].x<=lf&&nod[i].y>=lf){
			if((lf-nod[i].x)%nod[i].z==0){
				cnt++;
			}
		}
	}
	printf("%lld %d\n", lf, cnt);
}

int main(){
//	freopen("big.in", "r", stdin);
//	freopen("small.out", "w", stdout);
	while(gets(str)){
		top=0;
		if(strcmp(str, "")==0)continue;
		get_num();
		top++;
		while(gets(str)){
			if(strcmp(str,"")==0)break;
			get_num();
			top++;
		}
		solve();
		top=0;
	}
	if(top)solve();
	return 0;
}
