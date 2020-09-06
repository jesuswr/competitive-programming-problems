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

int main() {
	int n;
	ri(n);
	printf("1\n");
	fflush(stdout);
	int dst;
	ri(dst);
	if (dst == 0) {
		printf("! 1\n");
		fflush(stdout);
		return 0;
	}
	int curr = 1;
	int left = 2, right = 3;
	while (true) {
		left = 2 * curr, right = 2 * curr + 1;
		int dst2;
		printf("%d\n", left);
		fflush(stdout);
		ri(dst2);
		if (dst2 < dst) {
			dst = dst2;
			curr = left;
		}
		else {
			dst = dst - 1;
			curr = right;
		}

		if (dst == 0) {
			printf("! %d\n", curr);
			fflush(stdout);
			return 0;
		}

	}


	return 0;
}