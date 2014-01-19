#include <cstdio>
#include <cstdlib>

int main(){
	double a= 0.9921147013144779f;
	double b = -0.12533323356430426f;
	double tx2 = 1.2533323356430426f;
	double ty2 = 9.921147013144779f;
	double tx = 16.2f;
	
	double c = 0.12533323356430426f;
	double d = 0.9921147013144779f;
	double ty = -74.0f;
	
	printf("%lf\n", a * tx + c*ty + tx2);
	printf("%lf\n", b * tx + d*ty + ty2);
	
	int n;
	scanf("%d", &n);
	
	return 0;
}
