#include <cstdio>
#include <cstdlib>
#include <cstring>

struct node{
	char str[5];
}nod[2][80];

int num[2];
char map[40][40], tem[5], str[100];

int main(){
	for(int i=0;i<17;i++){
		for(int j=0;j<33;j++){
			if(i%2){
				if(j%4){
					if((j/4+i/2)%2){
						map[i][j]=':';
					}
					else{
						map[i][j]='.';
					}
				}
				else{
					map[i][j]='|';
				}
			}
			else {
				if(j%4){
					map[i][j]='-';
				}
				else{
					map[i][j]='+';
				}
			}
		}
		map[i][33]='\0';
		//puts(map[i]);
	}
	scanf("%s", str);
	scanf("%s", str);
	
	int len=strlen(str), j=0;
	str[len]=',';
	str[++len]='\0';
	for(int i=0;i<len;i++){
		if(str[i]==','){
			for(int k=j;k<i;k++){
				tem[k-j]=str[k];
			}
			tem[i-j]=0;
			j=i+1;
			strcpy(nod[0][num[0]++].str, tem);
		}
	}
	scanf("%s", str);
	scanf("%s", str);
	len=strlen(str);j=0;
	str[len]=',';
	str[++len]='\0';
	for(int i=0;i<len;i++){
		if(str[i]==','){
			for(int k=j;k<i;k++){
				tem[k-j]=str[k];
			}
			tem[i-j]=0;
			j=i+1;
			strcpy(nod[1][num[1]++].str, tem);
		}
	}
	
	for(int i=0;i<2;i++){
		int r, c;
		for(int j=0;j<num[i];j++){
			if(i==0){
				strcpy(tem, nod[0][j].str);
				len=strlen(tem);
				if(len==3){
					r=8-(tem[2]-'0');
					c=tem[1]-'a';
					map[2*r+1][4*c+2]=tem[0];
				}
				else{
					r=8-(tem[1]-'0');
					c=tem[0]-'a';
					map[2*r+1][4*c+2]='P';
				}
			}
			else{
				strcpy(tem, nod[1][j].str);
				len=strlen(tem);
				if(len==3){
					r=8-(tem[2]-'0');
					c=tem[1]-'a';
					map[2*r+1][4*c+2]=tem[0]-'A'+'a';
				}
				else{
					r=8-(tem[1]-'0');
					c=tem[0]-'a';
					map[2*r+1][4*c+2]='p';
				}
			}
		}
	}
	
	for(int i=0;i<17;i++){
		puts(map[i]);
	}
	system("pause");
	return 0;
}
