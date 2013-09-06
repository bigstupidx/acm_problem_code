#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;

struct edge{
	int to;
	edge *next;
}edg[1000010], *vert[1000010];

int n, m, val[1000010], in[1000010];
char str[120];

int get_num(int len){
	int ans=0, sign=1, i=0;
	if(str[0]=='-'){
		sign=-1;i++;
	}
	if(str[1]=='+'){
		i++;
	}
	for(;i<len;i++){
		ans*=10;
		ans+=str[i]-'0';
	}
	return ans;
}

void add_edge(int x, int y, int &top){
//	printf("%d -> %d\n", x, y);
	edge *p=&edg[++top];
	p->to=y;
	p->next=vert[x];	vert[x]=p;
}

int main(){
	int nca;
	scanf("%d", &nca);
	while(nca--){
		int top = -1;
		scanf("%d%d", &m, &n);
		memset(in, 0, sizeof(in));
		memset(vert, 0, sizeof(vert));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%s", str);
				int len=strlen(str);
				int v=i*m+j, u;
				if(str[0]=='='){
					len++;
					str[len-1]='+';
					for(int k=1, x=1;k<len;k++){
						if(str[k]=='+'){
							int row=0, col=0;
							for(int y=x;y<k;y++){
								if(str[y]<='Z'&&str[y]>='A'){
									col*=26;
									col+=str[y]-'A'+1;
								}
								else {
									row*=10;
									row+=str[y]-'0';
								}
							}
							x=k+1;
							u=(row-1)*m+col-1;
							in[v]++;
							add_edge(u, v, top);
						}
					}
					val[v]=0;
				}
				else {
					val[v]=get_num(len);
				}
			}
		}
		top=n*m;
		stack<int>S;
		for(int i=0;i<top;i++){
			if(in[i]==0){
				S.push(i);
			}
		}
		while(!S.empty()){
			int i=S.top();S.pop();
			for(edge *p=vert[i];p;p=p->next){
				val[p->to]+=val[i];
				if(--in[p->to]==0){
					S.push(p->to);
				}
			}
		}
		for(int i=0;i<n;i++){
			printf("%d", val[i*m]);
			for(int j=1;j<m;j++){
				printf(" %d", val[i*m+j]);
			}
			puts("");
		}
	}
	return 0;
}
