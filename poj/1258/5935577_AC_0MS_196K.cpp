#include<stdio.h>
int n,map[102][102],closed[102];

int Prim()
{
	int  ans = 0;
	for ( int i = 0; i < n; i ++ )
		closed[i] = map[0][i];
	for ( int j = 1; j < n; j ++ )
	{
        int i,  k,  mini = 1000000000;
		for ( i = 0;i < n; i ++ )
			if ( closed[i] && mini > closed[i] ) {
				k = i;
                mini = closed[i];
			}
		ans += mini;
		closed[k] = 0;
		for ( i = 0; i < n; i ++ )
			if ( closed[i] && map[k][i] < closed[i] )
				closed[i] = map[k][i];
	}
	return ans;
}
int main()
{
	while ( scanf("%d", &n ) != EOF ) {
		for ( int i = 0; i < n; i ++ )
			for ( int j = 0;j < n; j ++ )
				scanf("%d", map[i] + j );
		printf("%d\n", Prim( ) );
	}
	return 0;
}
