int main ()
{
int i ;
int    s ;
int sum ;
scanf ( "%d" , &s ) ;
for ( sum = 1 , i = 1 ; sum < s || sum > s && ( sum - s ) % 2 ; i ++ , sum += i ) ;
printf ( "%d\n" , i ) ;
return 0 ;
}