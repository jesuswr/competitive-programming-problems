#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>


using namespace std;

struct edge
{
	int to;
	double cost;
};

int v, e;
const double maxD = 1.7e+308;

vector<edge> g[32];
unordered_map<string,int> mp;

// Bellman Ford
double cost[32];


bool bellman(int s)
{
	cost[s] = 0;
	int it = 1;
	bool change = true;
	while( it<v && change) {
	    it++;
	    change = false;
	    for (int i = 0; i<v; i++)
	    {
	    	for (edge e: g[i])
	    	{
	    		if (cost[e.to]!=maxD)
	    		{
	    			if ( cost[e.to] > 1 - (-cost[i]+1)*e.cost )
	    			{
	    				cost[e.to] = 1 - (-cost[i]+1)*e.cost;
	    				change = true;
	    			}
	    		}
	    	}
	    }
	}

	for (int i = 0; i<v; i++)
	{
	   	for (edge e: g[i])
	   	{
	   		if (cost[e.to]!=maxD)
	   		{
	   			if ( cost[e.to] > 1 - (-cost[i]+1)*e.cost )
	   			{
	   				return true;
	   			}
	   		}
	   	}
	}
	return false;
}




int main()
{
	char word[30], word2[30];
	double aux;
	scanf("%d", &v);
	int n1 = 0;
	while (v)
	{
		n1++;
		for (int i = 0; i < v; ++i)
		{
			scanf("%s", word);
			mp[word] = i;

		}
		scanf("%d", &e);
		for (int i = 0; i < e; ++i)
		{
			scanf("%s %lf %s",word,&aux,word2);
			g[mp[word]].push_back({mp[word2],aux});

		}
		for (int i = 0; i < v; ++i) cost[i] = maxD;
		bool ans;
		for (int i = 0; i < v; ++i)
		{
			if (cost[i]==maxD)
			{
				ans = bellman(i);
			}
			if (ans == true) break;
		}
		printf("Case %d: ", n1);
		if (ans==true) printf("Yes\n");
		else printf("No\n");
		
		

		for (int i = 0; i<v; i++) g[i].clear();
		mp.clear();
		scanf("%d", &v);
	}
}