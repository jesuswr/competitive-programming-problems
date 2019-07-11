#include <iostream>
#include <queue>


using namespace std;


typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;

int t,p,v,e;


const int maxN = 1002;
int father[maxN], siz[maxN];


priority_queue <piii> pq;


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

	int rans = -ans*p;
	printf("%d\n",rans );

}




int main()
{
	scanf("%d", &t);

	int a,b,c;

	for (int ii = 0; ii < t; ii++)
	{
		scanf("%d", &p);
		scanf("%d", &v);
		scanf("%d", &e);

		pq = priority_queue<piii>();
		//cout << pq.empty() << endl;


		for (int i = 0; i < e; i++)
		{
			scanf("%d %d %d", &a, &b, &c);
			pq.push({-c,{a,b}});

		}

		makeSet(1,v);

		kruskall();

	}

}


















