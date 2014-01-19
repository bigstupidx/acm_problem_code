#include<stdio.h>
int main(){
    int i=1;
    float a,b;
    while(1){
             scanf("%f",&a);
             if(a==999)break;
             if(i){
                   scanf("%f",&b);
                   if(b==999)break;
                   printf("%.2f\n",b-a); i=0;
                   continue;  
             }
             printf("%.2f\n",a-b);
             b=a;
    }
    printf("End of Output\n");
    return 0;
}
             
             
