/*
n个coins
1.n个都是正面或反面，则最少要翻两次（同一个coin），因此答案肯定是偶数，
    由此也可知n为偶数时无解。
2.n为奇数时，则n可以表示为奇数加偶数的形式（即总有偶数！）。不失一般性，
  设有2i（i为自然数）个币是正面，则为了与结论1兼容，只能翻2i次，且翻n-1次
  可以“解”所有的情况（因为总有偶数，且对同一个coin翻两次不改变当前的situation）。
*/
#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n),n){
        if(n%2)printf("%d\n",n-1);
        else printf("No Solution!\n");
}
return 0;
}