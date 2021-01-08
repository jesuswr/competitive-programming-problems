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
const int MAXN = 3e5; // CAMBIAR ESTE
const ll MOD = 1e9 + 7;

// GJNM
int N;
string S;
ll PREA[MAXN], SUFC[MAXN], PRE[MAXN], SUF[MAXN];


ll binpow(ll b, ll e) {
    ll ret = 1;
    while (e > 0) {
        if (e & 1) ret = (ret * b) % MOD;
        e >>= 1;
        b = (b * b) % MOD;
    }
    return ret;
}

int main() {
    ri(N);
    cin >> S;
    S = "_" + S;
    FOR(i, 1, SZ(S)) {
        PREA[i] = S[i] == 'a';
        SUFC[i] = S[i] == 'c';
        PRE[i] = S[i] == '?';
        SUF[i] = S[i] == '?';
    }
    FOR(i, 1, SZ(S)) {
        PREA[i] += PREA[i - 1];
        PRE[i] += PRE[i - 1];
    }
    ROF(i, SZ(S) - 1, -1) {
        SUF[i] += SUF[i + 1];
        SUFC[i] += SUFC[i + 1];
    }

    ll match[4] = {0, 0, 0, 0};
    FOR(i, 1, SZ(S)) {
        if (S[i] == 'b') {
            match[3] += PREA[i - 1] * SUFC[i + 1];
            match[2] += PREA[i - 1] * SUF[i + 1] + PRE[i - 1] * SUFC[i + 1];
            match[1] += PRE[i - 1] * SUF[i + 1];
        }
        else if (S[i] == '?') {
            match[2] += PREA[i - 1] * SUFC[i + 1];
            match[1] += PREA[i - 1] * SUF[i + 1] + PRE[i - 1] * SUFC[i + 1];
            match[0] += PRE[i - 1] * SUF[i + 1];
        }
    }

    ll ans = 0;
    FOR(i, 0, 4) {
        match[i] %= MOD;
        ans += match[i] * binpow(3, SUF[0] - (3 - i));
        ans %= MOD;
    }
    printf("%lld\n", ans);
    return 0;
}