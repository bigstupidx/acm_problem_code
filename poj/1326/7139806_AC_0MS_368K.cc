#include <cstdio>
#include <cstring>

char str[30], tem[30], mod[4];

int solve(int d){
	int ans=0;
	if(mod[0]=='F'){
		ans=2*d;
	}
	else if(mod[0]=='B'){
		ans=d+(d+1)/2;
	}
	else if(mod[0]=='Y'){
		if(d<500)ans=500;
		else ans=d;
	}
	return ans;
}

int main(){
	while(scanf("%s", str), strcmp(str, "#")!=0){
		int ans = 0, d;
		scanf("%s%d%s", tem, &d, mod);
		ans+=solve(d);
		while(scanf("%s", str), strcmp(str, "0")!=0){
			scanf("%s%d%s", tem, &d, mod);
			ans+=solve(d);
		}
		printf("%d\n", ans);
	}
	return 0;
}
