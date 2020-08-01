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
#define rlll(a,b,c) scanf("%lld %lld %lld", &a, &b, &c)
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
ll x, y, r;
ll sx, sy, l;

ll circle_ec(int x1, int y1) { // 0 is border, 1 is out, -1 is in
	return (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y) - r * r;
}

int main() {
	rlll(x, y, r);
	rlll(sx, sy, l);
	if ( sx <= x && x <= sx + l && sy <= y && y <= sy + l ) {
		printf("2\n");
		return 0;
	}
	int ans = 0;
	FOR(i, 0, l + 1) {
		ll down = circle_ec(sx + i, sy);
		ll up = circle_ec(sx + i, sy + l);
		ll left = circle_ec(sx, sy + i);
		ll right = circle_ec(sx + l, sy + i);
		if ( down < 0 || up < 0 || left < 0 || right < 0 ){
			ans = max(ans, 2);
		}
		if ( down == 0 || up == 0 || left == 0 || right == 0)
			ans = max(ans, 1);
	}
	printf("%d\n", ans);
	return 0;
}