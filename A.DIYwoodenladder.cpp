#include <iostream>

using namespace std;

int heights[int(1e5+5)];

int main()
{
	int t;
	int n;
	scanf("%d", &t);
	while(t--) 
	{
	 	int max1 = -1, max2 = -1;
	 	scanf("%d", &n);
	 	for (int i = 0; i < n; ++i)
	 	{
	 	   	scanf("%d", &heights[i]);
	 	   	if ( heights[i] > max1 )
	 	   	{
	 	   		max2 = max1;
	 	   		max1 = heights[i];
	 	   	}
	 	   	else if ( heights[i] > max2)
	 	   	{
	 	   		max2 = heights[i];
	 	   	}
	 	}
	 	int ans = min (max1, max2);
	 	ans = min( ans - 1 , n-2);
	 	printf("%d\n", ans);   
	}
}
