//double log10(double x) 返回log10x的值

#include<stdio.h>
#include<math.h>
#define pi 3.141592653589793239
#define e  2.7182818284590452354
//n! = sqrt(2*π*n) * ((n/e)^n) * (1 + 1/(12*n) + 1/(288*n*n) + O(1/n^3))
/*利用Stirling公式 n! = √2πn (n/e)^n (1+Θ( 1/n))
取n! ≈sqrt(2*pi*n)*(n/e)^n;
对n! 取10的对数log10;
得log10(n!) = log10(sqrt(2*π*n)) + n * log10(n/e);
 e = 2.7182818284590452354
pi = 3.141592653589793239*/
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
               
                            double sum;
                            int i,n;
                            scanf("%d",&n);
                            sum=log10(sqrt(2*pi*n))+n*log10(n/e);
                            printf("%d\n",(int)sum+1);
    }
    return 0;  
}
