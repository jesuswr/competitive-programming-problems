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
const int MAXN = 5010; // CAMBIAR ESTE

// GJNM
struct Hash {
    int P = 1777771, MOD[2], PI[2];
    vector<int> h[2], pi[2];
    Hash() {}
    Hash(string& s) {
        MOD[0] = 999727999; MOD[1] = 1070777777;
        PI[0] = 325255434; PI[1] = 10018302; // inversa de P en MOD0 y MOD1
        FOR(k, 0, 2)h[k].resize(s.size() + 1), pi[k].resize(s.size() + 1);
        FOR(k, 0, 2) {
            h[k][0] = 0; pi[k][0] = 1;
            ll p = 1;
            FOR(i, 1, SZ(s) + 1) {
                h[k][i] = (h[k][i - 1] + p * s[i - 1]) % MOD[k];
                pi[k][i] = (1LL * pi[k][i - 1] * PI[k]) % MOD[k];
                p = (p * P) % MOD[k];
            }
        }
    }
    ll get(int s, int e) { // [s,e)
        ll h0 = (h[0][e] - h[0][s] + MOD[0]) % MOD[0];
        h0 = (1LL * h0 * pi[0][s]) % MOD[0];
        ll h1 = (h[1][e] - h[1][s] + MOD[1]) % MOD[1];
        h1 = (1LL * h1 * pi[1][s]) % MOD[1];
        return (h0 << 32) | h1;
    }
};

int n, q;
string s[MAXN];
Hash h[MAXN];
vector<ll> hs[MAXN];
vector<ll> hs2[MAXN];
int pre[MAXN][MAXN];

int main() {
    rii(n, q);
    vector< pair<ll, int> > hashes;
    FOR(i, 0, n) {
        cin >> s[i];
        h[i] = Hash(s[i]);
        FOR(j, 0, SZ(s[i])) {
            FOR(k, j, SZ(s[i])) {
                hs2[i].pb(h[i].get(j, k + 1));
            }
        }
        sort(ALL(hs2[i]));
        for (auto x : hs2[i]) {
            if (hs[i].empty() || hs[i].back() != x)
                hs[i].pb(x);
        }
        for (auto x : hs[i])
            hashes.pb({x, i});
        hs2[i].clear();
        s[i].clear();
    }
    sort(ALL(hashes));
    FOR(i, 0, n) {
        if (i > 0)
            FOR(j, 0, n) pre[i][j] = pre[i - 1][j];

        for (auto x : hs[i]) {
            pair<ll, int> tmp = {x, i};
            auto it = lower_bound(hashes.begin(), hashes.end(), tmp) - hashes.begin();
            if (it > 0) {
                it--;
                if (hashes[it].F == x)
                    pre[i][hashes[it].S]--;
            }
            pre[i][i]++;
        }
    }
    FOR(i, 0, n) {
        FOR(j, 1, n) {
            pre[i][j] += pre[i][j - 1];
        }
    }
    int last = 0;
    while (q--) {
        int a, b; rii(a, b);
        int l = (last + a - 1) % n + 1;
        int r = (last + b - 1) % n + 1;
        if (l > r)
            swap(l, r);
        l--, r--;
        last = pre[r][r] - (l > 0 ? pre[r][l - 1] : 0);
        printf("%d\n", last);
    }

    return 0;
}