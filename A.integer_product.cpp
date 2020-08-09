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
const int maxN = 2e5; // CAMBIAR ESTE

// GJNM
ll cnt[60][60];//?

int main() {
	int n;
	ri(n);
	ll DEN = 1e9;
	FOR(i, 0, n) {
		long double aux;
		scanf("%Lf", &aux);
		ll val = round(DEN * aux);
		int five = 0, two = 0;
		while ( val % 2 == 0 ) {
			two++;
			val /= 2;
		}
		while ( val % 5 == 0 ) {
			five++;
			val /= 5;
		}
		cnt[two][five]++;
	}
	ll ans = 0;
	FOR(i, 0, 60) {
		FOR(j, 0, 60) {
			FOR(ii, 0, 60) {
				FOR(jj, 0, 60) {
					if ( make_pair(i, j) > make_pair(ii, jj) )
						continue;
					if ( i + ii >= 18 && j + jj >= 18 ) {
						if ( i == ii && j == jj ) {
							ans += (cnt[i][j] * (cnt[ii][jj] - 1ll)) / 2ll;
						}
						else {
							ans += (cnt[i][j] * cnt[ii][jj]) ;
						}
					}
				}
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}