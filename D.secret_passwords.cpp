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
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define f first
#define s second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 2e5+5; // CAMBIAR ESTE

// GJNM
set<int> g[30];
char w[60];
int father[maxN], siz[maxN];


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
	x = find(x); y = find(y);
	if (siz[x] > siz[y]) father[y] = x;
	else
	{
		father[x] = y;
		if ( siz[x] == siz[y] ) siz[y]++;
	}
}



int main()
{
	int n;
	ri(n);
	FOR(i,0,n){
		scanf("%s",w);
		int l = strlen(w);
		FOR(j,0,l){
			g[w[j]-'a'].insert(i);
		}
	}
	int cnt = n;
	makeSet(0,n);
	FOR(i,0,30){
		int last = -1;
		for( int y : g[i] ){
			if ( last == -1 ){
				last = y;
				continue;
			}
			if ( find(y) != find(last) ){
				unio(y,last);
				cnt--;
			}
			last = y;
		}
	}
	printf("%d\n", cnt);
	return 0;
}