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

int main() {
	ll a, b, w, x, c;
	rll(a, b), rll(w, x), rl(c);
	//printf("a:%lld b:%lld w:%lld x:%lld c:%lld\n", a, b, w, x, c);
	if ( c <= a ) {
		printf("0\n");
		return 0;
	}

	ll ans = 0;
	ll need_b = (c - a) * x;
	if ( b < need_b ) {
		ll dist = (need_b - b + w - x - 1) / (w - x);
		b += dist * (w - x);
		ans += dist;
	}
	ans += max(0ll, c - a);
	printf("%lld\n", ans);
	return 0;
}