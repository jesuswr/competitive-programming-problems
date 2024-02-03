#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define ri(a) scanf("%d", &a)
#define rii(a, b) ri(a), ri(b)
#define lri(a) scanf("%lld", &a)
#define lrii(a, b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second 
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 80;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int n;
bitset<MAXN> B[MAXN];

uint nextMask(uint mask) {
	uint t = mask | (mask - 1);
	return (t+1) | (((~t & -~t) - 1) >> (__builtin_ctz(mask) + 1));
}

int solve(int m) {
	bitset<MAXN> bb;
	for(uint mask = (1<<m)-1; !(mask & (1<<n)); mask = nextMask(mask)) {
		bb.reset();
		FOR(i,0,n) if (mask>>i&1) bb = bb | B[i];

		if (bb.count() == (size_t)n) return mask;
	}

	return -1;
}


char tmp[MAXN];

int main() {
	int tc = 0;
	while(ri(n) != EOF) {
		FOR(i,0,n) {
			scanf("%s", tmp);
			FOR(j,0,n) B[i][j] = (i == j || tmp[j] == '1');
		}

		int i = 0;
		int msk = 0;
		while ((msk = solve(++i)) == -1);

		printf("Case %d: %d", ++tc, i);
		FOR(i,0,n) if (msk>>i&1) printf(" %d", i+1);
		printf("\n");

		FOR(i,0,n) B[i].reset();
	}

	return 0;
}

