#include <iostream>
#include <algorithm>


using namespace std;

long long piles[3];

int main()
{
	int t;
	scanf("%d", &t);
	long long ac;
	long long bc;
	while(t--) 
	{
	    scanf("%lld %lld %lld", &piles[0], &piles[1], &piles[2]);
	    sort(piles, piles+3);
	    ac = piles[0];
	    bc = piles[1];
	    //printf("%lld %lld\n", ac, bc);
	    ac += piles[1]-piles[0];
	    //printf("%lld\n", ac);
	    piles[2] -=piles[1]-piles[0];

	    ac += piles[2]/2;
	    printf("%lld\n", ac);

	}
}
