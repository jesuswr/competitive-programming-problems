#include <iostream>
#include <algorithm>


using namespace std;

int times[2*int(1e5)+2];
int timesSum[2*int(1e5)+2];
int nose[101];

int main()
{
	int n, t;
	scanf("%d %d", &n, &t);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &times[i]);
		timesSum[i] = times[i] + (i>0 ? timesSum[i-1]:0);
		
	}
	for (int i = 0; i < 101; ++i)
	{
		nose[i] = 0;
	}
	for (int i = 0; i < n; ++i)
	{
		if (timesSum[i]<=t)
		{
			printf("0 ");
			
			nose[times[i]] ++;
		}
		else
		{
			int aux = timesSum[i] - t;
			int cont = 0;
			for (int j = 100; j >0; --j)
			{
				if (aux<=0) break;
				if (nose[j]==0) continue;
				if (aux>nose[j]*j)
				{
					cont += nose[j];
					aux = aux - nose[j]*j;
				} 
				else
				{
					if ( aux%j==0 )
					{
						cont += aux/j;
						aux = 0;
					}
					else
					{
						cont += aux/j;
						cont ++;
						aux = 0;
					}
				}
			}
			printf("%d ", cont);
			nose[times[i]]++;
		}
	}
	printf("\n");
}
