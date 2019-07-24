#include <iostream>
#include <queue>


using namespace std;

int numbs[int(2e5+4) ];
vector<int> ans;

int main()
{
	int t;
	int n, k;
	scanf("%d", &t);
	int odds = 0;
	while(t--) 
	{
	    scanf("%d %d", &n, &k);
	    odds = 0;
	    for (int i = 0; i < n; ++i)
	    {
	    	scanf("%d", &numbs[i]);
	    	if (numbs[i]%2!=0) odds++;
	    	//printf("%d ", numbs[i]);
	    }
	    //printf("%d\n",odds );
	    odds -= k;
	    if (odds%2 != 0 || odds<0)
	    {
	    	printf("NO\n");
	    	continue;
	    }
	    printf("YES\n");
	    odds = 0;
	    for (int i = 0; i < n && odds < k-1; ++i)
	    {
	    	if (numbs[i]%2!=0)
	    	{
	    		printf("%d ", i+1);
	    		odds++;
	    	}
	    }
	    printf("%d\n", n);
	}
}
