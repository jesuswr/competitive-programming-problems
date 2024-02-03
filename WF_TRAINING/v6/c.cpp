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
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}


int N, M, K;
bool W[MAXN];
vi G[MAXN];

vi bfs(int s) {
	vi dst(N, INF);
	queue<int> q;
	q.push(s);
	dst[s] = 0;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int v : G[u]) if (dst[v] == INF) {
			dst[v] = dst[u] + 1;
			q.push(v);
		}
	}
	return dst;
}


int main(){
	rii(N,M), ri(K);
	FOR(i,0,K) {
		int a; ri(a);
		W[a-1] = 1;
	}
	FOR(_,0,M) {
		int a,b; rii(a,b);
		G[a-1].pb(b-1);
		swap(a,b);
		G[a-1].pb(b-1);
	}

	vi fromS = bfs(0), fromE = bfs(N-1);
	int op1 = fromS[N-1];
	ll sm = INFLL;
	ll aux = 0;
	FOR(i,0,N) if (W[i]) aux += fromE[i];
	FOR(i,0,N) if (W[i]) sm = min(sm, 1ll * (K-1) * fromS[i] + (aux - fromE[i]));

	--K;
	ll gcd = __gcd(sm, 1ll*K);
	sm /= gcd;
	K /= gcd;
	if (1ll * op1 * K <= sm) printf("%d/1\n", op1);
	else printf("%lld/%d\n", sm, K);


	return 0;
}
