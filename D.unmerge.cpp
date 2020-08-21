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
const int MAXN = 9000; // CAMBIAR ESTE
int OFFSET = 4500;

// GJNM
int n;
int p[MAXN];
bool dp[MAXN][MAXN], vis[MAXN][MAXN];
vi counts;

bool f(int sm, int pos) {
	if ( pos == n ) {
		return sm == 0;
	}
	if (vis[sm + OFFSET][pos])
		return dp[sm + OFFSET][pos];
	vis[sm + OFFSET][pos] = true;

	dp[sm + OFFSET][pos] = f(sm + counts[pos], pos + 1) | f(sm - counts[pos], pos + 1);
	//printf("%d %d %d %d\n", sm, pos, counts[pos], dp[sm + OFFSET][pos]);
	return dp[sm + OFFSET][pos];
}

void solve() {
	ri(n);
	FOR(i, 0, 2 * n) {
		ri(p[i]);
	}
	p[2 * n] = INF;
	counts.clear();

	int i = 0;
	while (i < 2 * n) {
		int j = i;
		while ( p[j] <= p[i] )
			j++;
		counts.pb(j - i);
		i = j;
	}

	n = counts.size();
	FOR(i, 0, MAXN) {
		FOR(j, 0, n) {
			vis[i][j] = false;
		}
	}
	//printf("%d\n", n);
	//for (auto x : counts)
	//	printf("%d ", x);
	//printf("\n");
	if ( f(0, 0) )
		printf("YES\n");
	else
		printf("NO\n");
}



int main() {
	int t;
	ri(t);
	while (t--) {
		solve();
	}
	return 0;
}