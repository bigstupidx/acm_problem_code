#include <cstdio>
#include <cstring>

char str[100], ans[100];
int flag[30];

int main(){
	while(gets(str)){
		int len=strlen(str), n=0;
		memset(flag, 0, sizeof(flag));
		flag[0]=1;
		flag['E'-'A']=1;
		flag['I'-'A']=1;
		flag['O'-'A']=1;
		flag['U'-'A']=1;
		for(int i=0;i<len;i++){
			if(str[i]<='Z'&&str[i]>='A'){
				if(!flag[str[i]-'A']){
					flag[str[i]-'A']=1;
					ans[n++]=str[i];
				}
			}
			else{
				ans[n++]=str[i];
			}
		}
		int i=0, j=n-1;
		while(i<n&&ans[i]==' ')i++;
		while(j>=0&&ans[j]==' ')j--;
		n=j-i+1;
		for(int k=i;k<=j;k++){
			ans[k-i]=ans[k];
		}
		ans[n]=0;
//		puts(ans);
		str[0]=ans[0];
		for(i=1,j=1;i<n;i++){
			if(ans[i]==' '){
				while(ans[i]==' ')i++;
				if(ans[i]<='Z'&&ans[i]>='A'){
					str[j++]=' ';
					str[j++]=ans[i];	
				}
				else{
					ans[j++]=ans[i];
				}
			}
			else{
				str[j++]=ans[i];
			}
		}
		str[j]=0;
		puts(str);
	}
	return 0;
}
