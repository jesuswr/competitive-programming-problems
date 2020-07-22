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
typedef __int128 lll;

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
void print(__int128 x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

lll sum(lll a) {
	return a * (a + 1) / 2;
}

void solve() {
	ll aaaaa, bbbbb;
	rll(aaaaa, bbbbb);
	ll gcd = __gcd(aaaaa, bbbbb);
	aaaaa /= gcd;
	bbbbb /= gcd;

	lll a = aaaaa, b = bbbbb;
	lll low, hig;

	low = 2 * a / b;
	hig = 2 * a / b + 100;

	vector< pair<lll, lll> > ans;
	lll jump = 1;
	//print(low), printf(" "), print(hig); printf("\n");
	for (lll i = max((lll)2, low - 100) ; i <= hig + 25; i += jump) {
		if ( a * (i - 1) % b != 0 )
			continue;
		jump = b;
		lll goal = sum(i) - a * (i - 1) / b;
		if ( goal >= 1 && goal <= i )
			ans.pb({i, goal});
	}
	printf("%lu\n", ans.size());
	for (auto p : ans) {
		print(p.F), printf(" "), print(p.S), printf("\n");
	}

}



int main() {
	int t;
	ri(t);
	while (t--) {
		solve();
	}

	return 0;
}