#include <cstdio>
#include <cstring>

char str[1002];
int n, par[30], in[30], out[30], flag[30];

int my_find(int x){
	if(par[x]==-1){
		return x;
	}
	return par[x]=my_find(par[x]);
}

int main(){
	int nca;
	scanf("%d", &nca);
	while(nca--){
		scanf("%d", &n);
		memset(par, -1, sizeof(par));
		memset(flag, 0, sizeof(flag));
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		for(int i=0;i<n;i++){
			scanf("%s", str);
			int len=strlen(str);
			int u=str[0]-'a';
			int v=str[len-1]-'a';
			flag[u]=flag[v]=1;
			in[v]++;	out[u]++;
			int ii=my_find(u);
			int jj=my_find(v);
			if(ii!=jj){
				par[ii]=jj;
			}
		}
		int ii, jj, xflag = 0;
		for(int i=0;i<26;i++){
			if(flag[i]){
				ii=my_find(i);
				break;
			}
		}
		for(int i=0;i<26;i++){
			if(flag[i]){
				jj=my_find(i);
				if(ii!=jj){
					xflag=1;
					break;
				}
			}
		}
		if(xflag){
			puts("The door cannot be opened.");
		}
		else {
			int cnt=0;
			for(int i=0;i<26;i++){
				if(flag[i]){
					if(in[i]!=out[i]){
						cnt++;
						if(cnt==1){
							ii=i;
						}
						else {
							jj=i;
						}
					}
				}
			}
			if(cnt!=2&&cnt!=0){
				puts("The door cannot be opened.");
			}
			else {
				if(cnt==2){
					if(in[ii]-1==out[ii]&&out[jj]-1==in[jj]||out[ii]-1==in[ii]&&in[jj]-1==out[jj]){
						puts("Ordering is possible.");
					}
					else {
						puts("The door cannot be opened.");
					}
				}
				else {
					puts("Ordering is possible.");
				}
			}
		}
	}
	return 0;
}
