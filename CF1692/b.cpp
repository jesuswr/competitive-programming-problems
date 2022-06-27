#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) scanf("%lld", &a)
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


int main() {
	int t; ri(t);
	while (t--) {
		int n; ri(n);
		map<int, int> cnt;
		FOR(i, 0, n) {
			int a; ri(a);
			cnt[a]++;
		}
		int aux = 0;
		for (auto [a, cnta] : cnt) {
			if (cnta > 1) aux += cnta - 1;
		}
		printf("%d\n", n - 2 * ((aux + 1) / 2));
	}

	return 0;
}