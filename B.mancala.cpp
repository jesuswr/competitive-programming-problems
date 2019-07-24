#include <iostream>

using namespace std;

long long arr1[14], arr2[14];


long long getStones(int ind)
{
	for (int i = 0; i < 14; ++i)
	{
		arr2[i] = arr1[i];
	}
	int stones = arr2[ind];
	arr2[ind] = 0;
	if ( stones/14 != 0)
	{
		for (int i = 0; i < 14; ++i) arr2[i] += stones/14;
	}
	if (stones%14 != 0)
	{
		stones = stones%14;
		int index = ind +1;
		while(stones>0) {
		    if (index == 14) index = 0;
		    else
		    {
		    	arr2[index] ++;
		    	stones --;
		    	index++;
		    }
		}
	}
	long long ret = 0;
	for (int i = 0; i < 14; ++i)
	{
		if (arr2[i]%2==0)
		{
			ret += arr2[i];
		}
	}
	return ret;
}



int main()
{
	for (int i = 0; i < 14; ++i)
	{
		scanf("%lld", &arr1[i]);
	}
	long long ans = 0;
	for (int i = 0; i < 14; ++i)
	{
		ans = max( ans, getStones(i));	
	}
	printf("%lld\n", ans);
}
