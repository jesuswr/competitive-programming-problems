#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <unordered_map>
#include <assert.h>
#include <array>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

int dadsadasda;

#define ri(a) dadsadasda=scanf("%d", &a)
#define rii(a,b) dadsadasda=scanf("%d %d", &a, &b)
#define riii(a,b,c) dadsadasda=scanf("%d %d %d", &a, &b, &c)
#define rl(a) dadsadasda=scanf("%lld", &a)
#define rll(a,b) dadsadasda=scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define ALL(s) s.begin(),s.end()
#define SZ(s) (int)s.size()

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1 << 21; // CAMBIAR ESTE

// GJNM
// MAXN must be power of 2 !!
// MOD-1 needs to be a multiple of MAXN !!
// big mod and primitive root for NTT:
typedef int tf;
typedef vector<tf> poly;
const tf MOD = 998244353 , RT = 3;
// NTT
int mulmod(ll a, ll b) {return a * b % MOD;}
int addmod(int a, int b) {int r = a + b; if (r >= MOD)r -= MOD; return r;}
int submod(int a, int b) {int r = a - b; if (r < 0)r += MOD; return r;}
int pm(int a, ll e) {
    int r = 1;
    while (e) {
        if (e & 1)r = mulmod(r, a);
        e >>= 1; a = mulmod(a, a);
    }
    return r;
}
int inv(int a) {return pm(a, MOD - 2);}
struct CD {
    tf x;
    CD(tf x): x(x) {}
    CD() {}
};
CD operator*(const CD& a, const CD& b) {return CD(mulmod(a.x, b.x));}
CD operator+(const CD& a, const CD& b) {return CD(addmod(a.x, b.x));}
CD operator-(const CD& a, const CD& b) {return CD(submod(a.x, b.x));}
vector<tf> rts(MAXN + 9, -1);
CD root(int n, bool inv) {
    tf r = rts[n] < 0 ? rts[n] = pm(RT, (MOD - 1) / n) : rts[n];
    return CD(inv ? pm(r, MOD - 2) : r);
}
CD cp1[MAXN + 9], cp2[MAXN + 9];
int R[MAXN + 9];
void dft(CD* a, int n, bool inv) {
    FOR(i, 0, n)if (R[i] < i)swap(a[R[i]], a[i]);
    for (int m = 2; m <= n; m *= 2) {
        CD wi = root(m, inv); // NTT
        for (int j = 0; j < n; j += m) {
            CD w(1);
            for (int k = j, k2 = j + m / 2; k2 < j + m; k++, k2++) {
                CD u = a[k]; CD v = a[k2] * w; a[k] = u + v; a[k2] = u - v; w = w * wi;
            }
        }
    }
    if (inv) { // NTT
        CD z(pm(n, MOD - 2)); // pm: modular exponentiation
        FOR(i, 0, n)a[i] = a[i] * z;
    }
}
poly multiply(poly& p1, poly& p2) {
    int n = p1.size() + p2.size() + 1;
    int m = 1, cnt = 0;
    while (m <= n)m += m, cnt++;
    FOR(i, 0, m) {R[i] = 0; FOR(j, 0, cnt)R[i] = (R[i] << 1) | ((i >> j) & 1);}
    FOR(i, 0, m)cp1[i] = 0, cp2[i] = 0;
    FOR(i, 0, p1.size())cp1[i] = p1[i];
    FOR(i, 0, p2.size())cp2[i] = p2[i];
    dft(cp1, m, false); dft(cp2, m, false);
    FOR(i, 0, m)cp1[i] = cp1[i] * cp2[i];
    dft(cp1, m, true);
    poly res;
    n -= 2;
    FOR(i, 0, n)res.pb(cp1[i].x); // NTT
    return res;
}
poly P[2010];

poly go(int l, int r) {
    if (l + 1 == r) return P[l];
    int m = (l + r) / 2;
    poly a = go(l, m), b = go(m, r);
    return multiply(a, b);
}

int main() {
    int n; ri(n);
    FOR(i, 0, n) {
        int a; ri(a);
        poly pa(a + 1, 1);
        P[i] = pa;
    }

    auto p = go(0, n);
    int q; ri(q);
    while (q--) {
        int a; ri(a);
        cout << (a < SZ(p) ? p[a] : 0) << '\n';
    }



    return 0;
}