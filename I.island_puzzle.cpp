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
vector<int> have;
vector<int> want;

int main() {
	int n;
	ri(n);
	int have_ind, want_ind;
	FOR(i, 0, n) {
		int aux; ri(aux);
		if ( aux != 0 )
			have.pb(aux);
	}
	FOR(i, 0, n) {
		int aux; ri(aux);
		if ( aux != 0 )
			want.pb(aux);
	}
	n--;
	FOR(i, 0, n) {
		if ( have[i] == 1 )
			have_ind = i;
		if ( want[i] == 1 )
			want_ind = i;
	}

	FOR(i, 0, n) {
		if ( have[have_ind] != want[want_ind] ) {
			printf("NO\n");
			return 0;
		}
		have_ind++; have_ind %= n;
		want_ind++; want_ind %= n;
	}
	printf("YES\n");

	return 0;
}