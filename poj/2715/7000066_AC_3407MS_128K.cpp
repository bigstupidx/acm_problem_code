#include <cstdio>
#include <cmath>
#include <cstring>

const double eps=1e-5;

int main(){
	int b, w, c;
	while(scanf("%d%d%d", &b, &w, &c), b||w||c){
		b*=16;
		w*=16;
		double radio=b*1.0/w;
		double radio1=1.0, radio2=0;
		double paint=b;
		int cnt=0;
		do{
			cnt++;
			paint=(b*c+w*(paint-radio1*c))/(w+c);
			radio1=paint/b;
			radio2=(b-paint)/w;
			//printf("%lf %lf %lf\n", paint, radio1, radio2);
			//getchar();
		}while(fabs(radio1/(1-radio1)-radio)>eps||fabs(radio2/(1-radio2)-radio)>eps);
		printf("%d\n", cnt);
	}
	return 0;
}
