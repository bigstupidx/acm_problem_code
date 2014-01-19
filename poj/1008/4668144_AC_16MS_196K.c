#include<stdio.h>
#include<string.h>

char haab[19][10]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen",
              "yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
char tzolkin[20][10]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen",
              "eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};
              
int main()
{
    int t;
    scanf("%d",&t);
    printf("%d\n",t);
    while(t--){
               int days,years,i;
               char months[10];
               scanf("%d. %s%d",&days,months,&years);
               for(i=0;i<19;i++)
                                  if(!strcmp(months,haab[i]))break;
               days+=365*years+i*20;
               printf("%d %s %d\n",1+days%13,tzolkin[days%20],days/260);
    }
    return 0;
}
    
