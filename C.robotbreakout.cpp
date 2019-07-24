#include <iostream>

using namespace std;

int n;


int main()
{
	int t;
	scanf("%d",&t);
	while(t--) 
	{
		int n;
		scanf("%d", &n);
	    int x, y, mu, md, ml, mr;
	    int maxx=1e5, maxy=1e5;
	    int minx = -maxx, miny = -maxy;
	    for (int i = 0; i < n; ++i)
	    {
	    	scanf("%d %d %d %d %d %d", &x, &y, &ml, &mu, &mr, &md);
	    	if (mr==0)
	    	{
	    		maxx = min(maxx, x);
	    	}
	    	if (ml==0)
	    	{
	    		minx = max(minx, x);
	    	}
	    	if (mu==0)
	    	{
	    		maxy = min(maxy, y);
	    	}
	    	if (md==0)
	    	{
	    		miny = max(miny, y);
	    	}
	    }
	    if (miny>maxy || minx>maxx)
	    {
	    	printf("0\n");
	    }
	    else
	    {
	    	printf("1 %d %d\n", minx, miny);
	    }

	}
}
