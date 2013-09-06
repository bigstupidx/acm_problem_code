#include<stdio.h>
typedef struct step{
	char a[30];
	char b[30];
	int next,prior;
}STEP;
STEP steps[350];

/*
int cmp(const void *e1,const void *e2)
{
	return strcmp(((STEP *)e1)->a,((STEP *)e2)->a);
}
*/
int main()
{
	int t,k;
	scanf("%d",&t);
	for(k=1;k<=t;k++){
		int n,i,j;
		scanf("%d",&n);
		for(i=0;i<n-1;i++){
			scanf("%s%s",steps[i].a,steps[i].b);
			steps[i].next=1000;
			steps[i].prior=1000;
		}
		/*qsort(steps,n,sizeof(steps[0]),cmp);*/
		for(i=0;i<n-1;i++)
			for(j=0;j<n-1;j++){
                if(i==j)continue;
				if(strcmp(steps[i].b,steps[j].a)==0){
					steps[i].next=j;
					steps[j].prior=i;
				}
            }
		for(i=0;i<n-1;i++)
			if(steps[i].prior==1000)
				break;
		
        printf("Scenario #%d:\n",k);
		while(steps[i].next!=1000){
			printf("%s\n",steps[i].a);
			i=steps[i].next;
		}
		printf("%s\n%s\n",steps[i].a,steps[i].b);
        if(k!=t)printf("\n");		
	}
	system("pause");
	return 0;
}
