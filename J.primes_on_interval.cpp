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
const int maxN = 1e6 + 10; // CAMBIAR ESTE

// GJNM
bool NotPrime[maxN];
int PCOUNT[maxN];

bool valid(int left, int right, int length, int need) {
	FOR(i, left, right - length + 2) {
		if ( PCOUNT[i + length - 1] - PCOUNT[i - 1] < need)
			return false;
	}
	return true;
}


int main() {
	FOR(i, 2, maxN) {
		if ( NotPrime[i] )
			continue;
		int act = i + i;
		while (act < maxN) {
			NotPrime[act] = true;
			act += i;
		}
	}
	FOR(i, 2, maxN) {
		PCOUNT[i] = !NotPrime[i];
		PCOUNT[i] += PCOUNT[i - 1];
	}

	int a, b, k;
	riii(a, b, k);
	if ( PCOUNT[b] - PCOUNT[a - 1] < k ) {
		printf("-1\n");
		return 0;
	}

	int lo = 1, hi = b - a + 1;
	while ( lo < hi ) {
		int mid = lo + (hi - lo) / 2;

		if ( valid(a, b, mid, k) )
			hi = mid;
		else
			lo = mid + 1;
	}
	printf("%d\n", hi);
	return 0;
}