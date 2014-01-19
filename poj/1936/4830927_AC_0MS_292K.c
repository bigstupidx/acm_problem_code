#include<stdio.h>
#define MAX 100010
char a[MAX],b[MAX];	
int main()
{
	while(scanf("%s%s",a,b)==2){
		int i,j;
		int lena,lenb;
		lena=strlen(a);
		lenb=strlen(b);
		if(lena>lenb)printf("No\n");
		else{
			for(i=0,j=0;i<lena&&j<lenb;j++)
				if(a[i]==b[j])i++;
			if(i==lena)printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}