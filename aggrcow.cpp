#include <iostream>
#include <algorithm>


using namespace std;


const int maxN = 100005;


int n, m, stalls[maxN];


int bs(int index, int size, int cows)
{
	//printf("%d %d %d\n",index, size, cows );
	int ans;
	int contC = cows-1;
	int contS = 0;
	for (int i = 1; i < size; ++i)
	{
		if (contC==0) break;

		contS = contS + stalls[i] - stalls[i-1] ;
		//printf("QUEDAN %d VACAS Y LLEVO %d ESPACIO\n",contC, contS );
		
		if (contS >= index)
		{
			contC--;
			contS = 0;
		}
	}
	if (contC==0) return 1;
	return -1;
}


int main()
{
	int t;
	scanf("%d", &t);
	int start, end, mid, ans, res;
	while(t--) 
	{
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; ++i)
		{
		   	scanf("%d", &stalls[i]);
		}
		sort(stalls, stalls +n);
		start = 0;
		end = stalls[n-1];
		mid = end/2;
		ans = 0;
		res = 0;
		while(start <= end ) 
		{
			//printf("%d %d %d\n", start,mid, end);
		    res = bs(mid, n , m);
		    if (res==-1)
		    {
		    	end = mid-1;
		    	mid = start + (end-start)/2;
		    }
		    else
		    {
		    	//printf("HOLA\n");
		    	ans = mid;
		    	start = mid +1;
		    	mid = start + (end-start)/2;
		    }
		}
		//printf("%d %d %d\n", start,mid, end);
		printf("%d\n", ans);

	}
	
}
