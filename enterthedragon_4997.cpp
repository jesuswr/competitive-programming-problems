#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

const int maxN = 1e6 +10;
int rains[maxN];
set<pair<int,int>> st;
int last[maxN];
int ans[maxN];

int main()
{
	int t, n, m;
	scanf("%d",&t);
	while(t--) 
	{
	    scanf("%d %d", &n, &m);
	    for (int i = 0; i < m; ++i)
	    {
	    	scanf("%d", &rains[i]);
	    }
	    for (int i = 1; i <= n; ++i)
	    {
	    	last[i] = -1;
	    }
	    int zeroCount = 0;
	    bool ansExist = true;
	    for (int i = 0; i < m && ansExist; ++i)
	    {
	    	if (rains[i]==0)
	    	{
	    		ans[zeroCount] = 0;
	    		zeroCount++;
	    		st.insert({i, zeroCount-1});
	    	}
	    	else
	    	{
	    		auto it = st.lower_bound({last[rains[i]],0});
	    		if (it==st.end()) { ansExist = false; break; }
	    		last[rains[i]] = i;
	    		pair<int,int> aux = *it;
	    		ans[aux.second] = rains[i];
	    		st.erase(it);
	    	}
	    }
	    if (ansExist)
	    {
	    	printf("YES\n");
	    	for (int i = 0; i < zeroCount; ++i)
	    	{
	    		printf("%d ", ans[i]);
	    	}
	    	printf("\n");
	    }
	    else
	    {
	    	printf("NO\n");
	    }
	    st.clear();
	}
}