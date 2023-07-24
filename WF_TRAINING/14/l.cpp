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
const int MAXN = 2e5+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N;
int A[MAXN];
int PINC[MAXN], PNINC[MAXN];

int main(){
	ri(N);
	FOR(i,0,N) ri(A[i]);
	FOR(i,1,N) {
		PINC[i] = PINC[i-1] + (A[i] >= A[i-1]);
		PNINC[i] = PNINC[i-1] + (A[i] < A[i-1]);
	}

	vii DP(N+1, {0,0});

	int q; ri(q);
	while(q--) {
		int l; ri(l);
		if (DP[l].F != 0) {
			printf("%d %d\n", DP[l].F, DP[l].S);
			continue;
		}

		int sub = 0, bad = 0;
		int i = 0;
		while(i < N) {
			int lo = 1, hi = N - i;
			while(lo < hi) {
				int mi = lo + (hi - lo + 1) / 2;
				if ( PINC[i + mi - 1] - PINC[i] == mi - 1 || PNINC[i + mi - 1] - PNINC[i] == mi - 1 )
					lo = mi;
				else
					hi = mi-1;
			}

			if (lo == N - i) lo = N;
			bad += max(0, min(l, N-i) - lo);
			sub++;
			i += max(l, lo);
		}

		DP[l] = {sub, bad};
		printf("%d %d\n", sub, bad);
	}
	return 0;
}
