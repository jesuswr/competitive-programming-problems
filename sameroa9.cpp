#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include <map>



using namespace std;
typedef pair<int,int> pii;


struct edge
{
	int to, cost;
};

const int maxN = 1000; // Actualizar este valor
const int INF = 0x7fffffff;

int v,e;

map<int,int> g[maxN];
map<int,int> gT[maxN];

int cost[maxN];
int cost2[maxN];

void dijkstra(int s)
{
	for (int i = 0; i<v; i++) cost[i] = INF;

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

	    for ( auto e : g[node]){
	    	no = e.first;
	    	we = e.second;

	    	if (cost[no] > cost[node] + we){
	    		//printf("%d\n",cost[no]);
	    		cost[no] = cost[node] + we;
	    		//printf("%d\n",cost[no]);
	    		pq.push({-cost[no],no});
	    	}

	    }
	}
}

void dijkstra2(int s)
{
	for (int i = 0; i<v; i++) cost2[i] = INF;

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

	    for ( auto e : gT[node]){
	    	no = e.first;
	    	we = e.second;

	    	if (cost2[no] > cost2[node] + we){
	    		cost2[no] = cost2[node] + we;
	    		
	    		pq.push({-cost2[no],no});
	    	}

	    }
	}
}


int main()
{
	
	int n1, n2, w;
	int s,d;
	scanf("%d %d", &v, &e);
	int aux;

	while(v!=0 && e!=0) 
	{

		scanf("%d %d", &s, &d);
		for (int i = 0; i < e; ++i)
		{
			scanf("%d %d %d", &n1, &n2, &w);
			g[n1][n2]=w;
			gT[n2][n1]=w;
		}
		
		dijkstra(s);
		dijkstra2(d);

		

		for (int i = 0; i < v; ++i)
		{
			for(auto e:g[i])
			{
				if (cost[i]==INF || cost2[e.first]==INF || cost[d]==INF) continue;
				if (cost[i]+e.second+cost2[e.first]==cost[d]) {g[i].erase(e.first);}//printf("%d\t%d\n",i,e.first );}
			}
		}
		dijkstra(s);
		if (cost[d]!=INF){
			printf("%d\n", cost[d]);
		}
		else printf("-1\n");
		


		for (int i = 0; i<v;i++) {g[i].clear();gT[i].clear();}
		scanf("%d %d", &v, &e);
	}
}
