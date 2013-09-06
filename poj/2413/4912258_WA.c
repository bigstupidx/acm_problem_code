#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char a[120],b[120];
char fibs[200][120];

void pre_done()
{
	int i,j,len,count=0;
	strcpy(fibs[1],"1");
	strcpy(fibs[2],"2");
	for(i=3;i<200;i++){
		len=strlen(fibs[i-1]);
		for(j=0;j<len;j++){
			int x,y;
			if(fibs[i-2][j]>'9'||fibs[i-2][j]<'0')
				x='0';
			else x=fibs[i-2][j];
			if(fibs[i-1][j]>'9'||fibs[i-1][j]<'0')
				y='0';
			else y=fibs[i-1][j];

			fibs[i][j]=x+y+count-'0';
			if(fibs[i][j]>'9'){
				count=1;
				fibs[i][j]-=10;
			}
			else count=0;
		}
		if(count==1){
			fibs[i][j]='1';count=0;
		}
	}
	/*for(i=1;i<200;i++)
		printf("%s\n",fibs[i]);*/
	return ;
}

void reversestr(char a[])
{
	int i,len,j;
	char c[120];
	len=strlen(a);
	for(j=0,i=len-1;i>=0;i--,j++)
		c[j]=a[i];
	c[j]='\0';
	strcpy(a,c);
}
int strcmpxx(char a[],char b[])
{
	int len1,len2;
	len1=strlen(a);
	len2=strlen(b);
	if(len1>len2)
		return -1;
	else if(len1<len2)
		return 1;
	else{
		int i,j;
		for(i=len1-1;i>=0;i--)
			if(a[i]==b[i])
				continue;
			else if(a[i]<b[i])
				return 1;
			else
				return -1;
		return 0;
	}
}

int main()
{
	pre_done();
	while(scanf("%s%s",a,b),(a[0]-'0')||(b[0]-'0')){
		int i,count=0;
		reversestr(a);
		reversestr(b);
		for(i=1;i<200;i++){
			if(strcmpxx(a,fibs[i])<0)
				continue;
			else if(strcmpxx(b,fibs[i])<=0)
				count ++;
			else
				break;
		}
		printf("%d\n",count);
	}
	system("pause");
	return 0;
}