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

int M, N;
vi G[MAXN];
int VIS;
int REACH[30];

bool isOn(int msk, int b) {
	return (msk >> b) & 1;
}

void dfs(int u) {
	VIS |= (1 << u);
	for(int v : G[u]) if (!isOn(VIS, v)) {
		dfs(v);
	}
}

int main(){
	rii(M,N);
	FOR(_,0,M) {
		char u,v; cin >> u >> v;
		G[u-'a'].pb(v-'a');
	}
	FOR(i,0,26) {
		VIS = 0;
		dfs(i);
		REACH[i] = VIS;
	}

	FOR(_,0,N) {
		string a,b; cin >> a >> b;
		bool good = sz(a) == sz(b);
		if (!good) {
			cout << "no\n";
			continue;
		}

		FOR(i,0,sz(a)) {
			int x = a[i] - 'a', y = b[i] - 'a';
			good &= isOn(REACH[x], y);
		}

		if (good) cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}
