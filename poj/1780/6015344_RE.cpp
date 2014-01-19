#include <cstdio>
#include <cstring>

int edge[1000000][10], nstates;
char out[10008576], *outp;

void dfs(int q)
{
  int i;
  /* We are in state q and press the key i. */
  for (i=0 ; i<10 ; i++)
    if (edge[q][i])
    {
      edge[q][i] = 0;
      dfs((q * 10 + i) % nstates);
      *--outp = '0' + i;
    }
}
int main()
{
  while (1)
  {
    int i, n, q;
    scanf("%d", &n);
    if (n == 0) break;
    /* There are 10^(n-1) states. */
    nstates = 1;
    for (i=1 ; i<n ; i++)
      nstates *= 10;
    //printf("nstates %d\n",nstates);
    for (q=0 ; q<nstates ; q++)
      for (i=0 ; i<10 ; i++)
        edge[q][i] = 1;
    /* We always start with pressing the 0 key n-1 times. */
    for (i=1 ; i<n ; i++)
      printf("0");
    *(outp = out + nstates*10) = 0;
    dfs(0);
    printf("%s\n", outp);
  }
  return 0;
}
