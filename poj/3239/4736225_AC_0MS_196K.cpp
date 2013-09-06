#include<iostream>

using namespace std;

int main()

{

       int i,n;

       while (scanf("%d",&n),n)

       {

              if (n%6!=2&&n%6!=3)

              {

                     for (i=2;i<=n;i+=2)

                            printf("%d ",i);

                     for (i=1;i<n-1;i+=2)

                            printf("%d ",i);

                     printf("%d\n",i);

              }

              else

                     if ((n/2)&1)

                     {

                            for (i=n/2;i<n;i+=2)

                                   printf("%d ",i);

                            for (i=1;i<(n/2)-1;i+=2)

                                   printf("%d ",i);

                            for (i=n/2+3;i<=n;i+=2)

                                   printf("%d ",i);

                            for (i=2;i<n/2;i+=2)

                                   printf("%d ",i);

                            printf("%d\n",i);

                     }

                     else

                     {

                            for (i=n/2;i<=n;i+=2)

                                   printf("%d ",i);

                            for (i=2;i<(n/2)-1;i+=2)

                                   printf("%d ",i);

                            for (i=n/2+3;i<n;i+=2)

                                   printf("%d ",i);

                            for (i=1;i<n/2;i+=2)

                                   printf("%d ",i);

                            printf("%d\n",i);

                     }

       }

       return 0;

}
