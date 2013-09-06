#include <cstdio>
#include <cstring>

int n, m;
char str[1002][1002], tem[1002];

void solve(){
    int k=0;
    m=strlen(str[0]);
    for(int i=m-1;i>=0;i--){
	for(int j=n-1;j>=0;j--){
	    tem[k++]=str[j][i];
	}
    }
    k--;
    while(tem[k]=='_')k--;
    tem[k+1]='\0';
//    puts(tem);
    m=k+1;k=0;
    for(int i=0;i<m;i++){
	if(tem[i]=='_'){
	    putchar(' ');
	}
	else if(tem[i]=='\\'){
	    putchar('\n');
	}
	else {
	    putchar(tem[i]);
	}
    }
    puts("");
}

int main(){
    while(scanf("%d",&n)!=EOF){
	for(int i=0;i<n;i++){
	    scanf("%s", str[i]);
	}
	solve();
	puts("");
    }
    return 0;
}