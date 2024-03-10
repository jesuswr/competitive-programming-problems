#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef ll T;
typedef complex<T> pt;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define ri(a) scanf("%d", &a)
#define rii(a, b) ri(a), ri(b)
#define lri(a) scanf("%lld", &a)
#define lrii(a, b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first
#define x real()
#define y imag()
#define mkt make_tuple

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 2e5+5;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

T cross (pt v, pt w) {return (conj(v)*w).y;}
T orient(pt a, pt b, pt c) { return cross(b-a, c-a);}
bool cmp (pt a, pt b) {
    return mkt(a.x, a.y) < mkt(b.x, b.y);
}
bool inTriangle(pt a, pt b, pt c, pt p) {
    return // orient(a, b, p) <= 0 && 
           orient(b, c, p) <= 0 && orient(c, a, p) <= 0;
}

vector<pt> convexHull (vector<pt> &P) {
    sort(all(P), cmp);
    vector<pt> UH;
    vector<pt> LH;
    for (auto p : P) {
        while (sz(UH) >= 2 && orient(UH[sz(UH)-2], UH.back(), p) >= 0) UH.pop_back();
        UH.pb(p);
    }

    reverse(all(P));

    for (auto p : P ) {
        while (sz(LH) >= 2 && orient(LH[sz(LH)-2], LH.back(), p) >= 0) LH.pop_back();
        LH.pb(p);
    }

    for (auto p : LH) if (p != UH.back() and p != UH[0]) UH.pb(p);
    return UH;
}

int n;
vector <pt> S;

int main() {
    ri (n);
    FOR(i,0,n) {
        ll xx, yy; lrii(xx, yy);
        S.pb({xx, yy});
    }

    vector<pt> CH = convexHull (S);
    vector<pt> R;

    for (auto p : S) {
        bool inside = true;
        for (auto c : CH) if(p == c) { inside = false; break; }
        if (inside) R.pb(p);
    }


    int ans = 1;
    FOR(i,0,sz(CH)) {
        pt a = CH[i], b = CH[(i+1) % sz(CH)];
        for (auto c : R) {
            bool pos = true;
            for (auto d : R) if (c != d && inTriangle(a, b, c, d)) {
                pos = false; 
                break;
            } 

            ans += pos;
        }
    }

    printf("%d\n", ans);

    return 0;
}