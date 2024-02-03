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
const int MAXN = 1e6+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

vi G[2][MAXN];
string s;
int get_tree(int &pos, vi g[]) {
	int val = 0;
	while(1) {
		if (s[pos] == ' ') {
			pos++;
		}
		else if (s[pos] == '(') {
			pos++;
			int j = get_tree(pos, g);
			g[val].pb(j);
		}
		else if (s[pos] == ')') {
			pos++;
			return val;
		}
		else if ('0' <= s[pos] && s[pos] <= '9') {
			val = 10 * val + (s[pos] - '0');
			pos++;
		}
	}
}
ii get_tree() {
	int r1, r2;
	getline(cin, s);
	s = s + ')';
	int pos = 0;
	r1 = get_tree(pos, G[0]);
	getline(cin, s);
	s = s + ')';
	pos = 0;
	r2 = get_tree(pos, G[1]);
	return {r1, r2};
}

map< ll , ll > mp;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
ll f(int gi, int u) {
	ll sum = u;
	for(int v : G[gi][u])
		sum += f(gi, v);
	if (mp.find(sum) != mp.end()) return mp[sum];
	return mp[sum] = rng();	
}


int main(){
	auto [r1, r2] = get_tree();
	
	if (f(0, r1) != f(1, r2)) cout << "No" << endl;
	else cout << "Yes" << endl;


	return 0;
}
