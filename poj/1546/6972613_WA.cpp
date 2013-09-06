#include <cstdio>
#include <cstring>

char str[120];
int base1, base2, num, arr[120], tem;
int main(){
	while(scanf("%s%d%d", str, &base1, &base2)!=EOF){
		int len=strlen(str), fi;
		fi = 1; num = 0;
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
		if(j<0)
			puts("  ERROR");
		else{
			j++;
			for(int i=0;i<j;i++)
				putchar(' ');
			puts(str+j);
		}
	}
	return 0;
}
