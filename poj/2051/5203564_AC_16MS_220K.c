#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Argus{
	int num;
	int period;
	int times;
}argu[1010];
int n,m;
int query[1010];

int mycmp(const void *e1,const void *e2)
{
	struct Argus *p1,*p2;
	p1=(struct Argus *)e1;
	p2=(struct Argus *)e2;
	return p1->num-p2->num;
}

void Adjust(int i)
{
    int j;
    int temp=query[i];
    j=i<<1;
    while (j<=n)
    {
          if (j<n && query[j]>query[j+1])
                j++;
          if (temp<=query[j])
                break;
          query[j>>1]=query[j];
          j=j<<1;
    }
    query[j>>1]=temp;
}

void HEAP()
{
	int i,j;
	for(i=n/2;i>0;i--)
		Adjust(i);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			if(query[1]==argu[j].period*argu[j].times)
				break;
		printf("%d\n",argu[j].num);
		query[1]+=argu[j].period;
		argu[j].times++;
		Adjust(1);
	}
	return ;
}
int main()
{
	char str[100];
	n=0;
	scanf("%s",str);
	while(strcmp(str,"#")!=0){
		scanf("%d%d",&argu[n].num,&argu[n].period);
		argu[n].times=1;
		n++;
		query[n]=argu[n-1].period;
		scanf("%s",str);
	}
	qsort(argu,n,sizeof(argu[0]),mycmp);
	scanf("%d",&m);
	HEAP();
	return 0;
}
