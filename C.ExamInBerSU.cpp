#include <iostream>
#include <algorithm>


using namespace std;

int times[101];
int timesSum[101];

int main()
{
	int n, t;
	scanf("%d %d", &n, &t);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &times[i]);
		timesSum[i] = times[i] + (i>0 ? timesSum[i-1]:0);
		//printf("%d \n", timesSum[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		if (timesSum[i]<=t)
		{
			printf("0 ");
		}
		else
		{
			sort(times, times+i, greater<int>());
			int count2 = 0;
			int count = timesSum[i];
			for (int j = 0; j < i ; ++j)
			{
				if ( count <= t ) break;
				
				count -= times[j];
				count2++;
			}
			printf("%d ", count2);
		}
	}
	printf("\n");
}
