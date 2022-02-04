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
const int MAXN = 50020; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, X;
int A[MAXN];
int DP[MAXN][2][2][2];

bool check(const vi &v, int p) {
    FOR(l, 0, 4) {
        if (v[l] == 1 && A[p - l] == -INF)
            return false;
        if (v[l] == 0)
            continue;

        int sm = A[p - l];
        FOR(r, l + 1, 4) {
            if (v[r] == 0)
                break;
            sm += A[p - r];
            if (sm < X * (r - l + 1)) {
                return false;
            }
        }
    }
    return true;
}

int f(int p, int p1, int p2, int p3) {
    int &ret = DP[p][p1][p2][p3];
    if (ret != -1)
        return ret;
    if (p == N)
        return ret = 0;
    ret = -INF;
    FOR(t, 0, 2) FOR(t1, p1, 2) FOR(t2, p2, p2 + 1) FOR(t3, p3, p3 + 1) {
        vi vec = {t, t1, t2, t3};
        if (check(vec, p))
            ret = max(ret, t + (t1 - p1) + (t2 - p2) + (t3 - p3) + f(p + 1, t, t1, t2));
    }
    return ret;
}

void solve() {
    ri(N);
    FOR(i, 0, N) ri(A[i + 4]);
    ri(X);
    N += 4;
    A[0] = A[1] = A[2] = A[3] = -INF;
    memset(DP, -1, sizeof(DP));
    printf("%d\n", f(4, 0, 0, 0));
}

int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}