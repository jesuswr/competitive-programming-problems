#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
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
const int MOD = 1e9+7;
const int MAXN = 2e5+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}


int main(){
	int t; cin >> t;
	while(t--) {
		int n,m,k; cin >> n >> m >> k;
		if (k == 1) cout << 1 << endl;
		else if (k == 2) 
			cout << min(n,m) + max(0, m / n - 1) << endl;
		else if (k == 3) {
			if (n >= m) cout << 0 << endl;
			else cout << m - (n-1) - m/n << endl;
		}
		else cout << 0 << endl;
	}
	return 0;
}
