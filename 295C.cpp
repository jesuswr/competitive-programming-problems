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
const int MAXN = 1e5; // CAMBIAR ESTE
const ll MOD = 1e9 + 7;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, K;
int CNT[2];

int P[100][100];
int pick(int a, int b) {
    if (P[a][b] != -1)
        return P[a][b];
    if (b == 0 || b == a)
        return P[a][b] = 1;
    return P[a][b] = (pick(a - 1, b) + pick(a - 1, b - 1)) % MOD;
}
ll pick2(int a, int b, int c, int d) {
    return (1ll * pick(a, b) * pick(c, d)) % MOD;
}

int DP[2][51][51];
ll DP2[2][51][51];
pair<int, ll> f(int _a, int _b) {
    memset(DP, INF, sizeof(DP));
    queue< array<int, 3> > q;
    q.push({0, _a, _b});
    DP[0][_a][_b] = 0;
    DP2[0][_a][_b] = 1;

    while (!q.empty()) {
        int P = q.front()[0];
        int A = q.front()[1];
        int B = q.front()[2];
        q.pop();
        if (P == 1 && A == _a && B == _b)
            return {DP[P][A][B], DP2[P][A][B]};
        for (int a = 0; a <= A; ++a) {
            for (int b = 0; b <= B; ++b) {
                if (a + b == 0) continue;
                if (50 * a + 100 * b > K) break;
                int nxtp = 1 ^ P;
                int nxta = (_a - A) + a;
                int nxtb = (_b - B) + b;
                if (DP[nxtp][nxta][nxtb] == INF) {
                    DP[nxtp][nxta][nxtb] = DP[P][A][B] + 1;
                    q.push({nxtp, nxta, nxtb});
                }
                if (DP[nxtp][nxta][nxtb] == DP[P][A][B] + 1) {
                    DP2[nxtp][nxta][nxtb] += pick2(A, a, B, b) * DP2[P][A][B];
                    DP2[nxtp][nxta][nxtb] %= MOD;
                }
            }
        }
    }
    return { -1, 0};
}



int main() {
    memset(P, -1, sizeof(P));
    rii(N, K);
    FOR(i, 0, N) {
        int a; ri(a);
        CNT[a == 100]++;
    }
    auto ans = f(CNT[0], CNT[1]);
    printf("%d\n%lld\n", ans.F, ans.S);
    return 0;
}