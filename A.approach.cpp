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
struct point {
	long double x, y;
};

long double dist(point a, point b) {
	return sqrt( (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) );
}

point get_ft(point a, point b, long double t, long double alpha) {
	point ret;
	if (a.x <= b.x)
		ret.x = a.x + cos(alpha) * t;
	else
		ret.x = a.x - cos(alpha) * t;

	if (a.y <= b.y)
		ret.y = a.y + sin(alpha) * t;
	else
		ret.y = a.y - sin(alpha) * t;
	return ret;
}


int main() {
	point a, b, c, d;
	scanf("%Lf %Lf %Lf %Lf", &a.x, &a.y, &b.x, &b.y);
	scanf("%Lf %Lf %Lf %Lf", &c.x, &c.y, &d.x, &d.y);
	if ( dist(a, b) > dist(c, d) )
		swap(a, c), swap(b, d);
	long double ans = dist(a, c);

	if ( dist(a, b) > 0 ) {
		long double alpha1 = asin(abs(a.y - b.y) / dist(a, b));
		long double alpha2 = asin(abs(c.y - d.y) / dist(c, d));

		long double lo = 0, hi = dist(a, b);
		FOR(_, 0, 200) {
			long double mid1 = lo + (hi - lo) / 3;
			long double mid2 = hi - (hi - lo) / 3;
			if ( dist( get_ft(a, b, mid1, alpha1), get_ft(c, d, mid1, alpha2) ) <= dist( get_ft(a, b, mid2, alpha1), get_ft(c, d, mid2, alpha2) )) {
				hi = mid2;
				ans = min(ans, dist( get_ft(a, b, mid1, alpha1), get_ft(c, d, mid1, alpha2) ));
			}
			else {
				lo = mid1;
				ans = min(ans, dist( get_ft(a, b, mid2, alpha1), get_ft(c, d, mid2, alpha2) ));
			}
		}

	}
	if ( dist(c, d) - dist(a, b) > (long double)1e-6 ) {
		long double alpha2 = asin(abs(c.y - d.y) / dist(c, d));

		long double lo = dist(a,b), hi = dist(c, d);
		FOR(_, 0, 200) {
			long double mid1 = lo + (hi - lo) / 3;
			long double mid2 = hi - (hi - lo) / 3;

			if ( dist( b, get_ft(c, d, mid1, alpha2) ) <= dist( b, get_ft(c, d, mid2, alpha2) )) {
				hi = mid2;
				ans = min(ans, dist( b, get_ft(c, d, mid1, alpha2) ));
			}
			else {
				lo = mid1;
				ans = min(ans, dist( b, get_ft(c, d, mid2, alpha2) ));
			}
		}

	}

	printf("%.12Lf\n", ans);
	return 0;
}