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
const int MAXN = 50+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N, M;
int A[MAXN][MAXN];

void norm() {
	set<int> uniq;
	FOR(i,0,N) FOR(j,0,M) if (A[i][j] != -1) uniq.insert(A[i][j]);
	map<int, int> mp;
	int i = 0;
	for(int x : uniq) mp[x] = i++;
	FOR(i,0,N) FOR(j,0,M) if (A[i][j] != -1) A[i][j] = mp[A[i][j]];
}

int dst(int a, int b, int c, int d) {
	return (abs(a- c) + abs(b - d));
}


int go(int r, int c) {
	map<int, int> diag_cnt;
	map<int, int> val_diag;
	FOR(i,0,N) FOR(j,0,M) if (A[i][j] >= 0) {
		diag_cnt[ dst(r, c, i, j) ] += 1;
		val_diag[A[i][j]] = dst(r, c, i, j);
		// cout << i << " " << j << " : " << dst(r, c, i, j) << endl;
	}
	int curr = 0;
	int ans = 0;
	for(auto [diag, cnt] : diag_cnt) {
		while(cnt > 0) {
			// cout << diag << " " << curr + 1 << " " << val_diag[curr] << endl;
			if (val_diag[curr] != diag) ans++;
			cnt--;
			curr++;
		}
	}
	return ans;
}



int main(){
	rii(N,M);
	FOR(i,0,N) FOR(j,0,M) ri(A[i][j]);
	norm();
	// FOR(i,0,N) {
	// 	FOR(j,0,M) cout << A[i][j];
	// 	cout << endl;
	// }
	int ans = min({
		go(0, 0),
		go(N-1, 0),
		go(0, M-1),
		go(N-1, M-1)
	});
	cout << ans << endl;
	// go(N-1, 0);
	return 0;
}
