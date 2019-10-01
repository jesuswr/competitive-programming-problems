#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a);
#define rii(a,b) scanf("%d %d", &a, &b);
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c);
#define rl(a) scanf("%lld", &a);
#define rll(a,b) scanf("%lld %lld", &a, &b);

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 105; // CAMBIAR ESTE

vi gI[maxN];
bool tof[maxN];
bool visited[maxN];
int to[maxN];
bool stat[maxN];
bool paradox;


// GJNM

bool getVal(bool a, bool b)
{
	return a==b;
}

void dfs( int x )
{
	visited[x] = true;
	if ( !visited[ to[x] ] )
	{
		tof[ to[x] ] = getVal( tof[x], stat[x]);
		dfs( to[x] );
	}
	else
	{
		if ( getVal( tof[x], stat[x]) != tof[ to[x] ])
		{
			paradox = true;
			return;
		}
	}

	for ( int y : gI[x])
	{
		if ( !visited[y] )
		{
			tof[y] = getVal( stat[y], tof[x] );
			dfs( y );
		}
		else
		{
			if ( tof[y] != getVal( stat[y], tof[x]))
			{
				paradox = true;
				return;
			}
		}
	}
}


int main()
{
	int n;
	int aux;
	bool aux2;
	char aux3[10];
	while(true) 
	{
	    ri(n);
	    if ( n == 0) break;
	    for (int i = 1; i <= n; ++i)
	    {
	    	visited[i] = false;
	    	tof[i] = true;
	    	scanf("%d %s", &aux, aux3);
	    	aux2 = true;
	    	if ( aux3[0] == 'f' ) aux2 = false;
	    	to[i] = aux;
	    	stat[i] = aux2;
	    	gI[aux].push_back(i);
	    }

	    paradox = false;
	    for (int i = 1; i <= n; ++i)
	    {
	    	if ( !visited[i] ) dfs(i);
	    	if ( paradox ) break;
	    }
	    paradox == true ? printf("PARADOX\n") : printf("NOT PARADOX\n");
	    for (int i = 0; i < n; ++i) gI[i+1].clear();
	    
	}
}