#include <iostream>
#include <algorithm>


using namespace std;

int numbs[2*int(1e5)+5];

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &numbs[i]);
	}
	sort(numbs, numbs+n);
	int ind = n/2;
	int aux = ind+1;
	int cont = 1;
	while(k>0) {
	    if (cont*(numbs[aux]-numbs[ind])<=k && aux<n)
	    {
	    	//printf("hola\n");
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
	printf("%d\n", numbs[ind]);

}
