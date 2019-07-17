#include <iostream>

using namespace std;

long long n, k,ans;

int checkI(long long i)
{
	long long sum = i*(i+1)/2;
	if (sum<k) return -1;
	if (i+(sum-k)==n) {ans = sum-k;return 0;}
	if (i+(sum-k)>n) return 1;
	if (i+(sum-k)<n) return -1;
}


int main()
{
	scanf("%lld %lld", &n, &k);
	if (n==1)
	{
		printf("0\n");
		return 0;
	}
	long long start = 0;
	long long end = 1e9;
	long long mid = (start+end)/2;
	ans = 0;
	while(start<end) {
	    if (checkI(mid)==0)
	    {
	    	break;
	    }
	    if (checkI(mid)==-1)
	    {
	    	start = mid +1;
	    	mid = (start+end)/2;
	    }
	    else
	    {
	    	end = mid;
	    	mid = (start+end)/2;
	    }

	}
	printf("%lld\n",ans );
}
