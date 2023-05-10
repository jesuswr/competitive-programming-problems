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


int main(){
	ll n,m; lrii(n, m);
	vector< ll > a(n);
	FOR(i,0,n) lri(a[i]);

	priority_queue< pair< ll, ll> > pq;
	FOR(i,0,n) pq.push({a[i], i});

	while(!pq.empty()) {
		auto [ai, i] = pq.top(); pq.pop();
		if (ai != a[i]) continue;
		// cout << i << " " << ai << endl;
		if (i > 0 && a[i-1] < a[i]) {
			ll diff = a[i] - a[i-1];
			if (diff > m) {
				a[i-1] = a[i] - m;
				pq.push({a[i-1], i-1});
			}
		}
		if (i + 1 < n && a[i+1] < a[i]) {
			ll diff = a[i] - a[i+1];
			if (diff > m) {
				a[i+1] = a[i] - m;
				pq.push({a[i+1], i+1});
			}
		}
	}
	FOR(i,0,n) printf("%lld%c", a[i], " \n"[i+1==n]);
	return 0;
}
