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
const int MAXN = 1e6 + 10; // CAMBIAR ESTE
const ll MOD = 1e9 + 7;

// GJNM
int N, M;
string S, P;
vi X;
bool need_match[MAXN];

bool good() {
    int n = SZ(S), m = SZ(P);
    vi pi(m + 1);
    P += '$';
    FOR(i, 1, m) {
        int j = pi[i - 1];
        while (j > 0 && P[i] != P[j]) j = pi[j - 1];
        if (P[i] == P[j]) pi[i] = j + 1;
    }
    int lst = 0;
    FOR(i, 0, n) {
        int j = lst;
        while (j > 0 && S[i] != P[j]) j = pi[j - 1];
        if (S[i] == P[j]) lst = j + 1;
        else lst = 0;
        if (need_match[i] && lst != m) return false;
    }
    return true;
}

int main() {
    rii(N, M);
    cin >> P;
    X.pb(-1);
    FOR(i, 0, M) {
        int aux; ri(aux);
        X.pb(aux - 1);
        need_match[aux - 1 + SZ(P) - 1] = true;
    }
    FOR(i, 0, N) {
        S.pb('?');
        auto it = ub(X.begin(), X.end(), i);
        --it;
        int x = *it;
        if (x == -1) continue;
        if (i - x >= SZ(P)) continue;
        S[i] = P[i - x];
    }

    if (!good()) printf("0\n");
    else {
        ll ans = 1;
        FOR(i, 0, N) if (S[i] == '?') ans = (ans * 26) % MOD;
        printf("%lld\n", ans);
    }

    return 0;
}