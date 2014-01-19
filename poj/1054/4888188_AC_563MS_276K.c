#include<stdio.h>

typedef struct PLANT{
	int x,y;
}PLANTS;
PLANTS plants[5001];

int r,c,n;

int mycompare(const void *e1,const void *e2)
{
	PLANTS *p1,*p2;
	p1=(PLANTS *)e1;
	p2=(PLANTS *)e2;
	if(p1->x==p2->x)
		return p1->y-p2->y;
	return p1->x-p2->x;
}

int binarysearch(PLANTS p)
{
	int middle ,former,last;
	former=0;last=n-1;
	while(former<=last){
		middle=(former+last)/2;
		if(plants[middle].x<p.x){
			former=middle+1;
			continue;
		}
		if(plants[middle].x>p.x){
			last=middle-1;
			continue;
		}
		if(plants[middle].y<p.y){
			former=middle+1;
			continue;
		}
		if(plants[middle].y>p.y){
			last=middle-1;
			continue;
		}
		return 1;
	}
	return 0;
}

int search(PLANTS fplant,int dx,int dy)
{
	int steps=2;
	PLANTS plant;
	plant.x=fplant.x+dx;
	plant.y=fplant.y+dy;
	while(plant.x<=r&&plant.x>=1&&plant.y<=c&&plant.y>=1){
		if(!binarysearch(plant)){
			return 0;
		}
		plant.x+=dx;
		plant.y+=dy;
		steps++;
	}
	return steps;
}

int main()
{
	int i,j;
	int max=2;
	scanf("%d%d",&r,&c);
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d",&plants[i].x,&plants[i].y);

	qsort(plants,n,sizeof(PLANTS),mycompare);

	for(i=0;i<n-2;i++)
		for(j=i+1;j<n-1;j++){
			
			int dx,dy,px,py,temp;
			
			dx=plants[j].x-plants[i].x;
			dy=plants[j].y-plants[i].y;
			px=plants[i].x-dx;
			py=plants[i].y-dy;
			if(px<=r&&px>=1&&py<=c&&py>=1)
				continue;
			if((plants[i].x+max*dx)>r)
				continue;
			py=plants[i].y+max*dy;
			if(py<1||py>c)
				continue;
			temp=search(plants[j],dx,dy);
			if(max<temp)
				max=temp;
	}
	if(max==2)max=0;
	printf("%d\n",max);
	system("pause");
	return 0;
}