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
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
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
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 3e5; // CAMBIAR ESTE


int father[maxN], siz[maxN];
bool special[maxN];
// n es el primer elemento y m el ultimo, por ejemplo los nodos de un grafo desde el 1 al 10
void makeSet(int n, int m) {
	for (int i = n; i <= m; ++i) {
		father[i] = -1;
		siz[i] = 0;
	}
}
int find(int x) {
	if (father[x] == -1) // -1 significa que es el representante del set
		return x;
	return father[x] = find(father[x]);
}
void unio(int x, int y, bool spec) { // x y y tienen que ser los representantes
	if (siz[x] > siz[y]) {
		father[y] = x;
		special[x] = spec;
	}
	else {
		father[x] = y;
		if ( siz[x] == siz[y] )
			siz[y]++;
		special[y] = spec;
	}
}



// GJNM
int V, E, K;

int main() {
	riii(V, E, K);
	FOR(i, 0, K) {
		int a;
		ri(a);
		special[a] = true;
	}
	priority_queue<piii> pq;
	FOR(i, 0, E) {
		int u, v, x;
		riii(u, v, x);
		pq.push({ -x, {u, v}});
	}
	int ans = -1;
	makeSet(0, 2*V);

	while (!pq.empty()) {
		int cst = -pq.top().F;
		int x = pq.top().S.F, y = pq.top().S.S;
		pq.pop();
		x = find(x), y = find(y);
		if ( x != y ){
			if ( special[x] && special[y] )
				ans = cst;
			unio(x,y,special[x] || special[y]);
		}
	}

	FOR(i, 0, K)
		printf("%d ", ans);
	printf("\n");

	return 0;
}