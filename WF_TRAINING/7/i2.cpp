#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dasdas;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) dasdas=scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) dasdas=scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 2e5+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll AYUDA = 1e9;
ll steps = -1;
ll q(ll x) {
	steps += x;
    ll r = steps % AYUDA + 1;
	return r;
}

void g(ll x) {
	cout << "guess " << x << endl;
	exit(0);
}


void go(ll u, ll sz) {
	ll mn = sz;
	for(ll i = 1; i * i <= sz; ++i) {
		if (sz % i == 0) {
			if (i <= AYUDA) {
				ll nu = q(i);
				if (nu == u) 
					mn = min(mn, i);
				u = nu;
			}
			if (sz / i <= AYUDA) {
				ll nu = q(sz / i);
				if (nu == u) 
					mn = min(mn, sz / i);
				u = nu;
			}
		}
	}
	g(mn);
}

int main(){
	map<ll, ll> first;
	map<ll, ll> last;

	const ll DIV_QUERIES = 30, F_QUERIES = 0;
	const ll S_QUERIES = 10000 - DIV_QUERIES - F_QUERIES;

	FOR(_,0,F_QUERIES) {
		ll u = q(1);
		first[u] = steps;
	}

    const ll aux = 5e8;
    const ll aux2 = 5e8 + 1;
	FOR(_,0,S_QUERIES) {
		ll s = aux + (rng() % aux2);
		ll u = q(s);
		last[u] = steps;
        assert(steps > 0);
		if (first.find(u) != first.end()) {
            cout << u << endl;
            cout << last[u] << "  -  " << first[u] << endl;
			go(u, last[u] - first[u]);
		}
        else {
            first[u] = steps;
        }
	}
	assert(false);


	return 0;
}
