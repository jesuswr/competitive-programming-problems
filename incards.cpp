#include <iostream>
#include <vector>
#include <queue>


using namespace std;


struct edge
{
	int to, cost;
};

const int maxN = 1000002;
const int INF = 0x7fffffff;

vector<edge> g[maxN];
vector<edge> gI[maxN];

int n, v, e;

int cost[maxN];
int cost2[maxN];


void dijkstra(int s)
{
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

}

void dijkstra2(int s)
{
	priority_queue<pair<int,int>> pq;
	int node;
	int weig;
	int no;
	int we;
	cost2[s] = 0;
	pq.push({0,s});

	while( !pq.empty() ) 
	{
	    node = pq.top().second;
	    weig = -pq.top().first;
	    pq.pop();
	    

	    if ( weig > cost2[node]) continue;

	    for ( edge e : gI[node]){
	    	no = e.to;
	    	we = e.cost;

	    	if (cost2[no] > cost2[node] + we){
	    		cost2[no] = cost2[node] + we;
	    		pq.push({-cost2[no],no});
	    	}

	    }
	}

}



int main()
{
	scanf("%d", &n);

	int n1, n2, weight;

	for (int ii = 0; ii < n; ++ii)
	{
		
		scanf("%d %d", &v, &e);

		for (int i = 1; i <= v; ++i)
		{
			cost[i] = INF;
			cost2[i] = INF;
			g[i].clear();
			gI[i].clear();
		}
	

		for (int i = 0; i < e; ++i)
		{
			scanf("%d %d %d", &n1, &n2, &weight);
			g[n1].push_back({n2,weight});
			gI[n2].push_back({n1,weight});
		}


		dijkstra(1);
		dijkstra2(1);

		int ans=0;

		for (int i = 1; i <= v; ++i)
		{
			ans += cost[i] + cost2[i];
		}
		printf("%d\n", ans);
	}
}