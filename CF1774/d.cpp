#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int das;
#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) das=scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) das=scanf("%lld", &a)
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
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N, M;
vi A[MAXN];

void solve() {
	rii(N, M);
	FOR(i,0,N) {
		A[i].resize(M);
		FOR(j,0,M) ri(A[i][j]);
	}

	int tot = 0;
	FOR(i,0,N) FOR(j,0,M) tot += A[i][j];

	if (tot % N != 0) {
		cout << -1 << endl;
		return;
	}

	vi rowCnt(N);
	vector<set<int>> colRem(M);
	int need = tot / N;

	FOR(i,0,N) FOR(j,0,M) rowCnt[i] += A[i][j]
	FOR(i,0,N) FOR(j,0,M) if (A[i][j] && rowCnt[i] > need) 
		colRem[j].insert(i);

	vector<tuple<int, int, int>> ans;
	FOR(i,0,N) {
		if (need <= rowCnt[i]) continue;

		for(int j = 0; j < M && rowCnt[i] < need; j++) {
			if (sz(colRem[j]) > 0) {
				int otherRow = *colRem[j].begin();
				rowCnt[otherRow]--;
				rowCnt[i]++;
				colRem[j].erase(otherRow);
				ans.pb({i, otherRow, j});

				if (rowCnt[otherRow] == need) {
					FOR(k,0,M) {
						auto it = colRem[k].find(otherRow);
						if (it != colRem[k].end()) colRem[k].erase(it);
					}
				}
			}
		}

	}

	cout << sz(ans) << endl;
	for(auto [a,b,c] : ans) cout << a + 1 << ' ' << b + 1 << ' ' << c + 1 << endl;


}

int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}
