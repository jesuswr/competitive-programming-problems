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
int A[200];
int LEN[200][200], ANS[200][200];


int main() {
	int t;
	ri(t);
	while (t--) {
		int n;
		ri(n);
		FOR(i, 1, n + 1)
		ri(A[i]);
		FOR(i, 1, n + 1) {
			vi seq; seq.reserve(n - i + 1);
			FOR(j, i, n + 1) {
				if ( seq.empty() || A[j] > seq.back() )
					seq.pb(A[j]);
				else {
					auto it = lower_bound(seq.begin(), seq.end(), A[j]);
					*it = A[j];
				}
				LEN[i][j] = seq.size();
			}
		}
		FOR(k, 1, n + 1) {
			FOR(i, 1, n + 1) {
				int j = 1;
				ANS[k][i] = 0;
				while (LEN[j][i] >= k) {
					ANS[k][i] = max(ANS[k][i], ANS[k][j - 1] + LEN[j][i]);
					j++;
				}
			}
		}
		FOR(i, 1, n + 1) {
			printf("%d%c", ANS[i][n], " \n"[i == n] );
		}
	}

	return 0;
}