#include <iostream>
#include <algorithm>



using namespace std;


struct edge
{
  	int cost, from, to;
  	bool operator < (const edge &w)
  	{
		return cost > w.cost;
 	}
};


const int maxN = 10003;
int father[maxN], siz[maxN];
edge edges[100002];




// n es el primer elemento y m el ultimo, por ejemplo los nodos de un grafo desde el 1 al 10
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

void unio(int x, int y)
{
  	if (siz[x] > siz[y]) father[y] = x;
 	else
	{
		father[x] = y;
		if ( siz[x] == siz[y] ) siz[y]++;
  	}
}



int main()
{
  	int t;
  	scanf("%d", &t);
  	int l = 1;
  	int v,e;
  	int a, b,c ;
  	while(l<=t) 
  	{
	  	scanf("%d %d", &v, &e);
	  	for (int i = 0; i < e; ++i)
	  	{
			scanf("%d %d %d", &a, &b, &c);
			edges[i]={c,a,b};
	  	}
	  	sort(edges, edges+e);
	  	makeSet(1,v);
	  	int totalC = 0, maxC = 0;
	  	for (int i = 0; i < e; ++i)
	  	{
			if ( find(edges[i].from) != find(edges[i].to) ) unio( find(edges[i].from) , find(edges[i].to) );
			else
			{
		  		totalC += edges[i].cost;
		  		maxC = max(maxC,edges[i].cost);
			}
	  	}
	  	printf("Case #%d: %d %d\n", l, totalC, maxC);
	  	l++;

  	}
}
