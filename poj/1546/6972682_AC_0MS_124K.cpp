#include <cstdio>
#include <cstring>

char str[120];
__int64 base1, base2, num, tem, fi;
int main(){
	while(scanf("%s", str)!=EOF){
		int len=strlen(str);
		fi = 1; num = 0;
		scanf("%I64d%I64d", &base1, &base2);
		for(int i=len-1; i>=0; i--){
			if(str[i]>='A'){
				num+=(str[i]-'A'+10)*fi;
			}
			else{
				num+=(str[i]-'0')*fi;
			}
			fi*=base1;
		}
	//	printf("%d\n", num);
		int j=6;
		str[7]='\0';
		while(num && j >= 0){
			tem = num % base2;
			if(tem>9){
				str[j]='A'+tem-10;
			}
			else{
				str[j]='0'+tem;
			}
			num/=base2;
			j--;
		}
		if(num)
			puts("  ERROR");
		else if(j==6)
			puts("      0");
		else{
			j++;
			for(int i=0;i<j;i++)
				putchar(' ');
			puts(str+j);
		}
	}
	return 0;
}
