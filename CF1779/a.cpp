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
	int t; ri(t);
	while (t--)
	{
		int n; ri(n);
		string s; cin >> s;
		int mn_r = INF, mx_l = -1;
		for(int i = 0; i < n; ++i) {
			if (s[i] == 'L') mx_l = i;
			else mn_r = min(mn_r, i);
		}
		if (mn_r == INF || mx_l == -1) cout << -1 << endl;
		else if (mn_r > mx_l) cout << mn_r << endl;
		else cout << 0 << endl;
	}
	

	return 0;
}
