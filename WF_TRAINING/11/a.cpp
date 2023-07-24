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
const int MAXN = 11;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N, K, M;
int C[MAXN];
int MSK[MAXN];
int SS_MSK[1 << MAXN];

int upd_msk(int msk, int lock, int col) {
	int ret = msk;
	FOR(b,0,N) {
		if (lock & (1 << b)) continue;
		
		if (col == C[b]) 
			ret |= (1 << b);
		else {
			ret |= (1 << b);
			ret ^= (1 << b);
		}
	}
	return ret;
}

bool VIS[1 << MAXN][1 << MAXN];
int  DST[1 << MAXN][1 << MAXN];

int main(){
	rii(N,K), ri(M);
	FOR(i,0,N) ri(C[i]);
	FOR(i,0,N) C[i]--;

	FOR(i,0,M) {
		int ni; ri(ni);
		FOR(_,0,ni) {
			int b; ri(b); --b;
			MSK[i] |= (1 << b);
		}
	}

	FOR(msk,0,1<<M) {
		FOR(b,0,M) if (msk & (1 << b)) {
			SS_MSK[msk] |= MSK[b];
		}
	}

	int nmsk = upd_msk(0, 0, 0);
	int mmsk = 0;

	queue< ii > q;
	q.push({nmsk, mmsk});
	VIS[nmsk][mmsk] = 1;
	while(!q.empty()) {
		auto [a, b] = q.front(); q.pop();
		// cout << a << " " << b << endl;
		if (a == (1 << N) - 1 && b == 0) {
			cout << DST[a][b] << endl;
			return 0;
		}

		// paint
		FOR(col,0,K) {
			int na = upd_msk(a, SS_MSK[b], col);
			// cout << "    " << na << endl;
			if (!VIS[na][b]) {
				VIS[na][b] = 1;
				DST[na][b] = DST[a][b] + 1;
				q.push({na, b});
			}
		}
		// add
		FOR(cas,0,M) if (b != (b | (1 << cas))) {
			int nb = b | (1 << cas);
			if (!VIS[a][nb]) {
				VIS[a][nb] = 1;
				DST[a][nb] = DST[a][b] + 1;
				q.push({a, nb});
			}
		}
		// rem
		FOR(cas,0,M) if (b == (b | (1 << cas))) {
			int nb = b ^ (1 << cas);
			if (!VIS[a][nb]) {
				VIS[a][nb] = 1;
				DST[a][nb] = DST[a][b] + 1;
				q.push({a, nb});
			}
		}


	}
	cout << -1 << endl;
	return 0;
}
