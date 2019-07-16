#include <iostream>
#include <vector>
#include <queue>
#include <set>


using namespace std;


const int maxN = 505;
int v, e;

struct edge
{
	int to, cost;
};

typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;

// Estructuras para conjuntos disjuntos
int father[maxN], siz[maxN];

// Estructura para kruskall
priority_queue <piii> pq;

// n es el primer indice del conj y m el ultimo
void makeSet(int n, int m)
{
	for (int i = n; i <= m; ++i)
	{
		father[i] = -1;
		siz[i] = 0;
	}
}

int find(int x)
{
	if (father[x]==-1) return x;

	return father[x] = find(father[x]);
}

// x e y deben ser los representantes de sus conjuntos
void unio(int x, int y)
{
	if (siz[x] > siz[y]) father[y] = x;
	else
	{
		father[x] = y;
		if ( siz[x] == siz[y] ) siz[y]++;
	}
}

set<piii> mst;
vector<edge> g[maxN];
vector<pii> g2[10001];

// LA COLA DE KRUSKALL USA PESOS NEGATIVOS POR COMODIDAD, AL FINAL CAMBIAR EL SIGNO
void kruskall(){
	int numComp = v;
	int node1, node2, weight;

	while( numComp != 1 ) {
		
		weight = pq.top().first;
		node1 = find( pq.top().second.first );
		node2 = find( pq.top().second.second );
	    
	    if (  node1 != node2 )
	    {
	    	unio( node1, node2 );
	    	mst.insert({-weight,{pq.top().second.first,pq.top().second.second}});
	    	numComp--;
	    }

	    pq.pop(); 
	}

	
	

}




int main()
{
	int n1, n2, w, count, cost;
	while (scanf("%d %d", &v, &e)>0)
	{	
		
		count = cost =0;
		for (int i = 0; i < e; ++i)
		{
			scanf("%d %d %d", &n1, &n2, &w);
			g[n1].push_back({n2,w});
			g[n2].push_back({n1,w});
			g2[w].push_back({n1,n2});
			pq.push({-w,{n1,n2}});
		}
		makeSet(1,v);
		kruskall();

		for (auto it = mst.begin(); it != mst.end() ; ++it)
		{
			auto p = *it;
			makeSet(1,v);
			int aux = g2[p.first].size();
			
			if (g2[p.first].size()>0)
			{
				for (piii pp:mst)
				{
					if (pp.second.first!=p.second.first || pp.second.second!=p.second.second)
					{
						
						unio(find(pp.second.first), find(pp.second.second));
					}
				}
				
				bool add = true;
				for (pii pp: g2[p.first])
				{
					
					if (find(pp.first)!=find(pp.second) && (pp.first!=p.second.first || pp.second!=p.second.second)){
						add = false;
						break;
					}
				}
				if (add)
				{
					count++;
					cost += p.first;
				}
			}
			
		}
		printf("%d %d\n", count, cost);
		for (int i = 1; i <= v; ++i) g[i].clear();
		for (int i = 1; i < 10001; ++i) g2[i].clear();
		pq = priority_queue<piii>();
		mst.clear();
	}
}
