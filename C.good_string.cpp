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
void solve() {
	string s;
	cin >> s;
	int mn = s.size() + 1;
	FOR(i, 0, 10) {
		FOR(j, 0, 10) {
			int tot = s.size();
			bool f = true;
			FOR(k, 0, s.size()) {
				if ( f ) {
					if ( s[k] == i + '0' )
						f = false;
				}
				else {
					if ( s[k] == j + '0' ) {
						f = true;
						tot -= 2;
					}
				}
			}
			mn = min(tot, mn);
		}
	}

	FOR(i, 0, 10) {
		int tot = s.size();
		FOR(j, 0, s.size()) {
			if ( s[j] == '0' + i )
				tot--;
		}
		mn = min(tot, mn);
	}
	printf("%d\n", mn);
}

int main() {
	int t;
	ri(t);
	while (t--) {
		solve();
	}

	return 0;
}