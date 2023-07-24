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
	int n; ri(n);
	vi have(1010);
	vi ans;
	while(n--) {
		int a; ri(a);
		if (a >= 0) have[a]++;
		else {
			if (have[-a] > 0) have[-a]--;
			else if (have[0] > 0) {
				have[0]--;
				ans.pb(-a);
			}
			else {
				cout << "No" << endl;
				return 0;
			}
		}
	}

	FOR(_,0,have[0]) ans.pb(1);

	cout << "Yes" << endl;
	FOR(i,0,sz(ans)) cout << ans[i] << " \n"[i + 1 == sz(ans)];

	return 0;
}
