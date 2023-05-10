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
const ll MOD = 998244353;
const int MAXN = 2e5+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N;
vi G[MAXN];
ll D2[MAXN];
ll ANS = 1;

int go(int u, int f = -1) {
	int cnt = 0;
	for(int v : G[u]) if (v != f) {
		cnt += go(v, u);
	}

	if (cnt & 1) {
		if (u == 1) ANS = 0;
		else {
			ll aux = cnt * D2[cnt - 1] % MOD;
			ANS = (ANS * aux) % MOD;
		}
		return 0;
	}
	else {
		ANS = (ANS * D2[cnt]) % MOD;
		return 1;
	}
}

int main(){
	D2[0] = 1;
	for(int i = 2; i < MAXN; i += 2) D2[i] = ((i - 1) * D2[i-2]) % MOD;
	ri(N);
	FOR(i,1,N) {
		int u,v; rii(u,v);
		G[u].pb(v);
		G[v].pb(u);
	}
	go(1);
	cout << ANS << endl;
	return 0;
}
