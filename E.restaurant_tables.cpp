#include <iostream>

int main()
{
	int n, a, b;
	int c = 0;
	int ans = 0;
	scanf("%d %d %d ", &n , &a , &b);
	for ( int i = 0 ; i < n ; i++){
		int x;
		scanf("%d",&x);
		if ( x == 1 ){
			if ( a > 0 ){
				a--;
			}
			else if ( b > 0 ){
				b--;
				c++;
			}
			else if ( c > 0 ){
				c--;
			}
			else{
				ans++;
			}
		}
		else{
			if ( b > 0){
				b--;
			}
			else ans += 2;
		}
	}
	printf("%d\n", ans);
}