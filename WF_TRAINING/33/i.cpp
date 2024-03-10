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
const int MAXN = 2e5+5;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N;

vi query(vi vec) {
	cout << "QUERY ";
	for(int x : vec) cout << x;
	cout << endl;
	vi ret(N);
	FOR(i,0,N) ri(ret[i]);
	return ret;
}

int main(){
	ri(N);

	vector<int> q(N,1);
	vector<int> deg = query(q);
	vector< vector<int> > Qs(15);

	FOR(bit,0,15) {
		FOR(i,0,N) q[i] = (i >> bit) & 1;
		Qs[bit] = query(q);
	}

	queue<int> qu;
	vii Es;

	FOR(i,0,N) if (deg[i] == 1) qu.push(i);

	while(!qu.empty()) {
		int u = qu.front();
		qu.pop();
		if (deg[u] == 0) break;

		int fat = 0;
		FOR(bit,0,15) if ( Qs[bit][u] ) fat += (1 << bit);

		Es.pb({fat, u});

		deg[fat]--;
		if (deg[fat] == 1) qu.push(fat);

		FOR(bit,0,15) if ( (u >> bit) & 1 ) Qs[bit][fat]--;
	}

	cout << "ANSWER" << endl;
	for(auto [a,b] : Es) cout << a + 1 << " " << b + 1 << endl;

	return 0;
}
