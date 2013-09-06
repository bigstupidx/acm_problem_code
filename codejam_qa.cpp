//============================================================================
// Name        : algorithm.cpp
// Author      : wangjunyong
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

char map[30]="yhesocvxduiglbkrztnwjpfmaq";
char str[1002];

int main() {
	freopen("small.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n;
	char ch;
	while(scanf("%d%c", &n, &ch)!=EOF){
		for(int i = 0;i<n;i++){
			gets(str);
			int len = strlen(str);
			for(int j = 0;j<len;j++){
				if(str[j]<='z' && str[j]>='a'){
					printf("%c", map[str[j]-'a']);
				}else {
					printf("%c", str[j]);
				}
			}
			puts("");
		}
	}
	return 0;
}
