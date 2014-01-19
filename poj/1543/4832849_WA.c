#include<stdio.h>
int n;
long cube[102];

void pre()
{
	int i;
	cube[1]=1;
	for(i=2;i<101;i++)
		cube[i]=i*i*i;
}
int main()
{
	int m,i,j,k;
	pre();
	scanf("%d",&n);
	if(n<6)goto end;
	for(m=6;m<=n;m++){
		
		for(i=3;i<=m-3;i++){
			if(cube[i]+cube[i+1]+cube[i+2]>cube[m])break;
		
			for(j=i+1;j<=m-2;j++){
				if(cube[i]+cube[j]+cube[j+1]>cube[m])break;
			
				for(k=j+1;k<=m-1;k++)
					if(cube[i]+cube[j]+cube[k]>cube[m])break;
					else if(cube[i]+cube[k]+cube[j]==cube[m])
						printf("Cube = %d, Triple = (%d,%d,%d)\n",m,i,j,k);
			}
		}
	}
end:return 0;
}
