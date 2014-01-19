#include <cstdio>
#include <cstring>

char map[12][12];
int n, m, mark[12][12], sx, sy;

int main(){
	while(scanf("%d%d%d", &n, &m, &sy), n||m||sy){
		
		for(int i=0;i<n;i++){
			scanf("%s", map[i]);
		}
		sx = 0; sy--;
		int flag = 0, step = 1, loop;
		memset(mark,0,sizeof(mark));
		while(1){
			if(map[sx][sy]=='N'){
				sx--;
			}
			else if(map[sx][sy]=='S'){
				sx++;
			}
			else if(map[sx][sy]=='W'){
				sy--;
			}
			else{
				sy++;
			}
			if(sx<0||sx==n||sy<0||sy==m)break;
			if(mark[sx][sy]){
				flag=1;
				loop=step-mark[sx][sy];
				break;
			}
			mark[sx][sy]=step++;
		}
		if(flag){
			if(step - loop == 1) step--;
			printf("%d step(s) before a loop of %d step(s)\n", step - loop, loop);
		}
		else{
			if(step==1)step--;
			printf("%d step(s) to exit\n", step);
		}
	}
	return 0;
}
