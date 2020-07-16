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
const int maxN = 1 << 24 ; // CAMBIAR ESTE

// GJNM
int aux;
int n;
int X[30], Y[30];
int x, y;

int dp[maxN + 10];
pii M[maxN + 10];

int DST(int x1, int y1, int x2, int y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int f(int btmsk) {
	if ( btmsk == (1 << n) - 1 )
		return 0;
	if ( dp[btmsk] != 0 )
		return dp[btmsk];

	int &ret = dp[btmsk];
	ret = INF;

	FOR(i, 0, n) {
		if ( btmsk & (1 << i) )
			continue;

		aux = 2 * DST(x, y, X[i], Y[i]) + f(btmsk | (1 << i));
		if ( aux < ret ) {
			ret = aux;
			M[btmsk] = {i + 1, -1};
		}
		break;
	}

	FOR(i, 0, n) {
		if ( btmsk & (1 << i) )
			continue;
		FOR(j, i + 1, n) {
			if ( btmsk & (1 << j) )
				continue;

			aux = DST(x, y, X[i], Y[i]) + DST(x, y, X[j], Y[j])
			      + DST(X[i], Y[i], X[j], Y[j])
			      + f(btmsk | (1 << i) | (1 << j));

			if ( aux < ret ) {
				ret = aux;
				M[btmsk] = {i+1, j+1};
			}
		}
		break;
	}

	return ret;
}



int main() {
	rii(x, y);
	ri(n);
	FOR(i, 0, n) {
		rii(X[i], Y[i]);
	}

	int ans = f(0);
	printf("%d\n", ans);
	printf("0 ");
	int btmsk = 0;
	while (btmsk != (1 << n) - 1) {
		if ( M[btmsk].S == -1 ) {
			printf("%d 0 ", M[btmsk].F);
			btmsk = btmsk | (1 << (M[btmsk].F - 1));
		}
		else {
			printf("%d %d 0 ", M[btmsk].F, M[btmsk].S);
			btmsk = btmsk | (1 << (M[btmsk].F - 1) ) | (1 << (M[btmsk].S - 1) );
		}

	}
	printf("\n");
	return 0;
}