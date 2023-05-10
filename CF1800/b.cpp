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


void solve() {
    int n, k; rii(n,k);
    map<char, int> cnt;
    string s;
    cin >> s;
    for(auto c : s) cnt[c] += 1;
    int ans = 0;
    for(char c = 'a'; c <= 'z'; ++c) {
        char C = toupper(c);
        int mn = min(cnt[c], cnt[C]);
        cnt[c] -= mn;
        cnt[C] -= mn;
        int mx = max(cnt[c], cnt[C]);
        int x = min(k, mx / 2);
        k -= x;
        ans += mn + x;
    }

    cout << ans << endl;
}


int main(){
	int t; ri(t);
	while(t--) {
        solve();
	}
	return 0;
}
