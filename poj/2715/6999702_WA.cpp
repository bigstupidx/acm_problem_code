#include <cstdio>
#include <cstring>

const double eps=1e-5;
long double bx, by, wx, wy;

int main(){
	int b, c, w;
	while(scanf("%d%d%d", &b, &w, &c), b||w||c){
		bx=b;
		by=0;
		wx=0;
		wy=w;
		int cnt=0;
		long double radio1=1.0*b/w, x, y, radio2=1.0*w/b;
		//printf("%lf %lf\n", radio1, radio2);
		do{
			cnt++;
			x=c*bx/(b*16);
			y=c*by/(b*16);
			bx-=x;
			by-=y;
			wx+=x;
			wy+=y;
			//printf("%.4lf %.4lf ", x,y);
			x=c*(wx)/(w*16+c);
			y=c*(wy)/(w*16+c);
			wx-=x;
			wy-=y;
			bx+=x;
			by+=y;
			//printf("%.4lf %.4lf \n", x,y);
			//printf("%lf %lf\n", by/bx, wx/wy);
			//getchar();
		}while(radio2-by/bx>eps||radio1-wx/wy>eps);
		printf("%d\n", cnt);
	}
	return 0;
}
