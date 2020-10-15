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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
struct Hash {
    int P = 1777771, MOD[2], PI[2];
    vector<int> h[2], pi[2];
    Hash(string& s) {
        MOD[0] = 999727999; MOD[1] = 1070777777;
        PI[0] = 325255434; PI[1] = 10018302; // inversa de P en MOD0 y MOD1
        FOR(k, 0, 2)h[k].resize(s.size() + 1), pi[k].resize(s.size() + 1);
        FOR(k, 0, 2) {
            h[k][0] = 0; pi[k][0] = 1;
            ll p = 1;
            FOR(i, 1, s.size() + 1) {
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


string a, b;
Hash ha(a), hb(b);
int n;
int cnta[200010][27], cntb[200010][27];

bool f(int la, int ra, int lb, int rb) {
    if (ha.get(la, ra) == hb.get(lb, rb))
        return true;
    if ((ra - la) & 1)
        return false;

    FOR(i, 0, 27) {
        if (cnta[ra][i] - cnta[la][i] != cntb[rb][i] - cntb[lb][i])
            return false;
    }

    int ma = la + (ra - la) / 2;
    int mb = lb + (rb - lb) / 2;

    bool op1 = f(la, ma, lb, mb) && f(ma, ra, mb, rb);
    if (op1)
        return true;
    bool op2 = f(la, ma, mb, rb) && f(ma, ra, lb, mb);
    return op2;
}


int main() {
    cin >> a;
    cin >> b;
    ha = Hash(a);
    hb = Hash(b);
    int n = a.size();

    FOR(i, 0, n) {
        cnta[i + 1][a[i] - 'a']++;
        cntb[i + 1][b[i] - 'a']++;
    }
    FOR(i, 1, n + 1) {
        FOR(j, 0, 27) {
            cnta[i][j] += cnta[i - 1][j];
            cntb[i][j] += cntb[i - 1][j];
        }
    }



    printf("%s\n", (f(0, n, 0, n) ? "YES" : "NO") );
    return 0;
}