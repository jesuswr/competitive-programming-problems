#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dasdas;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) dasdas=scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) dasdas=scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 2e5+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int A[MAXN][26];

int main(){
	int n; ri(n);
	FOR(i,0,n) {
		string s; cin >> s;
		for(char c : s) A[i][c - 'a']++;
		// cout << i + 1 << " :  ";
		FOR(j,0,26) {
			if (A[i][j] & 1) A[i][j] = 1;
			else if (A[i][j] > 1) A[i][j] = 2;
			// cout << A[i][j];
		}
		// cout << endl;
	}

	ll ans = 0;
	FOR(b,0,26) {
		int msk = (1 << 26) - 1 - (1 << b);
		unordered_map<int, int> cnt;
		cnt.reserve(n/2);
		FOR(i,0,n) if (!A[i][b]) {
			int m = 0;
			FOR(j,0,26) if (A[i][j] == 1) m |= (1 << j);
			int cm = (m ^ msk);
			ans += cnt[cm];
			cnt[m]++;
		}
	}
	cout << ans << endl;

	return 0;
}
