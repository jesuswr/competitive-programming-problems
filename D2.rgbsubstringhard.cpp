#include <iostream>
#include <string>

using namespace std;

char word[int(2e5+5)];
int RGB[int(2e5+5)];
int GBR[int(2e5+5)];
int BRG[int(2e5+5)];
char rgb[3] = {'R','G','B'};



int main()
{
	int t;
	scanf("%d", &t);
	while(t--) 
	{
	    int n,k;
	    scanf("%d %d", &n, &k);
	    
	    scanf("%s", word);
	    if (k==1)
	    {
	    	
	    	printf("0\n");
	    	continue;
	    }

	    for (int i = 0; i < n; ++i)
	    {
	    	if (rgb[i%3]==word[i])
	    	{
	    		RGB[i] = 0 + (i == 0 ? 0: RGB[i-1]);
	    	}
	    	if (rgb[i%3]!=word[i])
	    	{
	    		RGB[i] = 1 + (i == 0 ? 0: RGB[i-1]);
	    	}
	    	if (rgb[(i+1)%3]==word[i])
	    	{
	    		GBR[i] = 0 + (i == 0 ? 0: GBR[i-1]);
	    	}
	    	if (rgb[(i+1)%3]!=word[i])
	    	{
	    		GBR[i] = 1 + (i == 0 ? 0: GBR[i-1]);
	    	}
	    	if (rgb[(i+2)%3]==word[i])
	    	{
	    		BRG[i] = 0 + (i == 0 ? 0: BRG[i-1]);
	    	}
	    	if (rgb[(i+2)%3]!=word[i])
	    	{
	    		BRG[i] = 1 + (i == 0 ? 0: BRG[i-1]);
	    	}
	    }
	   
	    int mind = min( RGB[k-1], min( GBR[k-1], BRG[k-1]  ) );

	    if (mind == 0) 
	    {
	    	printf("0\n");
	    	continue;
	    }
	    for (int i = 1; i < n-k+1; ++i)
	    {
	    	mind = min( min( mind, RGB[i+k-1] - RGB[i-1] ), min( GBR[i+k-1] - GBR[i-1], BRG[i+k-1] - BRG[i-1] ) );
	    }

	    
	    printf("%d\n", mind);
	    
	   
	}
}