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
int N;
int A[MAXN];
int B[MAXN];

int main() {
    ri(N);
    FOR(i, 0, N) ri(A[i]);
    FOR(i, 0, N) FOR(j, 0, 31) if (A[i] & (1 << j)) B[i] = j;
    FOR(i, 0, N - 2) if (B[i] == B[i + 1] && B[i + 1] == B[i + 2]) {printf("1\n"); return 0;}

    int ans = INF;
    FOR(l, 0, N) FOR(m, l + 1, N) FOR(r, m + 1, N + 1) {
        int xor1 = 0;
        FOR(i, l, m) xor1 ^= A[i];
        int xor2 = 0;
        FOR(i, m, r) xor2 ^= A[i];
        if (xor1 > xor2) ans = min(ans, (m - l - 1) + (r - m - 1));
    }

    if (ans == INF) printf("-1\n");
    else printf("%d\n", ans);

    return 0;
}