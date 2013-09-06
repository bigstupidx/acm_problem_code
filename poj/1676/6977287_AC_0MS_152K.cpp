#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

char g[10][3][4]={
	" _ ", "| |", "|_|",
	"   ", "  |", "  |",
	" _ ", " _|", "|_ ",
	" _ ", " _|", " _|",
	"   ", "|_|", "  |",
	" _ ", "|_ ", " _|",
	" _ ", "|_ ", "|_|",
	" _ ", "  |", "  |",
	" _ ", "|_|", "|_|",
	" _ ", "|_|", " _|"
};

char str[3][30];
vector<int>num[10], cl[2];

bool check(int jj,int ii){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(str[i][ii+j]!=' '&&str[i][ii+j]!=g[jj][i][j]){
				return false;
			}
		}
	}
	return true;
}

void get_time(int ii, int y){
	for(int i=0;i<num[ii].size();i++){
		if(num[ii][i]>2)break;
		for(int j=0;j<num[ii+1].size();j++){
			if(num[ii][i]==2&&num[ii+1][j]>3)break;
			for(int k=0;k<num[ii+2].size();k++){
				if(num[ii+2][k]>5)break;
				for(int l=0;l<num[ii+3].size();l++){
					int tt=(num[ii][i]*10+num[ii+1][j])*60+num[ii+2][k]*10+num[ii+3][l];
					cl[y].push_back(tt);
				}
			}
		}
	}
}

int main(){
	int nca;
	scanf("%d", &nca);getchar();
	while(nca--){
		
		cl[0].clear();
		cl[1].clear();
		for(int i=0;i<8;i++){
			num[i].clear();
		}
		for(int i=0;i<3;i++){
			gets(str[i]);
		}
		for(int i=0;i<25;i++){
			if(i<12&&i%3==0||i>12&&i%3==1){
				for(int j=0;j<10;j++){
					if(check(j,i)){
						num[i/3].push_back(j);
					}
				}
			}
		}
		get_time(0,0);
		get_time(4,1);
		int tim, cnt=0;
		for(int i=0;i<cl[0].size();i++){
			for(int j=0;j<cl[1].size();j++){
				if(cl[0][i]==cl[1][j]+15||cl[0][i]+1425==cl[1][j]){
					cnt++;
					tim=cl[0][i];
					//printf("%.2d%d\n", tim/60, tim%60);
				}
			}
		}
		if(cnt!=1)puts("Not Sure");
		else
			printf("%.2d%.2d\n", tim/60,tim%60);
	}
	return 0;
}
