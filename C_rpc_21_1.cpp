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
const int MAXN = 2e6 + 10; // CAMBIAR ESTE

// GJNM
int N, M;
int A[MAXN];

void solve() {
    FOR(i, 0, N) ri(A[i]);
    FOR(i, 0, M) ri(A[N + i]);
    sort(A, A + N + M);
    int inters = 0;
    FOR(i, 1, M + N) inters += A[i] == A[i - 1];
    printf("%d %d %d %d\n", N - inters, inters, M - inters, N + M - inters);
}

int main() {
    while (true) {
        rii(N, M);
        if (N == 0 && M == 0) break;
        solve();
    }

    return 0;
}