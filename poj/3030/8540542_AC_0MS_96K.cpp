#include <cstdio>

int main(){
int n;
scanf("%d", &n);
for(int i = 0;i<n;i++){
int a, b, c;
scanf("%d%d%d", &a, &b, &c);
a+=c;
if(a < b)puts("advertise");
else if(a==b)puts("does not matter");
else puts("do not advertise");
}
return 0;
}