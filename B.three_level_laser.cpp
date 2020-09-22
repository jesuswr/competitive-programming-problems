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
const int MAXN = 1e5 + 1; // CAMBIAR ESTE

// GJNM
int E[MAXN];

int main() {
	int n, u;
	rii(n, u);
	FOR(i, 0, n)
	ri(E[i]);
	long double ans = -1;
	FOR(i, 0, n - 2) {
		auto it = upper_bound(E + i + 1, E + n, u + E[i]);
		it--;
		int k = it - E;
		if (k > i + 1) {
			ans = max(ans, (long double)(E[k] - E[i + 1]) / (E[k] - E[i]));
		}

	}
	if (ans > -0.5)
		printf("%.10Lf\n", ans);
	else
		printf("-1\n");

	return 0;
}