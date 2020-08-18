#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM
int n;
ll mat[30][30];

void fill() {
	ll aux = -1;
	FOR(r, 0, n) {
		FOR(c, 0, n) {
			if ( r & 1 ) {
				mat[r][c] = (1ll << ( aux + c ));
			}
			else {
				mat[r][c] = 0;
			}
		}
		aux++;
	}
	FOR(r, 0, n) {
		FOR(c, 0, n) {
			printf("%lld ", mat[r][c]);
		}
		printf("\n");
	}
	fflush(stdout);
}

void solve(ll k) {
	int r = 0, c = 0;
	FOR(i, 0, n) {
		if ( i == n - 1 ) {
			while ( c < n  ) {
				printf("%d %d\n", r + 1, 1 + c++);
			}
			continue;
		}

		if ( i & 1 ) {
			printf("%d %d\n", r + 1, c + 1);
			while ( c < n - 1 && ((mat[r][c + 1] & k) != 0) ) {
				printf("%d %d\n", r + 1, ++c + 1);
			}
			r++;
		}
		else {
			printf("%d %d\n", r + 1, c + 1);
			while ( (mat[r + 1][c] & k) == 0 ) {
				printf("%d %d\n", r + 1, ++c + 1 );
			}
			r++;
		}
	}

	fflush(stdout);

}



int main() {
	ri(n);
	fill();

	int q;
	ri(q);
	while (q--) {
		ll k;
		rl(k);
		solve(k);
	}

	return 0;
}