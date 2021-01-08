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
const int MAXC = 1e6 + 10;

// GJNM
int N, M;
int A[MAXN], B[MAXN], C[MAXN], D[MAXN];
int MAX[MAXC];

int main() {
    rii(N, M);
    FOR(i, 0, N) rii(A[i], B[i]);
    FOR(i, 0, M) rii(C[i], D[i]);
    FOR(i, 0, N) FOR(j, 0, M) {
        if (A[i] <= C[j] && B[i] <= D[j]) {
            int x = C[j] - A[i];
            MAX[x] = max(MAX[x], D[j] - B[i] + 1);
        }
    }
    for (int i = MAXC - 3; i >= 0; i--) MAX[i] = max(MAX[i], MAX[i + 1]);
    int ans = INF;
    FOR(i, 0, MAXC) ans = min(ans, i + MAX[i]);
    printf("%d\n", ans);
    return 0;
}