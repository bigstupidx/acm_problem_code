#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

char str[1010];

struct node{
	char ch;
	int cnt;
}now;

vector <node> list;

void solve(){
	int len=strlen(str);
	now.cnt=1;
	now.ch=str[0];
	for(int i=1;i<len;i++){
		if(str[i]==str[i-1]){
			now.cnt++;
		}
		else{
			list.push_back(now);
			now.ch=str[i];
			now.cnt=1;
		}
	}
	list.push_back(now);
	int top=list.size();
	for(int i=0;i<top;i++){
		if(i==0){
			if(list[0].cnt==1){
				printf("1%c", list[0].ch);
				if(list[0].ch=='1'){
					putchar('1');
				}
			}
			else{
				for(int j=0;j<list[0].cnt/9;j++){
					printf("9%c", list[0].ch);
				}
				list[0].cnt%=9;
				if(list[0].cnt){
					if(list[0].cnt>1){
						printf("%d%c", list[0].cnt, list[0].ch);
					}
					else{
						printf("1%c", list[0].ch);
						if(list[0].ch=='1'){
							putchar('1');
						}
					}
				}
			}
		}
		else{
			if(list[i].cnt==1){
				if(list[i-1].cnt==1){
					putchar(list[i].ch);
					if(list[i].ch=='1'){
						putchar('1');
					}
				}
				else{
					printf("1%c", list[i].ch);
					if(list[i].ch=='1'){
						putchar('1');
					}
				}
			}
			else{
				if(list[i-1].cnt==1){
					putchar('1');
				}
				for(int j=0;j<list[i].cnt/9;j++){
					printf("9%c", list[i].ch);
				}
				list[i].cnt%=9;
				if(list[i].cnt){
					if(list[i].cnt==1){
						printf("1%c", list[i].ch);
						if(list[i].ch=='1'){
							putchar('1');
						}
					}
					else{
						printf("%d%c", list[i].cnt, list[i].ch);
					}
				}
			}
		}
	}
	if(list[top-1].cnt==1)
		putchar('1');
	puts("");
	return ;
}

int main(){
	while(gets(str)){
		if(strcmp(str, "")==0){
			puts("");
			continue;
		}
		list.clear();
		solve();
	}
	return 0;
}
