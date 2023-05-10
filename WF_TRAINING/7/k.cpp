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
const int MAXN = 1e6+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N, Q, T=1;
ll G[26][26];
ll ALL;
int NXT[MAXN][26], CNT[MAXN];
void insert(const string &s) {
	int u = 0;
	for(const char c : s) {
		int nxt = c - 'a';
		FOR(i,0,26) if (i != nxt && NXT[u][i] != 0) {
			G[nxt][i] += CNT[NXT[u][i]];
		}
		if (!NXT[u][nxt]) {
			NXT[u][nxt] = T++;
		}
		u = NXT[u][nxt];
		CNT[u] += 1;
	}
	FOR(i,0,26) if (NXT[u][i] != 0) {
		ALL += CNT[NXT[u][i]];
	}
}



int main(){
	rii(N,Q);
	FOR(_,0,N) {
		string s; cin >> s;
		insert(s);
	}
	FOR(_,0,Q) {
		string ord; cin >> ord;
		ll ans = ALL;
		FOR(i,0,26) FOR(j,i+1,26) {
			ans += G[ ord[i] - 'a' ][ ord[j] - 'a' ];
		}
		printf("%lld\n", ans);
	}

	return 0;
}
