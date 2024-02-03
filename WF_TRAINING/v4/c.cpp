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
const int MAXN = 100+5;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int _i;
map<string, int> _ind;
int transform(string &a) {
	if (_ind.find(a) != _ind.end()) return _ind[a];
	return _ind[a] = _i++;
}

int N;
bool VIS[MAXN];
int H[MAXN];
vi G[MAXN];

int ANS;
void dfs(int u) {
	VIS[u] = 1;

	for(int v : G[u]) {
		if (VIS[v]) {
			ANS = max(ANS, H[u] - H[v] + 1);
		}
		else {
			H[v] = H[u] + 1;
			dfs(v);
		}
	}

	VIS[u] = 0;
}


int main(){
	cin >> N;
	FOR(_,0,N) {
		string a,b,c; cin >> a >> b >> c;
		int bi = transform(b), ci = transform(c);
		G[bi].pb(ci);
	}

	N = _i;
	FOR(i,0,N) {
		H[i] = 0;
		dfs(i);
	}

	if (ANS == 0) cout << "No trades possible" << endl;
	else cout << ANS << endl;


	return 0;
}
