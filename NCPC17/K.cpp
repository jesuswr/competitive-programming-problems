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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

int dadsadasda;

#define ri(a) dadsadasda=scanf("%lld", &a)
#define rii(a,b) dadsadasda=scanf("%d %d", &a, &b)
#define riii(a,b,c) dadsadasda=scanf("%lld %lld %lld", &a, &b, &c)
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
const int MAXN = 3e5; // CAMBIAR ESTE

// GJNM
ll M;
ll N[3], Sn[3], Naux[3];
ll C[MAXN];

bool valid(ll mnn) {
    FOR(i, 0, 3) Naux[i] = N[i];

    FOR(i, 0, M / 2) {
        ll mn = LLINF;
        pair<ll,ll> f;
        FOR(a, 0, 3) FOR(b, 0, 3) {
            Naux[a]--;
            Naux[b]--;
            if (Naux[a] >= 0 && Naux[b] >= 0 && mn > Sn[a] + Sn[b] && C[i] * (Sn[a] + Sn[b]) >= mnn) {
                mn = Sn[a] + Sn[b];
                f = {a, b};
            }
            Naux[a]++;
            Naux[b]++;
        }
        if (mn == LLINF) return false;
        Naux[f.F]--;
        Naux[f.S]--;
    }
    return true;
}

int main() {
    riii(N[0], N[1], N[2]);
    riii(Sn[0], Sn[1], Sn[2]);
    M = N[0] + N[1] + N[2];
    FOR(i, 0, M / 2) ri(C[i]);
    sort(C, C + M / 2);
    reverse(C, C + M / 2);

    ll lo = 0, hi = 1e10 + 10;
    while (lo < hi) {
        ll mi = lo + (hi - lo + 1) / 2;
        if (valid(mi)) lo = mi;
        else hi = mi - 1;
    }
    printf("%lld\n", lo);
    return 0;
}