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

void solve() {
	int n,m; rii(n,m);
	priority_queue<int> pq;
	FOR(i,0,n) {
		int a; ri(a);
		pq.push(-a);
	}
	FOR(i,0,m) {
		int a; ri(a);
		pq.pop();
		pq.push(-a);
	}
	ll sm = 0;
	while(!pq.empty()) {
		sm -= pq.top();
		pq.pop();
	}
	cout << sm << endl;
}

int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}
