#include <cstdio>
#include <cstring>

char str[120], ans[200];

void solve(int &flag){
	int len=strlen(str), k=0;
	for(int i=0;i<len;i++){
		if(str[i]=='p'){
			if(i+3<len&&str[i+1]=='i'&&str[i+2]=='n'&&str[i+3]=='k'){
				ans[k++]='f';
				ans[k++]='l';
				ans[k++]='o';
				ans[k++]='y';
				ans[k++]='d';
				i+=3;
			}
			else {
				ans[k++]='p';
			}
		}
		else if(str[i]=='E'){
			if(i+2<len&&str[i+1]=='O'&&str[i+2]=='F'){
				flag=1;
				break;
			}
		}
		else {
			ans[k++]=str[i];
		}
	}
	len=k;
	k=0;
	for(int i=0;i<len;i++){
		if(i+1<len && ans[i]=='d' && ans[i+1]=='d'){
			str[k++]='p';
			i++;
		}
		else if(i+1<len && ans[i]=='e' && ans[i+1]=='i'&&(i==0||i>0&&ans[i-1]!='c')){
			str[k++]='i';
			str[k++]='e';
		}
		else {
			str[k++]=ans[i];
		}
	}
	len=k;
	for(int i=0;i<len;i++){
		if(str[i]==' '||str[i]<='z'&&str[i]>='a'){
			putchar(str[i]);
		}
	}
	puts("");
}

int main(){
	int flag = 0;
	while(gets(str)){
		if(flag)continue;
		if(strcmp(str, "EOF")==0){
			flag=1;
			continue;
		}
		solve(flag);
	}
	return 0;
}
