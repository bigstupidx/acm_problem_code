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
			temp=(lz+y)*(lz+y)+(lz-z+x)*(lz-z+x);
			if(temp<ans)ans=temp;
			temp=(ly+z)*(ly+z)+(x-y+ly)*(x-y+ly);
			if(temp<ans)ans=temp;
		}
		else if(ly==y){
			ans=(y+z)*(y+z)+x*x;
			temp=(y+x)*(y+x)+z*z;
			if(temp<ans)
				ans=temp;
			temp=(x+lz)*(x+lz)+(lz-z+y)*(lz-z+y);
			if(temp<ans)ans=temp;
			temp=(z+lx)*(z+lx)+(lx-x+y)*(lx-x+y);
			if(temp<ans)ans=temp;
		}
		else {
			ans=(x+z)*(x+z)+y*y;
			temp=(z+y)*(z+y)+x*x;
			if(temp<ans)
				ans=temp;
			temp=(x+ly)*(x+ly)+(z-y+ly)*(z-y+ly);
			if(temp<ans)ans=temp;
			temp=(lx+y)*(lx+y)+(lx-x+z)*(lx-x+z);
			if(temp<ans)ans=temp;
		}
		printf("%d\n",ans);
	}
}