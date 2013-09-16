#include <cstdio>
#include <cstring>

char str[102], tem[102];
int arr[30], flag[2][30], mark[102];

int main(){
    int nca;
    scanf("%d", &nca);
    getchar();
    while(nca--){
	memset(mark, 0, sizeof(mark));
	memset(flag, 0, sizeof(flag));
	for(int i=0;i<26;i++){
	    arr[i]=i+1;
	}
	gets(tem);
	int len=strlen(tem), k=0;
	for(int i=0;i<len;i++){
	    if(tem[i]!=' '){
		str[k]=tem[i];
		if(str[k]<='z'&&str[k]>='a'){
		    flag[0][str[k]-'a']=1;
		    mark[k]=1;
		}
		k++;
	    }
	}
	for(int i=0;i<k;i++){
	    if(str[i]<='z'&&str[i]>='a'){
		if(i==0){
		    if(str[1]==str[2]){
			mark[1]=mark[2]=1;
			if(str[1]=='+'){
			    flag[1][str[i]-'a']=1;
			}
			else {
			    flag[1][str[i]-'a']=-1;
			}
		    }
		}
		else {
		    if(!mark[i-2]){
			mark[i-1]=mark[i-2]=1;
			if(str[i-1]=='+'){
			    arr[str[i]-'a']++;
			}
			else {
			    arr[str[i]-'a']--;
			}
		    }
		    else {
			if(i+2<k&&str[i+1]==str[i+2]){
			    mark[i+1]=mark[i+2]=1;
			    if(str[i+1]=='-'){
				flag[1][str[i]-'a']=-1;
			    }
			    else {
				flag[1][str[i]-'a']=1;
			    }
			}
		    }
		}
	    }
	}
	int ans=0;
	char op='+';
	for(int i=0;i<k;i++){
	    if(str[i]<='z'&&str[i]>='a'){
		if(op=='+')ans+=arr[str[i]-'a'];
		else ans-=arr[str[i]-'a'];
		while(i<k&&mark[i]){
		    i++;
		}
		op=str[i];
	    }
	}
	printf("Expression: %s\n", tem);
	printf("value = %d\n", ans);
	for(int i=0;i<26;i++){
	    if(flag[0][i]){
		if(flag[1][i]==0){
		    printf("%c = %d\n", i+'a', arr[i]);
		}
		else if(flag[1][i]==-1){
		    printf("%c = %d\n", i+'a', --arr[i]);
		}
		else {
		    printf("%c = %d\n", i+'a', ++arr[i]);
		}
	    }
	}
    }
    return 0;
}