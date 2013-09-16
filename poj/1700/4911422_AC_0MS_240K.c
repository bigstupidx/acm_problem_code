#include<stdio.h>

int arrey[1010];

int mycompare(const void *e1,const void *e2)
{
    return *(int *)e1-*(int *)e2;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
               int i,j,n,t;
               long ans=0;
               scanf("%d",&n);
               for(i=0;i<n;i++)
                               scanf("%d",&arrey[i]);
               if(n==1){
                        printf("%d\n",arrey[0]);
                        continue;
               }
               qsort(arrey,n,sizeof(int),mycompare);
               t=arrey[0]+2*arrey[1];
               if(n%2){
				   for(i=n-1;i>2;i-=2)
					   if(t<(2*arrey[0]+arrey[i-1]))
                                          ans+=arrey[i]+t;
					   else
						   ans+=arrey[i-1]+arrey[i]+2*arrey[0];
                   ans+=(t-arrey[1]+arrey[2]);
               }
               else{
                    for(i=n-1;i>1;i-=2)
						if(t<(arrey[i-1]+2*arrey[0]))
                                       ans+=arrey[i]+t;
						else
							ans+=arrey[i]+arrey[i-1]+2*arrey[0];
                    ans+=arrey[1];
               }
               printf("%ld\n",ans);
    }
    system("pause");
    return 0;   
}
