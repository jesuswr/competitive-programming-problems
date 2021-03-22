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

// GJNM
int N, K;
int A[MAXN];

int B[MAXN];
int PRE1[MAXN], PRE2[MAXN];
bool valid(int x) {
    FOR(i, 0, N) B[i] = (A[i] >= x ? 1 : -1);
    FOR(i, 0, N) PRE1[i] = B[i] + (i > 0 ? PRE1[i - 1] : 0);
    FOR(i, 0, N) PRE2[i] = (i > 0 ? min(PRE2[i - 1], PRE1[i]) : PRE1[i]);
    FOR(i, K - 1, N) if (PRE1[i] > 0) return true;
    FOR(i, K, N) if (PRE1[i] - PRE2[i - K] > 0) return true;
    return false;
}

int main() {
    rii(N, K);
    FOR(i, 0, N) ri(A[i]);
    int lo = 1, hi = MAXN;
    while (lo < hi) {
        int mi = lo + (hi - lo + 1) / 2;
        if (valid(mi)) lo = mi;
        else hi = mi - 1;
    }
    printf("%d\n", lo);
    return 0;
}