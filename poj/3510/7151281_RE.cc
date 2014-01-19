#include <cstdio>
#include <cstring>

char str[1002], tem[1002];

void solve(int &flag){
	int len=strlen(str), k;
	for(int i=0;i<len;i++){
		if(str[i]=='E'&&str[i+1]=='O'&&str[i+2]=='F'){
			flag=1;
			break;
		}
		else if(str[i]=='p'&&str[i+1]=='i'&&str[i+2]=='n'&&str[i+3]=='k'){
			tem[k++]='f';
			tem[k++]='l';
			tem[k++]='o';
			tem[k++]='y';
			tem[k++]='d';
			i+=3;
		}
		else if(str[i]=='d'&&str[i+1]=='d'){
			tem[k++]='p';
			i++;
		}
		else if(str[i]=='e'&&str[i+1]=='i'&&(i==0||i>0&&str[i-1]!='c')){
			tem[k++]='i';
			tem[k++]='e';
			i++;
		}
		else {
			tem[k++]=str[i];
		}
	}
	for(int i=0;i<k;i++){
		if(tem[i]==' '||tem[i]<='z'&&tem[i]>='a'){
			putchar(tem[i]);
		}
	}
	puts("");
}

int main(){
	int flag=0;
	while(gets(str)){
		if(flag)continue;
		solve(flag);
	}
	return 0;
}