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
const int maxN = 1e5 + 10; // CAMBIAR ESTE

// GJNM
int v, e, k;
vi G[maxN];
int START, END;
bool SPECIAL[maxN];

int father[maxN], siz[maxN];
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
void unio(int x, int y) { // x y y tienen que ser los representantes
	if (siz[x] > siz[y])
		father[y] = x;
	else {
		father[x] = y;
		if ( siz[x] == siz[y] ) siz[y]++;
	}
}

int C[maxN];

bool check(int q) {
	makeSet(0, v);
	queue<int> curr;
	set<int> active;
	FOR(i, 0, v) {
		if ( SPECIAL[i] ) {
			active.insert(i);
			curr.push(i);
		}
	}
	curr.push(END), active.insert(END);

	FOR(i, 0, q / 2) {
		int n = curr.size();

		if ( find(START) == find(END) )
			return true;

		FOR(j, 0, n) {
			int x = curr.front(); curr.pop();
			for (auto &y : G[x]) {
				if ( find(x) != find(y) )
					unio(find(x), find(y));
				if ( !active.count(y) ) {
					active.insert(y);
					curr.push(y);
				}
			}
		}
	}
	if ( q & 1 ) {
		for (auto &i : active) {
			for (auto &y : G[i]) {
				if ( find(i) != find(y) && (active.count(y) > 0) )
					unio(find(i), find(y));
			}
		}
	}

	return find(START) == find(END);
}

int DIST[maxN];
bool vis[maxN];
int AYUDA = INF;

void bfs(int e) {
	vis[e] = true;
	DIST[e] = 0;
	queue<int> q;
	q.push(e);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		if ( x == START )
			return;
		if ( SPECIAL[x] )
			AYUDA = min(AYUDA, DIST[x]);

		for (auto y : G[x]) {
			if (!vis[y]) {
				DIST[y] = DIST[x] + 1;
				vis[y] = true;
				q.push(y);
			}
		}
	}
	printf("-1\n");
	exit(0);
}


int main() {
	riii(v, e, k);
	FOR(i, 0, k) {
		int aux;
		ri(aux);
		SPECIAL[aux - 1] = true;
	}
	FOR(i, 0, e) {
		int a, b;
		rii(a, b);
		a--, b--;
		G[a].pb(b);
		G[b].pb(a);

	}
	rii(START, END);
	START--, END--;

	bfs(END);

	int lo = AYUDA, hi = DIST[START];
	while ( lo < hi ) {
		FOR(i, 0, v)
			C[i] = -1;

		int mid = lo + (hi - lo) / 2;
		if ( check(mid) )
			hi = mid;
		else
			lo = mid + 1;
	}
	printf("%d\n", hi);
	return 0;
}