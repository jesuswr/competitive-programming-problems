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

ll N; 
vii I;
map<ll, int> Ind;

int go(ll n) {
	if (Ind.find(n) != Ind.end()) return Ind[n];
	if (n == 1) {
		I.pb({-1, -1});
		return Ind[1] = 0;
	}
	int li = go((n+1) / 2), ri = go(n/2);
	I.push_back({li,ri});
	Ind[n] = sz(I) - 1;
	return Ind[n];
}

void solve() {
	lri(N);
	int ind = go(N);
	printf("%d\n", sz(I));
	for(auto [l,r] : I) printf("%d %d\n", l, r);
	printf("%d\n", ind);
	Ind.clear();
	I.clear();
}


int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}
