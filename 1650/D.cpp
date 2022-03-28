#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int qwert;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) qwert = scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) qwert = scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void shift(vi &a, int s, int l) {
    vi aux(l);
    FOR(i, 0, l) aux[(i - s + l) % l] = a[i];
    FOR(i, 0, l) a[i] = aux[i];
}

void solve() {
    int n; ri(n);
    vi a(n);
    FOR(i, 0, n) ri(a[i]);
    FOR(i, 0, n) a[i]--;
    vi ans;
    for (int i = n - 1; i >= 0; --i) {
        int ind = 0;
        while (a[ind] != i) ind++;
        int dff = (ind + 1) % (i + 1);
        shift(a, dff, i + 1);
        ans.pb(dff);
    }
    reverse(all(ans));
    for (auto x : ans) printf("%d ", x);
    printf("\n");
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}
