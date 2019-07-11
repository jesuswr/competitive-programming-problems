#include <iostream>
#include <vector>
#include <queue>


using namespace std;


struct edge
{
	int to, cost;
};

const int maxN = 5005; // Actualizar este valor
const int INF = 0x7fffffff;

int v;

vector<edge> g[maxN];

int cost1[maxN];
int cost2[maxN];
int cost3[maxN];

void dijkstra1(int s)
{
	for (int i =1; i<=v; i++) cost1[i] = INF;
	priority_queue<pair<int,int>> pq;
	int node;
	int weig;
	int no;
	int we;
	cost1[s] = 0;
	pq.push({0,s});

	while( !pq.empty() ) 
	{
	    node = pq.top().second;
	    weig = -pq.top().first;
	    pq.pop();

	    if ( weig > cost1[node]) continue;

	    for ( edge e : g[node]){
	    	no = e.to;
	    	we = e.cost;

	    	if (cost1[no] > cost1[node] + we){
	    		cost1[no] = cost1[node] + we;
	    		pq.push({-cost1[no],no});
	    	}

	    }
	}
}

void dijkstra2(int s)
{
	for (int i =1; i<=v; i++) cost2[i] = INF;
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

	    for ( edge e : g[node]){
	    	no = e.to;
	    	we = e.cost;

	    	if (cost2[no] > cost2[node] + we){
	    		cost2[no] = cost2[node] + we;
	    		pq.push({-cost2[no],no});
	    	}

	    }
	}
}

void dijkstra3(int s)
{
	for (int i =1; i<=v; i++) cost3[i] = INF;
	priority_queue<pair<int,int>> pq;
	int node;
	int weig;
	int no;
	int we;
	cost3[s] = 0;
	pq.push({0,s});

	while( !pq.empty() ) 
	{
	    node = pq.top().second;
	    weig = -pq.top().first;
	    pq.pop();

	    if ( weig > cost3[node]) continue;

	    for ( edge e : g[node]){
	    	no = e.to;
	    	we = e.cost;

	    	if (cost3[no] > cost3[node] + we){
	    		cost3[no] = cost3[node] + we;
	    		pq.push({-cost3[no],no});
	    	}

	    }
	}
}



int main(){
	int B, C, N, e;
	int n1, n2, l;
	int ans1, ans2, ans3;
	scanf("%d %d %d %d %d", &v, &B, &C, &N, &e);
	while(v!=-1) {
	    for (int i = 0; i < e; ++i)
	    {
	    	scanf("%d %d %d", &n1, &n2, &l);
	   		g[n1].push_back({n2,l});
	   		g[n2].push_back({n1,l});
	    }

	    ans1 = -1;
	    ans2 = -1;
	    ans3 = -1;

	    dijkstra1(B);
	    dijkstra2(C);
	    dijkstra3(N);

	    for (int i = 1; i <= v; ++i)
	    {
	    	if (cost2[i]==INF || cost3[i]==INF || cost1[i]==INF) continue;

	    	//printf("HOLA entro con %d\n", i);
	    	if (cost2[i]+cost1[i]==cost1[C] && cost3[i]+cost1[i]==cost1[N]){
	    		if (cost1[i]>ans1)
	    		{
	    			ans1=cost1[i];
	    			ans2=cost2[i];
	    			ans3=cost3[i];
	    		}
	    	}

	    }

	    printf("%d %d %d\n", ans1, ans2, ans3);



	    for (int i = 1; i <= v; ++i) g[i].clear();
	    scanf("%d %d %d %d %d", &v, &B, &C, &N, &e);
	}
}