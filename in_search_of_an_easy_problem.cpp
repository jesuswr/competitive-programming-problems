#include <iostream>

int main()
{
	int n;
	scanf("%d",&n);
	for( int i = 0 ; i < n; i ++)
	{
		int x;
		scanf("%d",&x);
		if ( x )
		{
			printf("HARD\n");
			return 0;
		}
	}
	printf("EASY\n");
	return 0;
}