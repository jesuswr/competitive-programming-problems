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
const ll INFLL = 1e15;
const int MOD = 1e9+7;
const int MAXN = 6e5+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N;
vector<array<int, 3>> A;

int main(){
	ri(N);
	bool c[3] = {0,0,0};
	FOR(i,0,N) {
		A.emplace_back();
		FOR(j,0,3) ri(A[i][j]);
		c[0] |= max(A[i][1], A[i][2]) == 0;
		c[1] |= max(A[i][0], A[i][2]) == 0;
		c[2] |= max(A[i][0], A[i][1]) == 0;
	}

	if (!c[0] || !c[1] || !c[2]) {
		cout << "Infinity" << endl;
		return 0;
	}

	sort(A.begin(), A.end(), [](auto a, auto b) {
		return a[2] < b[2];
	});

	set<pair<int, int>> st;
	ll ans = 0;
	for (auto [x,y,z] : A ) {
		auto it = st.lower_bound({x, -INF});
		if (it != st.end() && it->first == x && it->second <= y) {
			continue;
		}
		if (it != st.begin() && prev(it)->second <= y) {
			continue;
		}
		if (z > 0) {
			auto jt = (it == st.begin() ? it : prev(it));
			for (; jt!=st.end() && jt->second >= y; ++jt) {
				if (next(jt) != st.end()) {
					ans = max(ans, 1ll * jt->second + 1ll * next(jt)->first + 1ll * z);
				}
			}
		}
		for (auto jt=it; jt!=st.end() && jt->second >= y;) {
			st.erase(prev(++jt));
		}
		st.insert({x, y});
	}
	cout << ans-3 << "\n";


	return 0;
}
