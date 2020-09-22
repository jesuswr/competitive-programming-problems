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
const int MAXN = 1e5 + 10; // CAMBIAR ESTE

// GJNM
string s[MAXN], s_rev[MAXN];
bool ord[MAXN][2][2];
ll c[MAXN];
int n;
ll dp[MAXN][2];
bool vis[MAXN][2];

ll f(int pos, int last_rev) {
	if (pos == n)
		return 0;
	if (vis[pos][last_rev])
		return dp[pos][last_rev];
	vis[pos][last_rev] = true;
	dp[pos][last_rev] = LLINF;

	if (ord[pos][last_rev][0])
		dp[pos][last_rev] = min(dp[pos][last_rev], f(pos + 1, 0));
	if (ord[pos][last_rev][1])
		dp[pos][last_rev] = min(dp[pos][last_rev], f(pos + 1, 1) + c[pos]);

	return dp[pos][last_rev];
}

int main() {
	ri(n);
	n++;
	FOR(i, 1, n) {
		rl(c[i]);
	}
	s[0] = "";
	FOR(i, 1, n) {
		cin >> s[i];
		s_rev[i] = s[i];
		reverse(s_rev[i].begin(), s_rev[i].end());
	}
	FOR(i, 1, n) {
		if (s[i - 1].compare(s[i]) <= 0)
			ord[i][0][0] = true;
		if (s_rev[i - 1].compare(s[i]) <= 0)
			ord[i][1][0] = true;
		if (s[i - 1].compare(s_rev[i]) <= 0)
			ord[i][0][1] = true;
		if (s_rev[i - 1].compare(s_rev[i]) <= 0)
			ord[i][1][1] = true;
	}
	if (f(1,0)>=LLINF)
		printf("-1\n");
	else
		printf("%lld\n", f(1,0));

	return 0;
}