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
#include <random>
#include <chrono>

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
const int MAXN = 2e6 + 69; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, M;
ll L[MAXN];
vector<ll> Ds[MAXN], Pref[MAXN];

void build(int u) {
    if (u > N) return;
    int l = 2 * u, r = 2 * u + 1;
    int cl = L[l - 1], cr = L[r - 1];
    build(l), build(r);
    Ds[u].pb(0);
    for (int li = 0, ri = 0; li < SZ(Ds[l]) || ri < SZ(Ds[r]);) {
        if (li == SZ(Ds[l]))
            Ds[u].pb(cr + Ds[r][ri++]);
        else if (ri == SZ(Ds[r]))
            Ds[u].pb(cl + Ds[l][li++]);
        else if (cl + Ds[l][li] <= cr + Ds[r][ri])
            Ds[u].pb(cl + Ds[l][li++]);
        else
            Ds[u].pb(cr + Ds[r][ri++]);
    }
    for (auto x : Ds[u]) {
        ll add = (SZ(Pref[u]) > 0 ? Pref[u].back() : 0);
        Pref[u].pb(x + add);
    }
}


int main() {
    rii(N, M);
    FOR(i, 0, N - 1) rl(L[i + 1]);
    build(1);

    while (M--) {
        int a, h; rii(a, h);
        ll ans = 0;
        ll aux;
        aux = ub(ALL(Ds[a]), h) - Ds[a].begin();
        if (aux > 0)
            ans += aux * h - Pref[a][aux - 1];
        ll up = 0;
        while (a != 1) {
            int new_a = a / 2;
            int l = 2 * new_a, r = 2 * new_a + 1;
            int cl = L[l - 1], cr = L[r - 1];
            up += L[a - 1];
            ans += max(h - up, 0ll);
            if (a & 1) {
                aux = ub(ALL(Ds[l]), h - up - cl) - Ds[l].begin();
                if (aux > 0)
                    ans += max(aux * (h - up - cl) - Pref[l][aux - 1], 0ll);
            }
            else {
                aux = ub(ALL(Ds[r]), h - up - cr) - Ds[r].begin();
                if (aux > 0)
                    ans += max(aux * (h - up - cr) - Pref[r][aux - 1], 0ll);
            }
            a = new_a;
        }
        printf("%lld\n", ans);
    }
    return 0;
}