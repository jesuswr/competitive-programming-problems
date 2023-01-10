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



void solve(){
	int n,m;
	rii(n,m);
	vector<ll> a(n);
	for(int i = 0; i < n; ++i) lri(a[i]);

	int cnt = 0;
	--m;
	ll ms = 0;
	for(int i = 0; i <= m; ++i) ms += a[i];

	ll aux = ms - a[m];
	priority_queue<ll> pq;
	if (a[m] > 0)
		pq.push(a[m]);

	for(int i = m-1; i >= 0; --i) {
		while(aux < ms) {
			ll t = pq.top(); pq.pop();
			ms -= 2 * t;
			cnt++;
		}
		if (a[i] > 0) pq.push(a[i]);
		aux -= a[i];
	}

	aux = ms;
	priority_queue<ll> pq2;
	for(int i = m+1; i < n; ++i) {
		if (a[i] < 0) pq2.push(-a[i]);
		aux += a[i];
		while(aux < ms) {
			ll t = pq2.top(); pq2.pop();
			aux += 2 * t;
			cnt++;
		}
	}

	cout << cnt << endl;
}



int main(){
	int t; ri(t);
	while(t--) solve();

	return 0;
}
