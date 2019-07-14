#include <iostream>
#include <map>

using namespace std;
const int maxN = 5e4+10;
int paintedColumns[maxN];
int paintedRows[maxN];
map<pair<int,int>,int> mp;

int main()
{
	int q;
	scanf("%d",&q);
	int n,m;
	char c;
	int max1;
	int max2;
	int ans;
	
	while(q--) {
		ans = 0;
		max1 = 0;
		max2 = 0;
	    scanf("%d %d", &n,&m);

	    for (int i = 0; i < m; ++i)
	    	{
	    		
	    		paintedColumns[i] = 0;
	    	}
	    	
	    	for (int i = 0; i < n; ++i)
	    	{
	    		
	    		paintedRows[i] = 0;
	    	}
	    
	    for (int i = 0; i < n; ++i)
	    {

	    	scanf("%*c");
	    	for (int j = 0; j < m; ++j)
	    	{
	    		scanf("%c",&c);
	    		
	    		if (c=='*')
	    		{
	    			paintedRows[i]++;
	    			paintedColumns[j]++;
	    			mp[{i,j}]=1;
	    		}
	    		
	    	}
	    }
	    
	    for (int i = 0; i < n; ++i)
	    {
	    	for (int j = 0; j < m; ++j)
	    	{
	    		ans = max(ans, paintedRows[i]+paintedColumns[j]-(int)(mp[{i,j}]==1));	
	    	}
	    }

	    ans = m+n-1-ans;
	    	


	    	
	    printf("%d\n", ans);
		
		mp.clear();	
	}
}