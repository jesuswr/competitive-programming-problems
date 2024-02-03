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


// SRPP
// RRSP
// SPRP
// RRRP
// RSPP
// PPSR
// RSPP
// RRSR
// PSRP
// SSRS

int N,M;
vi preff(string &s){
    int n = s.length();
    vi P(n);
    FOR(i,1,n){
        int j = P[i-1];
        while(j>0 && s[i]!=s[j]) j = P[j-1];
        j += s[i] == s[j];
        P[i] = j;
    }
	vi ret;
	int x = P[n-1];
	while(1) {
		if (2*n - x <= N) ret.pb(x);
		else break;
		if (x == 0) break;
		x = P[x-1];
	}
	return ret;
}

string A[123];

int main(){
	cin >> N >> M;
	vector< pair< vi, int> > ans;
	FOR(_,0,M) {
		string s; cin >> s;
		A[_] = s;
		auto res = preff(s);
		ans.pb({res,_});
	}
	sort(all(ans));
	for(auto [_, ind] : ans) {
		cout << A[ind] << endl;
		// for(int x : _) cout << x << " ";
		// cout << endl;
	}
	return 0;
}
