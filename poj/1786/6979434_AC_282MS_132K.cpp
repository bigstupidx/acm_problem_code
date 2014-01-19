#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

char map[5]="CDSH", charnum[20]="  23456789TJQKA";
struct node{
	int suit;
	int num;
	bool operator <(const node &a)const{
		if(a.suit==suit){
			return a.num > num;
		}
		return a.suit > suit;
	}
}now;
vector<node>player[4];

int get_id(char ch){
	if(ch=='S')
		return 0;
	if(ch=='W')
		return 1;
	if(ch=='N')
		return 2;
	return 3;
}

int get_suit(char ch){
	if(ch=='C')
		return 0;
	if(ch=='D')
		return 1;
	if(ch=='S')
		return 2;
	return 3;
}

int get_num(char ch){
	if(ch<='9'&&ch>='0')
		return ch-'0';
	if(ch=='T')
		return 10;
	if(ch=='J')
		return 11;
	if(ch=='Q')
		return 12;
	if(ch=='K')
		return 13;
	return 14;
}

void my_output(){
	for(int i=0;i<4;i++){
		sort(player[i].begin(), player[i].end());
	}
	/*
	for(int i=0;i<4;i++){
		for(int j=0;j<13;j++){
			printf("%d %.2d  ", player[i][j].suit, player[i][j].num);
		}
		puts("");
	}
	*/
	for(int i=0;i<4;i++){
		if(i==0)printf("South ");
		else if(i==1)printf("West ");
		else if(i==2)printf("North ");
		else printf("East ");
		puts("player:");
		for(int j=0;j<5;j++){
			if(j==0||j==4){
				putchar('+');
				for(int k=0;k<13;k++){
					printf("---+");
				}
				puts("");
			}
			else {
				putchar('|');
				if(j==2){
					for(int k=0;k<13;k++){
						printf(" %c |", map[player[i][k].suit]);
					}
					puts("");
				}
				else{
					for(int k=0;k<13;k++){
						char ch= charnum[player[i][k].num];
						printf("%c %c|", ch, ch);
					}
					puts("");
				}
			}
		}
	}
	return ;
}

int main(){
	char str[4], suit, num, flag=0;
	while(scanf("%s", str), strcmp(str, "#")!=0){
		if(flag)puts("");
		else flag=1;
		int ppl=get_id(str[0]);
		for(int i=0;i<4;i++){
			player[i].clear();
		}
		ppl=(ppl+1)%4;
		for(int i=0;i<52;i++){
			while(scanf("%c", &suit), suit==' '||suit=='\n');
			while(scanf("%c", &num), num==' '||suit=='\n');
			now.suit=get_suit(suit);
			now.num=get_num(num);
			player[ppl].push_back(now);
			ppl=(ppl+1)%4;
		}
		my_output();
	}
	return 0;
}
