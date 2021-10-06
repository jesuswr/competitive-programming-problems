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
const int MAXN = 5e5 + 69; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int BIT[MAXN];
// suma de rangos [0,n-1]
void updBIT(int p, int val) {
    p++;    // esto es porque el bit esta indexado desde 1
    for (; p < MAXN; p += p & -p) // se puede cambiar maxN por n+5 si hace falta mas velocidad
        BIT[p] += val;
}
void updBIT(int l, int r, int val) {
    updBIT(l, val);
    updBIT(r + 1, -val);
}
int sumBIT(int p) {
    p++;
    int ret = 0;
    for (; p; p -= p & -p)
        ret += BIT[p];
    return ret;
}

int A[MAXN];
int PRE[MAXN];
int SZ[MAXN], LST[MAXN];

int main() {
    int N, C; rii(N, C);
    FOR(i, 1, N + 1) {
        ri(A[i]);
        PRE[i] = (A[i] == C);
    }
    for (int i = 1; i <= N; ++i) PRE[i] += PRE[i - 1];
    int ans = PRE[N];
    FOR(i, 1, N + 1) {
        if (A[i] == C) {
            updBIT(1, 5e5 + 1, -1);
        }
        else {
            int val = max(0, sumBIT(A[i]));
            if (val <= 0) {
                SZ[A[i]] = 0;
                LST[A[i]] = i;
            }
            val++;
            SZ[A[i]]++;
            // printf("%d %d %d %d %d\n", i, A[i], LST[A[i]], SZ[A[i]], val);
            updBIT(A[i], A[i], val - sumBIT(A[i]));
            ans = max(ans, SZ[A[i]] + PRE[LST[A[i]] - 1] + (PRE[N] - PRE[i]));
        }
    }
    printf("%d\n", ans);

    return 0;
}