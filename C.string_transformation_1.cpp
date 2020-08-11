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
const int maxN = 1e5 + 10; // CAMBIAR ESTE

// GJNM
int n;
char s[2][maxN];


void solve() {
	ri(n);
	scanf("%s", s[0]);
	scanf("%s", s[1]);

	FOR(i, 0, n) {
		if ( s[0][i] > s[1][i] ) {
			printf("-1\n");
			return;
		}
	}
	int ans = 0;
	FOR(c, 0, 20) {
		int go_to = INF;
		FOR(i, 0, n) {
			if ( s[0][i] == 'a' + c && s[0][i] != s[1][i] ) {
				go_to = min(go_to, s[1][i] - 'a');
			}
		}
		if ( go_to != INF )
			ans++;
		FOR(i, 0, n) {
			if ( s[0][i] == 'a' + c && s[0][i] != s[1][i] ) {
				s[0][i] = 'a' + go_to;
			}
		}
	}
	printf("%d\n", ans);
}



int main() {
	int t;
	ri(t);
	while (t--) {
		solve();
	}

	return 0;
}