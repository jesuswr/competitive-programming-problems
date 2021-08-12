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
const int MAXN = 1e5 + 10; // CAMBIAR ESTE

// GJNM
int N, Q, T;
string S;
string A[MAXN], B[MAXN];
vi OC[531441];

int f(int l, int r, const string &s) {
    int ret = 0, p = 1;
    for (; l <= r; ++l) {
        ret += p * (s[l] - 'a' + 1);
        p *= 27;
    }
    return ret;
}

string get_string(int h) {
    string ret;
    while (h > 0) {
        int aux = h % 27;
        ret += 'a' + aux - 1;
        h /= 27;
    }
    return ret;
}


vi PRE[531441];
void pre_calc(int h) {
    int len = 0;
    int aux_h = h;
    while (aux_h > 0) {
        len++;
        aux_h /= 27;
    }
    PRE[h].resize(531441, INF);
    OC[h].pb(2 * INF);

    int j = 0;
    FOR(l, 0, N) {
        while (l >= OC[h][j + 1]) ++j;
        FOR(r, l, min(N, l + 4)) {
            int h2 = f(l, r, S);
            PRE[h][h2] = min(PRE[h][h2], max(r + 1, OC[h][j] + len) - min(l, OC[h][j]));
            PRE[h][h2] = min(PRE[h][h2], max(r + 1, OC[h][j + 1] + len) - min(l, OC[h][j + 1]));
        }
    }
}

int go(const string &a, const string & b) {
    int h1 = f(0, SZ(a) - 1, a), h2 = f(0, SZ(b) - 1, b);
    int ret = 2 * INF;
    int i = 0, j = 0;
    while (i < SZ(OC[h1]) && j < SZ(OC[h2])) {
        ret = min(ret, max(OC[h1][i] + SZ(a), OC[h2][j] + SZ(b)) - min(OC[h1][i], OC[h2][j]) );
        if (OC[h1][i] < OC[h2][j])
            i++;
        else
            j++;
    }
    return ret;
}

int main() {
    cin >> S; N = SZ(S);
    ri(Q); T = (10 * N) / sqrt(Q + 1);
    FOR(i, 0, Q) cin >> A[i] >> B[i];

    FOR(l, 0, N) FOR(r, l, min(N, l + 4)) OC[f(l, r, S)].pb(l);

    FOR(i, 0, Q) {
        int h1 = f(0, SZ(A[i]) - 1, A[i]), h2 = f(0, SZ(B[i]) - 1, B[i]);
        int ans = 0;
        if (SZ(OC[h1]) > T) {
            if (SZ(PRE[h1]) == 0)
                pre_calc(h1);
            ans = PRE[h1][h2];
        }
        else if (SZ(OC[h2]) > T) {
            if (SZ(PRE[h2]) == 0)
                pre_calc(h2);
            ans = PRE[h2][h1];
        }
        else
            ans = go(A[i], B[i]);
        printf("%d\n", (ans >= INF ? -1 : ans));
    }
    return 0;
}