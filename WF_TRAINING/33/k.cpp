#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int das;
#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) das=scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) das=scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 1e5+5;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int V, E;
vi G[MAXN];
vector< tuple<int, int, int> > E_ind;

void input() {
	rii(V,E);
	FOR(i,0,E){
		int a,b; rii(a,b);
		G[a].pb(b);
		G[b].pb(a);
		E_ind.pb({a,b,i});
		E_ind.pb({b,a,i});
	}
	sort(all(E_ind));
}


int F[MAXN];
bool VIS[MAXN];
void dfs(int u = 1, int f = -1) {
	F[u] = f;
	VIS[u] = 1;

	for(int v : G[u]) if (v != f && !VIS[v]) {
		dfs(v,u);
	}
}

vi CYCLE;
bool IN_CYCLE[MAXN];
int LOW;

bool create_cycle() {
	FOR(u,0,V) for(int v : G[u]) if (v != F[u] && v == 1) {
		int x = u;
		LOW = x;
		while(x != -1) {
			CYCLE.pb(x);
			IN_CYCLE[x] = 1;
			x = F[x];
		}
		reverse(all(CYCLE));
		return true;
	}
	return false;
}

bool CYCLE_UP[MAXN];

void dfs2(int u = 1) {
	if (!IN_CYCLE[u] && F[ u ] != 1 && ( IN_CYCLE[ F[u] ] || CYCLE_UP[ F[u] ] )) 
		CYCLE_UP[u] = 1;

	for(int v : G[u]) if (F[v] == u) dfs2(v);
}

vi edges_to_keys(const vi &vec) {
	vi res;
	FOR(i,1,sz(vec)) {
		auto [a,b,c] = *lower_bound(E_ind.begin(), E_ind.end(), make_tuple(vec[i], vec[i-1], -1));
		res.pb( c );
	}
	return res;
} 

void solve1() {
	vi alice = {0};
	int u = 0;
	while (u != 1) {
		u = F[u];
		alice.pb(u);
	};

	vi bob = {1,LOW};
	u = LOW;
	while(u != 0) {
		u = F[u];
		bob.pb(u);
	}

	vi alice_k = edges_to_keys(alice), bob_k = edges_to_keys(bob);
	for(int x : alice_k) cout << x << ' ';
	cout << endl;
	for(int x : bob_k) cout << x << ' ';
	cout << endl;
	FOR(i,1,sz(alice)) cout << "MOVE " << alice[i] << endl;
	cout << "DONE" << endl;
	FOR(i,1,sz(bob)) cout << "MOVE " << bob[i] << endl;
	cout << "DONE" << endl;
}

void solve2() {
	vi a1, a2, b1, b2, b3;


	a1 = {0};
	int u = 0;
	while (!IN_CYCLE[u]) {
		u = F[u];
		a1.pb(u);
	}

	int z = u;
	a2 = {u};
	while(u != 1) {
		u = F[u];
		a2.pb(u);
	}

	b1 = {1, LOW};

	b2 = {LOW};
	u = LOW;
	while(u != z) {
		u = F[u];
		b2.pb(u);
	}

	b3 = a1;
	reverse(all(b3));

	vi ak1 = edges_to_keys(a1), ak2 = edges_to_keys(a2), bk1 = edges_to_keys(b1), bk2 = edges_to_keys(b2);

	for(int x : ak1) cout << x << ' ';
	for(int x : ak2) cout << x << ' ';
	cout << endl;
	for(int x : bk1) cout << x << ' ';
	for(int x : bk2) cout << x << ' ';
	cout << endl;

	FOR(i,1,sz(a1)) cout << "MOVE " << a1[i] << endl;
	cout << "DROP ";
	for(int x : ak1) cout << x << ' ';
	cout << endl;
	FOR(i,1,sz(a2)) cout << "MOVE " << a2[i] << endl;
	cout << "DONE" << endl;

	FOR(i,1,sz(b1)) cout << "MOVE " << b1[i] << endl;
	FOR(i,1,sz(b2)) cout << "MOVE " << b2[i] << endl;
	cout << "GRAB" << endl;
	FOR(i,1,sz(b3)) cout << "MOVE " << b3[i] << endl;
	cout << "DONE" << endl;

}

void solve3() {
	vi a1, a2, a3, b1, b2, b3;
	// alice de 0 a 1
	a1 = {0};
	int u = 0;
	while(u != 1) {
		u = F[u];
		a1.pb(u);
	}
	
	// alice de LOW a 1
	a3 = {LOW};
	u = LOW;
	while(u != 1) {
		u = F[u];
		a3.pb(u);
	}

	// alice de 1 a LOW
	a2 = a3;
	reverse(all(a2));

	b1 = {1, LOW};
	b2 = {LOW, 1};
	b3 = a1;
	reverse(all(b3));

	vi ak1 = edges_to_keys(a1), ak2 = edges_to_keys(a2), bk1 = edges_to_keys(b1);

	for(int x : ak1) cout << x << ' ';
	for(int x : ak2) cout << x << ' ';
	cout << endl;
	for(int x : bk1) cout << x << ' ';
	cout << endl;

	FOR(i,1,sz(a1)) cout << "MOVE " << a1[i] << endl;
	FOR(i,1,sz(a2)) cout << "MOVE " << a2[i] << endl;
	cout << "DROP ";
	for(int x : ak1) cout << x << ' ';
	cout << endl;
	FOR(i,1,sz(a3)) cout << "MOVE " << a3[i] << endl;
	cout << "DONE" << endl;

	FOR(i,1,sz(b1)) cout << "MOVE " << b1[i] << endl;
	cout << "GRAB" << endl;
	FOR(i,1,sz(b2)) cout << "MOVE " << b2[i] << endl;
	FOR(i,1,sz(b3)) cout << "MOVE " << b3[i] << endl;
	cout << "DONE" << endl;

}

int main(){
	input();

	dfs();
	if (!create_cycle()) {
		printf("No solution\n");
		return 0;
	}
	dfs2();
 
	if (IN_CYCLE[0])
		solve1();
	else if (CYCLE_UP[0])
		solve2();
	else 
		solve3();

	return 0;
}
