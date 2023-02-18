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

const int INF = 1e9;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 15;
const int MXSZ = 1 << MAXN; 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N, A[MAXN];
int SM[MXSZ];
int PRV[MAXN+1][MAXN+1][MXSZ];


void solve() {
	ri(N);
	FOR(i,0,N) ri(A[i]);

	FOR(i,0,N) SM[1 << i] = A[i];
	FOR(msk, 3, 1 << N) {
		int x = msk & (1 - msk);
		int y = msk ^ x;
		SM[msk] = SM[x] + SM[y];
	}

	vector< vector < vector<int> > > DP(N+1, vector< vector<int>>(N+1, vector<int>(1 << N, INF)));
	DP[0][0][0] = 0;
	FOR(pos, 0, N) FOR(cnt, 0, N + 1) FOR(msk, 0, 1 << N) if (DP[pos][cnt][msk] < INF) {
		if (DP[pos + 1][cnt][msk] > DP[pos][cnt][msk]) {
			DP[pos + 1][cnt][msk] = DP[pos][cnt][msk];
			PRV[pos + 1][cnt][msk] = 0;
		}

		// cout << pos << " " << cnt << " " << msk << " : " << DP[pos][cnt][msk] << endl;

		int c_msk = (1 << N) - 1;
		c_msk ^= msk;
		if ( c_msk & (1 << pos) ) { // no he usado a[pos]
			for(int n_msk = c_msk; n_msk; n_msk = (n_msk - 1) & c_msk) if (n_msk & (1 << pos)) {
				// cout << "\t" << pos << " " << cnt+1 << " " << (msk | n_msk) << endl;
				if (SM[n_msk] > DP[pos][cnt][msk] && SM[n_msk] < DP[pos][cnt + 1][msk | n_msk]) {
					// cout << "\t\t entro" << endl;
					DP[pos][cnt+1][msk | n_msk] = SM[n_msk];
					PRV[pos][cnt+1][msk | n_msk] = n_msk;
				}
			}
		} 
	}

	int mx = 1;
	FOR(i,0,N+1) if (DP[N][i][(1 << N) - 1] < INF) mx = i;

	vii moves;
	int p = N, c = mx, m = (1 << N) - 1;
	while(c > 0) {
		if (PRV[p][c][m]) {
			FOR(i,0,N) if (i != p && (PRV[p][c][m] & (1 << i))) {
				moves.pb({i, p});
			}
			m = m ^ PRV[p][c][m];
			--c;
		}
		else {
			--p;
		}
	}

	cout << sz(moves) << endl;
	FOR(i,0,sz(moves)) {
		auto [a,b] = moves[i];
		// cout << "\t" << a + 1 << " " << b + 1 << endl;
		int ma = -1, mb = -1;
		FOR(j,0,i) {
			auto [c,_] = moves[j];
			if (a > c) ++ma;
			if (b > c) ++mb;
		}
		cout << a - ma << " " << b - mb << endl;
	}


}


int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}
