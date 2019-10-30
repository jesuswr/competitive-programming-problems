#include <iostream>

int main()
{
	long long n;
	scanf("%lld", &n);
	if ( n&1 ) printf("1\n");
	else printf("2\n");
	return 0;
}