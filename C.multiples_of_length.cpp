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
ll a[MAXN];

int main() {
	ll n;
	rl(n);
	FOR(i, 0, n) {
		rl(a[i]);
	}
	if ( n == 1 ) {
		printf("1 1\n");
		printf("0\n");
		printf("1 1\n");
		printf("0\n");
		printf("1 1\n");
		printf("%lld\n", -a[0]);
		return 0;
	}

	printf("1 %lld\n", n - 1);
	FOR(i, 0, n - 1) {
		printf("%lld ", (n - 1)*a[i]);
		a[i] = a[i] + (n - 1) * a[i];
	}
	printf("\n");
	printf("%lld %lld\n", n, n);
	printf("%lld\n", -a[n - 1]);
	a[n - 1] = 0;
	printf("%lld %lld\n", 1ll, n );
	FOR(i, 0, n) {
		printf("%lld ", -a[i]);
	}
	printf("\n");
	return 0;
}