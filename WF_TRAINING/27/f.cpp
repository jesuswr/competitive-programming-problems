#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int das;
#define FOR(i,n,m) for (int i = n; i < (int)m; i++)
#define ROF(i,n,m) for (int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj, val, sizeof(obj))
#define ri(a) das=scanf("%d", &a)
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
const int MOD = 1e9+7;
const int MAXN = 2e5+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N;
vi A;

ll R;
ll ROW[2500 * 90];
int V[2500 * 90];

int go(int len) {
	int mx = 0;
	int i = 0;
	++R;++R;
	while(i < sz(A)) {
		int curr = A[i];
		i++;
		vii inds;
		while(i < sz(A) && curr + 1 + A[i] <= len) {
			inds.pb({curr,0});
			curr = curr + 1 + A[i];
			i++;
		}

		FOR(j,0,sz(inds)) {
			auto [col, _] = inds[j];
			int val = 0;
			if (ROW[col] == R) 
				val = V[col] + 1;
			else 
				val = 1;
			mx = max(mx, val);
			inds[j] = {col, val};
		}

		++R;

		for(auto [col, val] : inds) {
			for(int delta : {1,0,-1}) {
				int next_col = col + delta;
				if (ROW[next_col] != R) {
					ROW[next_col] = R;
					V[next_col] = val;
				}
				else 
					V[next_col] = max(V[next_col], val);
			}
		}
	}
	return mx;
}


int main() {
	ri(N);
	int mn = 1, mx = N * 80 + N;
	FOR(i,0,N) {
		string s; cin >> s;
		A.pb(sz(s));
		mn = max(mn, sz(s));
	}

	ii ans = {0,0};
	FOR(i,mn,mx) {
		int result = go(i);
		if (result > ans.F) {
			ans = {result, i};
		}
	}
	cout << ans. S << " " << ans.F << endl;
	return 0;
}
