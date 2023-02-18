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



int main(){
	int n,k; rii(n,k);
	vector<vi> where(k, vi(n));
	vector<vi> a(k, vi(n));
	FOR(i,0,k) FOR(j,0,n) {
		ri(a[i][j]);
		a[i][j]--;
		where[i][a[i][j]] = j;
	}

	vi bst(n, 1);
	int mx = 1;
	for(int i = n-1; i>=0; --i) {
		int curr = a[0][i];
		// cout << curr+1 << endl;
		FOR(j,i+1,n) {
			int nxt = a[0][j];
			bool g = 1;
			FOR(l,0,k) {
				g &= where[l][curr] < where[l][nxt];
			}
			// if (g) cout << "\t" << nxt+1 << endl;
			if (g) bst[curr] = max(bst[curr], bst[nxt] + 1);
		}
		mx = max(mx, bst[curr]);
	}
	cout << mx << endl;
	return 0;
}
