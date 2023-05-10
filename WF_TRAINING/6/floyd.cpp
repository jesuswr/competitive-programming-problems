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
const int MAXN = 1e5+69;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N, M, Q;
ll DST[59][59];

int main(){
	rii(N,M), ri(Q);
	FOR(i,0,N) FOR(j,0,N) DST[i][j] = i == j ? 0 : INFLL;
	FOR(i,0,M) {
		int u, v; rii(u,v); int c; ri(c);
		--u, --v;
		DST[u][v] = DST[v][u] = c;
	}

	FOR(k,0,N) FOR(i,0,N) FOR(j,0,N) DST[i][j] = min(DST[i][j], DST[i][k] + DST[k][j]);

	while(Q--) {
		int a,b; rii(a,b); --a, --b;
		if (DST[a][b] >= INFLL) DST[a][b] = -1;
		cout << DST[a][b] << endl;
	}

	return 0;
}
