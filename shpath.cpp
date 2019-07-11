#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <chrono>

#include <string>
#include <queue>


using namespace std;

const int maxN = 10002;
const int INF = 0x7fffffff;

struct edge
{
	int to, cost;
};

int v;
vector<edge> g[maxN];
int cost[maxN];

unordered_map<string,int> mp;



void dijkstra(int s, int f)
{
	for (int i =1; i<=v; i++) cost[i] = INF;

	priority_queue<pair<int,int>> pq;
	int node;
	int weig;
	int no;
	int we;
	cost[s] = 0;
	pq.push({0,s});

	while( !pq.empty() ) 
	{
	    node = pq.top().second;
	    weig = -pq.top().first;
	    pq.pop();
	    
	    if (node == f) break;

	    if ( weig > cost[node]) continue;

	    for ( edge e : g[node]){
	    	no = e.to;
	    	we = e.cost;

	    	if (cost[no] > cost[node] + we){
	    		cost[no] = cost[node] + we;
	    		pq.push({-cost[no],no});
	    	}

	    }
	}
	printf("%d\n", cost[f]);

}


int main()
{
	char word[20];
	int t,e,n1,n2,w,r;
	scanf("%d",&t);
	while(t--) 
	{
	    scanf("%d",&v);
	    for (int i = 1; i <= v; ++i)
	    {
	    	scanf("%s%d",word,&e);
	    	mp[word] = i;
	    	for (int j = 0; j < e; ++j)
	    	{
	    		scanf("%d %d",&n1,&w);
	    		g[i].push_back({n1,w});
	    	}
	    }
	    scanf("%d",&r);
	    for (int i = 0; i < r; ++i)
	    {
	    	scanf("%s",word);
	    	n1 = mp[word];
	    	scanf("%s",word);
	    	n2 = mp[word];
	    	dijkstra(n1,n2);
	    }
	    mp.clear();
	    for (int i=1; i<=v; i++) g[i].clear();
	}
}