#include <iostream>
#include <algorithm>


using namespace std;

long long numbs[2*int(1e5)+5];

int main(){
	long long n, k;
	scanf("%lld %lld", &n, &k);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld", &numbs[i]);
	}
	sort(numbs, numbs+n);
	int ind = n/2;
	int aux = ind+1;
	int cont = 1;
	while(k>0) {
	    if (cont*(numbs[aux]-numbs[ind])<=k && aux<n)
	    {
	    	
	    	
	    	k -= (numbs[aux] - numbs[ind])*cont;
	    	
	    	numbs[ind] = numbs[aux];

	    	aux++;
	    	cont++;
	    }
	    else if (k>=cont || aux>=n)
	    {
	    	
	    	numbs[ind] += k/cont;
	    	break;
	    }
	    else
	    {
	    	
	    	break;
	    }
	}
	printf("%lld\n", numbs[ind]);

}
