#include <cstdio>
#include <cstring>

int level[32010], c[32010], n;

int lowbit(int x){
    return x&(-x);
}

int get_sum(int max){
    int sum=0;
    for(int i=max; i>0;i-=lowbit(i)){
	sum+=c[i];
    }
    return  sum;
}

void my_insert(int x){
    for(int i=x;i<32010;i+=lowbit(i)){
	c[i]++;
    }
}

int main(){
    while(scanf("%d", &n)!=EOF){
	memset(c, 0, sizeof(c));
	memset(level, 0, sizeof(level));
	for(int x, y, i=0;i<n;i++){
	    scanf("%d%d", &x, &y);
	    x++;
	    level[get_sum(x)]++;
	    my_insert(x);
	}
	for(int i=0;i<n;i++){
	    printf("%d\n", level[i]);
	}
    }
    return 0;
}