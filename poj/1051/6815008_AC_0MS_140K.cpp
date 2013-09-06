#include <cstdio>
#include <cstring>

char map[26][8]={
	".-","-...","-.-.","-..",".","..-.","--.",
	"....","..",".---","-.-",".-..","--","-.",
	"---",".--.","--.-",".-.","...","-","..-",
	"...-", ".--", "-..-", "-.--", "--.."
};
char str[120], ans[120], tem[600];
char under[5]="..--", comma[5]=".-.-", period[5]="---.", ques[5]="----";
int length[26], n, num[120];
int main()
{
	scanf("%d",&n);
	for(int ii=1;ii<=n;ii++){
		scanf("%s", str);
		int len=strlen(str),k=0;
		for(int i=0;i<len;i++){
			num[i]=4;
			if(str[i]<='Z'&&str[i]>='A'){
				int x=str[i]-'A';
				num[i]=strlen(map[x]);
				for(int j=0;j<num[i];j++){
					tem[k++]=map[x][j];
				}
			}
			else if(str[i]=='_'){
				for(int j=0;j<4;j++){
					tem[k++]=under[j];
				}
			}
			else if(str[i]=='?'){
				for(int j=0;j<4;j++){
					tem[k++]=ques[j];
				}
			}
			else if(str[i]=='.'){
				for(int j=0;j<4;j++){
					tem[k++]=period[j];
				}
			}
			else{
				for(int j=0;j<4;j++){
					tem[k++]=comma[j];
				}
			}
		}
		int sum=0;tem[k]=0;
		printf("%d: ",ii);
		for(int i=len-1;i>=0;sum+=num[i],i--){
			char temp[6];
			int x=0;
			for(int j=0;j<num[i];j++){
				temp[x++]=tem[sum+j];
			}
			temp[x]='\0';
			if(strcmp(temp, "..--")==0)
				putchar('_');
			else if(strcmp(temp, "---.")==0)
				putchar('.');
			else if(strcmp(temp, ".-.-")==0)
				putchar(',');
			else if(strcmp(temp, "----")==0)
				putchar('?');
			else{
				for(int j=0;j<26;j++){
					if(strcmp(temp, map[j])==0){
						putchar('A'+j);
						break;
					}
				}
			}
		}
		puts("");
	}
	return 0;
}
