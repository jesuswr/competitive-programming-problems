#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) scanf("%lld", &a)
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
	ll P; cin >> P;
	set< pair< int, ll > > vis;
	map< pair<int,ll> , int > par;
	queue< tuple< int, ll, int> > q;

	q.push({0, P, 0});
	vis.insert({0,P});

	while(!q.empty()) {
		auto [sum, prod, dst] = q.front(); q.pop();
		if (sum == 41 && prod == 1) {
			cout << dst << " ";
			while( par.find({sum, prod}) != par.end()) {
				cout << par[{sum, prod}] << " ";
				int i = par[{sum, prod}];
				sum -= i;
				prod *= i;
			}
			cout << endl;
			return;
		}

		FOR(i,1,42) if ( prod % i == 0 && i + sum <= 41 && vis.find({sum+i, prod/i}) == vis.end()) {
			vis.insert({sum+i, prod/i});
			q.push({sum+i, prod/i, dst+1});
			par[{sum+i, prod/i}] = i;
		}
	}

	cout << -1 << endl;
}


int main(){
	int t; cin >> t;
	FOR(i,1,t+1) {
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}
