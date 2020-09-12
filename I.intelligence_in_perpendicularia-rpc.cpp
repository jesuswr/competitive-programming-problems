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
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
int n;
pii points[1100];
int hor[(int)3e6], ver[(int)3e6];

int main() {
	ri(n);
	FOR(i, 0, n) {
		rii(points[i].F, points[i].S);
		points[i].F += 1e6;
		points[i].S += 1e6;
	}
	FOR(i, 0, n) {
		if ( points[i].S == points[(i + 1) % n].S ) {
			int low = min(points[i].F, points[(i + 1) % n].F);
			int high = max(points[i].F, points[(i + 1) % n].F);
			hor[low]++;
			hor[high]--;
		}
		else {
			int low = min(points[i].S, points[(i + 1) % n].S);
			int high = max(points[i].S, points[(i + 1) % n].S);
			ver[low]++;
			ver[high]--;
		}
	}
	FOR(i, 1, 2e6 + 10) {
		ver[i] += ver[i - 1];
		hor[i] += hor[i - 1];
	}
	ll ans = 0;
	FOR(i, 0, 2e6 + 10) {
		ans += (ver[i] > 2 ? ver[i] - 2 : 0);
		ans += (hor[i] > 2 ? hor[i] - 2 : 0);
	}
	printf("%lld\n", ans);
	return 0;
}