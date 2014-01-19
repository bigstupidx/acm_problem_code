#include<stdio.h>
#include<math.h>
int arrey[100];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n,i,odd,even;
		odd=even=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",arrey+i);
			if(arrey[i]==1&&i%2)odd++;
			else if(arrey[i]==1&&!(i%2))even++;
		}
		if(n%2){printf("YES\n");continue;}
		if(fabs(odd-even)<2){printf("YES\n");continue;}
		printf("NO\n");
	}
	return 0;
}
