#include <cstdio>
#include <cstring>

char map[30], str[30];

void Mr_J(int n){
	char ch=str[n-1];
	for(int i=n-1;i>0;i--){
		str[i]=str[i-1];
	}
	str[0]=ch;
}

void Mr_C(int n){
	char ch=str[0];
	n--;
	for(int i=0;i<n;i++){
		str[i]=str[i+1];
	}
	str[n]=ch;
}

void Mr_E(int n){
	char ch;
	int m=n/2;
	for(int i=0;i<m;i++){
		if(n%2){
			ch=str[i];
			str[i]=str[i+m+1];
			str[i+m+1]=ch;
		}
		else{
			ch=str[i];
			str[i]=str[i+m];
			str[i+m]=ch;
		}
	}
}

void Mr_A(int n){
	char ch;
	for(int j=0, i=n-1;i>j;i--,j++){
		ch=str[i];
		str[i]=str[j];
		str[j]=ch;
	}
}

void Mr_P(int n){
	for(int i=0;i<n;i++){
		if(str[i]<='9'&&str[i]>='0'){
			if(str[i]=='0'){
				str[i]='9';
			}
			else{
				str[i]--;
			}
		}
	}
}

void Mr_M(int n){
	for(int i=0;i<n;i++){
		if(str[i]>='0'&&str[i]<='9'){
			if(str[i]=='9'){
				str[i]='0';
			}
			else{
				str[i]++;
			}
		}
	}
}

int main(){
	int nca;
	scanf("%d", &nca);
	while(nca--){
		int len, n;
		scanf("%s%s", map, str);
		n = strlen(str);
		len = strlen(map);
		for(int i=len-1;i>=0;i--){
			if(map[i]=='J'){
				Mr_J(n);
			}
			else if(map[i]=='C'){
				Mr_C(n);
			}
			else if(map[i]=='E'){
				Mr_E(n);
			}
			else if(map[i]=='A'){
				Mr_A(n);
			}
			else if(map[i]=='P'){
				Mr_P(n);
			}
			else {
				Mr_M(n);
			}
		}
		printf("%s\n", str);
	}
	return 0;
}
