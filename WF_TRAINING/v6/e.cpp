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
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

string S;
string curr;
vector<string> ans;

void gen(int p) {
	if (p == sz(S)) {
		ans.pb(curr);
	}
	else {

		curr.pb(S[p] + abs('A' - 'a'));
		gen(p+1);
		curr.pop_back();

		if (p + 1 < sz(S) && S[p] == 'S' && S[p+1] == 'S') {
			curr.pb('B');
			gen(p+2);
			curr.pop_back();
		} 
	}
}

int main(){
	cin >> S;
	gen(0);
	for (string &s : ans) cout << s << endl;
	return 0;
}
