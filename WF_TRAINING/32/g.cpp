#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj, val) memset(obj, val, sizeof(obj))
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

int p[MAXN];
int d[MAXN];

int main() {
    int n;
    ri(n);
    FOR(i,1,n) { ri(p[i]); p[i]--; d[p[i]]++; }

    int l = 0, lcas = 0;
    FOR(i,0,n) {
        l += (d[i] == 0);
        lcas += (d[i] >= 2);
    }

    assert(lcas <= l);

    vi ans = {1};
    FOR(i,0,lcas) {
        ans.pb(ans.back() + 2);
    }

    FOR(i,lcas,l) {
        ans.pb(ans.back() + 1);
    }

    FOR(i,0,l) printf("%d%c", ans[i], i == l-1 ? '\n' : ' ');


    return 0;
}
