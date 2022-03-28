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
typedef long long T;
typedef complex<T> pt;
#define x real() // DO noT USE x & y AS VARIABLE NAMES!!!
#define y imag()
#define mkt make_tuple
const double PI = 2 * acos(0.0);
const double EPS = 1e-6;


void polarSort(vector<pt> &V) {
    sort(all(V), [](pt v, pt w) {
        return make_tuple(v.x, v.y) <
               make_tuple(w.x, w.y);
    });
}

int main() {
    int t; ri(t);
    while (t--) {
        int n; ri(n);
        vector<pt> v;
        FOR(i, 0, n) {
            int a, b; rii(a, b);
            v.pb({ a,  b});
        }
        polarSort(v);
        pt mid = (v[0] + v[n - 1]);
        bool ans = 1;
        FOR(i, 0, n / 2) {
            pt aux = (v[i] + v[n - 1 - i]);
            if (mid != aux) {
                ans = 0;
            }
        }
        if (ans)printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
