#include <cstdio>
#include <vector>
#include <map>
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
vector<int>num[10];

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

int main(){
	int nca;
	scanf("%d", &nca);getchar();
	while(nca--){
		
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
		vector<int>cl1, cl2;
		for(int i=0;i<num[0].size();i++){
			if(num[0][i]>2)break;
			for(int j=0;j<num[1].size();j++){
				if(num[0][i]==2&&num[1][j]>3)break;
				for(int k=0;k<num[2].size();k++){
					if(num[2][k]>5)break;
					for(int x=0;x<num[3].size();x++){
						int tt=(num[0][i]*10+num[1][j])*60+num[2][k]*10+num[3][x];
						cl1.push_back(tt);
					}
				}
			}
		}
		for(int i=0;i<num[4].size();i++){
			if(num[4][i]>2)break;
			for(int j=0;j<num[5].size();j++){
				if(num[4][i]==2&&num[5][j]>3)break;
				for(int k=0;k<num[6].size();k++){
					if(num[6][k]>5)break;
					for(int x=0;x<num[7].size();x++){
						int tt=(num[4][i]*10+num[5][j])*60+num[6][k]*10+num[7][x];
						cl2.push_back(tt);
					}
				}
			}
		}
		int tim, cnt=0;
		for(int i=0;i<cl1.size();i++){
			for(int j=0;j<cl2.size();j++){
				if(cl1[i]>cl2[j]&&cl1[i]==cl2[j]+15||cl1[i]<cl2[j]&&cl1[i]+1425==cl2[j]){
					cnt++;
					tim=cl1[i];
				}
			}
		}
		if(cnt!=1)puts("Not Sure");
		else
			printf("%.2d%d\n", tim/60,tim%60);
	}
	return 0;
}
