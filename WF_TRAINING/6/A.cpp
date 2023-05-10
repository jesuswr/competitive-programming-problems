#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ri(a) scanf("%d", &a);
#define rii(a, b) ri(a), ri(b)
#define lri(a) scanf("%lld", &a);
#define lrii(a, b) lri(a), lri(b)
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define all(x) x.begin(), x.end()
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
set <int> M[30];

int main() {
	string s, t;
	cin >> s >> t;


	int n = sz(s), m = sz(t);
	FOR(i,0,n) M[s[i]-'a'].insert(i);


	int i = 0;
    int r = 1;

	FOR(j,0,m) {
		int nxt = t[j] - 'a';
        auto it = M[nxt].lower_bound(i);
        if (it == M[nxt].end()) {
            i = 0;
            --j;
            ++r;
        } else {
            i = *it + 1;
        }
	}

    cout << r << endl;

	return 0;
}

