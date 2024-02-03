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
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N, M;
int DP[5010][24];
ii range[5010][24];
int f(int n, int m) {
	if (n == 0) return 0;
	if (m == 0) return INF;
	if (DP[n][m] != -1) return DP[n][m];

	DP[n][m] = INF;
	FOR(mid,1,n+1) {
		DP[n][m] = min(DP[n][m],  1 + max( f(mid-1, m-1) , f(n-mid, m) )  );
	}
	range[n][m] = {INF,-INF};
	FOR(mid,1,n+1) {
		if (DP[n][m] == 1 + max( f(mid-1, m-1) , f(n-mid, m) )) {
			range[n][m].F = min(range[n][m].F, mid);
			range[n][m].S = mid;
		}
	}
	return DP[n][m];
}


int main(){
	ms(DP,-1);
	cin >> N >> M;
	cout << f(N,M) << ' ';
	if (range[N][M].F == range[N][M].S) cout << range[N][M].F << endl;
	else cout << range[N][M].F << '-' << range[N][M].S << endl;
	return 0;
}
