#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct node{
    int num, rol, rec;
    char name[22];
    bool operator <(const node &a)const{
	if(a.rol == rol){
	    return a.num > num;
	}
	return a.rol > rol;
    }
}nod[24];

int sum[4], cnt[4], n, flag[24];
char tem[30], ch;

int get_rol(){
    if(tem[0]=='G'){
	return 0;
    }
    if(tem[0]=='D'){
	return 1;
    }
    if(tem[0]=='M'){
	return 2;
    }
    return 3;
}

int get_year(int ii){
    int year=0;
    for(int i=ii;i<ii+4;i++){
	year*=10;
	year+=tem[i]-'0';
    }
    return year;
}

char get_player(int x){
    if(x==0){
	return 'G';
    }
    if(x==1){
	return 'D';
    }
    if(x==2){
	return 'M';
    }
    return 'S';
}
bool solve(){
    sort(nod, nod+22);
    memset(cnt, 0, sizeof(cnt));
    memset(flag, 0, sizeof(flag));
    int maxi=-1, k=0, temp=-1;
    for(int i=0;i<22;i++){
	int j=nod[i].rol;
	//printf("%d %s %d %d\n", nod[i].num, nod[i].name, j, nod[i].rec);
	if(cnt[j]<sum[j]){
	    flag[i]=1;
	    cnt[j]++;
	    if(maxi<nod[i].rec){
		maxi=nod[i].rec;
		temp=nod[i].num;
		k=i;
	    }
	    else if(maxi == nod[i].rec&&temp<nod[i].num){
		temp=nod[i].num;
		k=i;
	    }
	}
    }
    for(int i=0;i<4;i++){
	if(cnt[i]<sum[i]){
	    return false;
	}
    }
    flag[k]=0;
    printf("%d %s %c\n", nod[k].num, nod[k].name, get_player(nod[k].rol));
    for(int i=0;i<22;i++){
	if(flag[i]){
	    printf("%d %s %c\n", nod[i].num, nod[i].name, get_player(nod[i].rol));
	}
    }
    return true;
}

int main(){
    sum[0]=1;
    while(scanf("%d", &n), n){
	nod[0].num=n;
	scanf("%s%s", nod[0].name, tem);
	nod[0].rol=get_rol();
	nod[0].rec=0;
	do{
	    scanf("%s%c", tem, &ch);
	    nod[0].rec+=get_year(5)-get_year(0)+1;
	}while(ch!='\n');

	for(int i=1;i<22;i++){
	    scanf("%d%s%s", &nod[i].num, nod[i].name, tem);
	    nod[i].rol=get_rol();
	    nod[i].rec=0;
	    do{
		scanf("%s%c", tem, &ch);
		nod[i].rec+=get_year(5)-get_year(0)+1;
	    }while(ch!='\n');
	}
	//for(int i=0;i<22;i++){
	//    printf("%d %s %d %d\n", nod[i].num, nod[i].name, nod[i].rol, nod[i].rec);
	//}
	scanf("%d-%d-%d", &sum[1], &sum[2], &sum[3]);
	if(!solve()){
	    puts("IMPOSSIBLE TO ARRANGE");
	}
	puts("");
    }
    return 0;
}