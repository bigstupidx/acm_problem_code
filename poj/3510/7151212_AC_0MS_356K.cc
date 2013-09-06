#include <cstdio>
#include <cstring>

char str[1002];

void solve(int &flag) {
	int len = strlen(str), k = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == 'E' && str[i + 1] == 'O' && str[i + 2] == 'F') {
			flag = 1;
			break;
		}
		else if (str[i] == 'p' && str[i + 1] == 'i' && str[i + 2] == 'n' && str[i + 3] == 'k') {
			i += 3;
			printf("floyd");
		}
		else if(str[i]=='e'&&str[i+1]=='i'){
			if(i==0||i>0&&str[i-1]!='c'){
				printf("ie");
				i++;
			}
			else {
				putchar('e');
			}
		}
		else if(str[i]=='d'&&str[i+1]=='d'){
			putchar('p');
			i++;
		}
		else {
			if(str[i]==' '||str[i]<='z'&&str[i]>='a'){
				putchar(str[i]);
			}
		}
	}
	puts("");
}

int main() {
	int flag = 0;
	while (gets(str)) {
		if (flag)continue;
		solve(flag);
	}
	return 0;
}
