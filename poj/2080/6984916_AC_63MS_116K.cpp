#include <cstdio>
#include <cstring>

char week[7][12]={
	"Sunday", "Monday", "Tuesday",
	"Wednesday", "Thursday", "Friday", "Saturday"
};

int month[2][12]={
	31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
	31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

bool is_leap(int n){
	if(n%4||!(n%100)&&(n%400)){
		return false;
	}
	return true;
}

int main(){
	int dat;
	while(scanf("%d", &dat), dat!=-1){
		int wk=6, yr=2000, mon=0, flag;
		wk=(dat+wk)%7;
		while(dat>365){
			if(is_leap(yr)){
				dat-=366;
			}
			else{
				dat-=365;
			}
			yr++;
		}
		if(dat==365&&!is_leap(yr)){
			yr++;
			dat=0;
		}
		if(is_leap(yr))flag=1;
		else flag=0;
		while(dat>=month[flag][mon]){
			dat-=month[flag][mon];
			mon++;
		}
		printf("%d-%.2d-%.2d %s\n", yr, mon+1, dat+1, week[wk]);
	}
	return 0;
}
