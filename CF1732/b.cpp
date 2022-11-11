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
	int n; ri(n);
	string s; cin >> s;

	int n_c = 0;
	FOR(i, 1, n) {
		int a = s[i] - '0';
		int b = s[i - 1] - '0';
		if (n_c & 1) a = a ^ 1;
		// printf("%d%d\n", b, a);
		if (a < b) {
			// printf("++\n");
			n_c++;
			s[i] = '1';
		}
		else {
			s[i] = a + '0';
		}
	}
	printf("%d\n", n_c);
}


int main() {
	int t; ri(t);
	while (t--) solve();
	return 0;
}