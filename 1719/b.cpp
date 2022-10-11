#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dsadsa;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) dsadsa = scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) dsadsa = scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}


void solve() {
	ll n, k; lrii(n, k);
	int CNT[4] = {0, 0, 0, 0};
	k %= 4;
	if (k == 0) {
		printf("NO\n");
		return;
	}

	if (k & 1) {
		printf("YES\n");
		for (int i = 0; i < n; i += 2) printf("%d %d\n", i + 1, i + 2);
	}
	else {
		printf("YES\n");
		for (int i = 0; i < n; i += 2) {
			if ((i + 2) % 4 == 0)
				printf("%d %d\n", i + 1, i + 2);
			else
				printf("%d %d\n", i + 2, i + 1);
		}
	}

}


int main() {
	int t; ri(t);
	while (t--) solve();
	return 0;
}