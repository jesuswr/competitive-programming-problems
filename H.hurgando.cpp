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
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM

struct Hash {
    int P = 1777771, MOD[3], PI[3];
    vector<int> h[3], pi[3];
    Hash(string& s) {
        MOD[0] = 999727999; MOD[1] = 1070777777; MOD[2] = 1000002149;
        PI[0] = 325255434; PI[1] = 10018302; PI[2] = 123794613; // inversa de P en MOD0 y MOD1
        FOR(k, 0, 3)h[k].resize(s.size() + 1), pi[k].resize(s.size() + 1);
        FOR(k, 0, 3) {
            h[k][0] = 0; pi[k][0] = 1;
            ll p = 1;
            FOR(i, 1, SZ(s) + 1) {
                h[k][i] = (h[k][i - 1] + p * s[i - 1]) % MOD[k];
                pi[k][i] = (1LL * pi[k][i - 1] * PI[k]) % MOD[k];
                p = (p * P) % MOD[k];
            }
        }
    }
    piii get(int s, int e) { // [s,e)
        ll h0 = (h[0][e] - h[0][s] + MOD[0]) % MOD[0];
        h0 = (1LL * h0 * pi[0][s]) % MOD[0];
        ll h1 = (h[1][e] - h[1][s] + MOD[1]) % MOD[1];
        h1 = (1LL * h1 * pi[1][s]) % MOD[1];
        ll h2 = (h[2][e] - h[2][s] + MOD[2]) % MOD[2];
        h2 = (1LL * h2 * pi[2][s]) % MOD[2];
        return {h0, {h1, h2}};
    }
};

int n;
string s;
int r, m;
map<piii, int> hash_cnt;

ll MOD[3] = {999727999, 1070777777, 1000002149};
int P = 1777771;

ll hi[3][2010];
ll thi[3];

int main() {
    ri(n);
    cin >> s;
    rii(r, m);
    Hash h(s);
    FOR(i, 0, n - m + 1) {
        hash_cnt[h.get(i, i + m)]++;
    }

    string abcd;
    for (auto c = 'a'; c <= 'z'; c++)
        abcd.pb(c);
    abcd += ",._";

    ll ans = 0;
    FOR(_, 0, r) {
        cin >> s;
        FOR(k, 0, 3) {
            ll p = 1;
            thi[k] = 0;
            FOR(i, 0, m) {
                hi[k][i] = (s[i] * p ) % MOD[k];
                p = (p * P) % MOD[k];
                thi[k] = (thi[k] + hi[k][i]) % MOD[k];
            }
        }
        ans += hash_cnt[ {thi[0], {thi[1], thi[2]}}];

        ll p[3] = {1, 1, 1};
        FOR(i, 0, m) {
            for (auto c : abcd) {
                if (s[i] == c) continue;

                FOR(k, 0, 3) {
                    thi[k] = (thi[k] - hi[k][i] + c * p[k] + MOD[k]) % MOD[k];
                }
                ans += hash_cnt[ {thi[0], {thi[1], thi[2]}}];
                FOR(k, 0, 3) {
                    thi[k] = (thi[k] + hi[k][i] - c * p[k] + MOD[k]) % MOD[k];
                }
            }
            FOR(k, 0, 3) {
                p[k] = (p[k] * P) % MOD[k];
            }
        }
    }

    printf("%lld\n", ans);
    return 0;
}