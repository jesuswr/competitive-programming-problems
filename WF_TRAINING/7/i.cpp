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

ll steps = -1;
int q(int x) {
	cout << "walk " << x << endl;
	int r; ri(r);
	steps += x;
	return r;
}

void g(int x) {
	cout << "guess " << x << endl;
	exit(0);
}

const int AYUDA = 1e9;

int main(){
	map<int, ll> first;

	int mx = 1;
	FOR(_,0,3333) mx = max(mx, q(rng() % AYUDA + 1));
	FOR(_,0,3333) {
		int u = q(1);
		if (first.find(u) != first.end()) {
			g(steps - first[u]);
		}
		first[u] = steps;
	}
	int u = q(mx);
	if (first.find(u) != first.end()) {
		g(steps - first[u]);
	}
	first[u] = steps;
	FOR(_,0,3333) {
		int u = q(3333);
		if (first.find(u) != first.end()) {
			g(steps - first[u]);
		}
		first[u] = steps;
	}




	return 0;
}
