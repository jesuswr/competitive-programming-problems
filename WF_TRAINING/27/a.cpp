#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int das;
#define FOR(i,n,m) for (int i = n; i < (int)m; i++)
#define ROF(i,n,m) for (int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj, val, sizeof(obj))
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
const ll INFLL = 1e18+69;
const int MOD = 1e9+7;
const int MAXN = 1e6+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

struct edge {
	int f, t;
	ll s, e;
	long double p;

	bool operator<(edge other) {
		if (s == other.s) return f < other.f;
		return s > other.s;
	}

	void print() {
		cout << f << " " << t << " " << s << " " << e << " " << p << endl;
	}
};

int V, E;
ll T;
vector<edge> G;
vector< pair<ll, long double> > H[MAXN];

void push(ll t, long double p, int i) {
	H[i].pb({-t, p});
}
void push_if_best(ll t, long double p, int i) {
	if (p > H[i].back().S) push(t,p,i);
}
long double get(ll t, int i) {
	pair<ll, long double> tmp = {-t, -1};
	int ind = lower_bound( all(H[i]) , tmp) - H[i].begin();
	return H[i][ind-1].S;
}

int main() {
	rii(E,V); lri(T);
	FOR(i,0,E) {
		edge e;
		das=scanf("%d %d %lld %lld %Lf", &e.f, &e.t, &e.s, &e.e, &e.p);
		G.pb(e);
	}
	sort(all(G));
	FOR(i,0,V) push(INFLL, 0, i);
	push(T+1, 1, 1);

	int gi = 0;
	while(gi < sz(G)) {
		vector<edge> curr;
		int aux = gi;
		while( aux < sz(G) && G[aux].s == G[gi].s && G[aux].f == G[gi].f ) {
			curr.pb(G[aux]);
			aux++;
		}
		gi = aux;

		int from = curr[0].f;
		ll start = curr[0].s;
		long double mx = 0;
		for(edge &e : curr) {
			long double p = get(e.e, e.t) * e.p + get(e.s, e.f) * (1 - e.p);
			mx = max(mx, p);
		}
		// curr[0].print();
		// cout << mx << endl;
		push_if_best(start, mx, from);
	}
	printf("%.10Lf\n", H[0].back().S);
	return 0;
}
