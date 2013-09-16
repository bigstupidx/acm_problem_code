#include<stdio.h>
int main()
{
	int lx,ly,lz,x,y,z;
	while(scanf("%d%d%d%d%d%d",&lx,&ly,&lz,&x,&y,&z),lx||ly||lz||z||y||x){
		int temp,ans=0;
		if(x==0)
			ans=y*y+z*z;
		else if(y==0)
			ans=x*x+z*z;
		else if(z==0)
			ans=x*x+y*y;
		else if(x==lx&&ly==y&&lz==z){
			ans=(x+y)*(x+y)+z*z;
			temp=(y+z)*(y+z)+x*x;
			if(temp<ans)ans=temp;
			temp=(z+x)*(z+x)+y*y;
			if(temp<ans)ans=temp;
		}
		else if(lx==x){
			ans=(x+z)*(x+z)+y*y;
			temp=(x+y)*(x+y)+z*z;
			if(temp<ans)
				ans=temp;
			temp=(x+y)*(x+y)+(lz-z+ly)*(lz-z+ly);
			if(temp<ans)ans=temp;
			temp=(x+z)*(x+z)+(lz-y+ly)*(lz-y+ly);
			if(temp<ans)ans=temp;
		}
		else if(ly==y){
			ans=(y+z)*(y+z)+x*x;
			temp=(y+x)*(y+x)+z*z;
			if(temp<ans)
				ans=temp;
			temp=(x+y)*(x+y)+(lx-z+lz)*(lx-z+lz);
			if(temp<ans)ans=temp;
			temp=(z+y)*(z+y)+(lx-x+lz)*(lx-x+lz);
			if(temp<ans)ans=temp;
		}
		else {
			ans=(x+z)*(x+z)+y*y;
			temp=(z+y)*(z+y)+x*x;
			if(temp<ans)
				ans=temp;
			temp=(x+z)*(x+z)+(lx-y+ly)*(lx-y+ly);
			if(temp<ans)ans=temp;
			temp=(z+y)*(z+y)+(lx-x+ly)*(lx-x+ly);
			if(temp<ans)ans=temp;
		}
		printf("%d\n",ans);
	}
}