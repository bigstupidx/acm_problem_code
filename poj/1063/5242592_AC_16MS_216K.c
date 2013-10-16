#include<stdio.h>
#include<math.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n,w,b;
		int i,x;
		scanf("%d",&n);
		if(n%2){
			for(i=0;i<n;i++)
				scanf("%d",&x);
			printf("YES\n");
			continue;
		}
		w=b=0;
		for(i=0;i<n;i++){
			scanf("%d",&x);
			if(x){
				if(i%2)
					w++;
				else
					b++;
			}
		}
		if(fabs(w-b)<=1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}