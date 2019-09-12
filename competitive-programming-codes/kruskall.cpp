// CODIGO DE KRUSKALL

#include <iostream>
#include <queue>


using namespace std;


typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;

// Estructuras para conjuntos disjuntos
const int maxN = 1002;
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

// LA COLA DE KRUSKALL USA PESOS NEGATIVOS POR COMODIDAD, AL FINAL CAMBIAR EL SIGNO
void kruskall(){
	int numComp = v;
	int ans = 0;
	int node1, node2, weight;

	while( numComp != 1 ) {
		
		weight = pq.top().first;
		node1 = find( pq.top().second.first );
		node2 = find( pq.top().second.second );
	    
	    if (  node1 != node2 )
	    {
	    	unio( node1, node2 );
	    	ans += weight;
	    	numComp--;
	    }

	    pq.pop();
	}

	int rans = -ans;
	

}

