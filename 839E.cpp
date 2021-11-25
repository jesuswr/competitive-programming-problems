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
const int MAXN = 41; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, K;
int L, R;
int MAT[MAXN][MAXN];

int DP[1 << 20];
void f() {
    FOR(msk, 1, 1 << L) {
        int cnt = 0;
        bool good = true;
        FOR(b, 0, L) if ((msk >> b) & 1) {
            DP[msk] = max(DP[msk ^ (1 << b)], DP[msk]);
            ++cnt;
            FOR(b2, 0, b) if ((msk >> b2) & 1)
                good &= MAT[b][b2];
        }
        if (good)
            DP[msk] = cnt;
    }
}

int f2() {
    int ans = 0;
    FOR(msk, 0, 1 << R) {
        int cnt = 0;
        bool good = true;
        FOR(b, 0, R) if ((msk >> b) & 1) {
            ++cnt;
            FOR(b2, 0, b) if ((msk >> b2) & 1)
                good &= MAT[L + b][L + b2];
        }
        if (good) {
            int msk2 = (1 << L) - 1;
            FOR(b, 0, R) if ((msk >> b) & 1) {
                int aux_msk = 0;
                FOR(b2, 0, L) {
                    if (MAT[L + b][b2])
                        aux_msk |= (1 << b2);
                }
                msk2 &= aux_msk;
            }
            ans = max(ans, cnt + DP[msk2]);
        }
    }
    return ans;
}


int main() {
    rii(N, K);
    FOR(i, 0, N) FOR(j, 0, N) ri(MAT[i][j]);
    L = N / 2;
    R = (N + 1) / 2;
    f();
    int sz = f2();
    long double ans = ((1.0) * K / sz) * ((1.0) * K / sz) * ((sz * sz - sz) >> 1);
    printf("%.10Lf\n", ans);
    return 0;
}