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
const int MAXN = 1500+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N;
int MAT[MAXN][MAXN];
ii WHERE[MAXN*MAXN];


int main(){
	ri(N);
	FOR(i,0,N) {
		FOR(j,0,N) {
			ri(MAT[i][j]);
			WHERE[MAT[i][j]] = {i,j};
		}
	}
	ll ans = 0;
	vi cntr(N), cntc(N);
	for(int i = N*N; i >= 1; --i) {
		ii pos = WHERE[i];
		int row = pos.F, col = pos.S;
		ans += cntr[row] * (N - 1 - cntc[col]) + cntc[col] * (N - 1 - cntr[row]);
		cntr[row] += 1;
		cntc[col] +=1;
	}
	cout << ans / 2 << endl;

	return 0;
}
