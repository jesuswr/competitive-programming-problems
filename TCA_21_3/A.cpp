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
const int MAXN = 50000; // CAMBIAR ESTE

// GJNM
int N, Q;
int A[1001];
int B[1001];
bool USED[MAXN];
vii G[MAXN];
int D[MAXN];

void dijkstra() {
    FOR(i, 0, A[0]) D[i] = 1e9 + 1;
    priority_queue<pii> pq;
    D[0] = 0;
    pq.push({D[0], 0});

    while (!pq.empty()) {
        auto [cst, u] = pq.top(); pq.pop();
        cst *= -1;
        if (cst > D[u])
            continue;

        FOR(i, 1, N) {
            int v = A[i] + u;
            if (v >= A[0])
                v -= A[0];
            if (D[v] > D[u] + B[i]) {
                D[v] = D[u] + B[i];
                pq.push({ -D[v], v});
            }
        }
    }
}

int main() {
    ri(N);
    FOR(i, 0, N) ri(A[i]);
    FOR(i, 0, N) B[i] = A[i];

    int j = 1;
    USED[0] = 1;
    FOR(i, 1, N) {
        A[i] %= A[0];
        if (USED[A[i]])
            continue;
        USED[A[i]] = 1;
        B[j] = B[i];
        A[j++] = A[i];
    }
    N = j;
    dijkstra();

    ri(Q);
    while (Q--) {
        int x; ri(x);
        if (D[x % A[0]] <= x)
            printf("TAK\n");
        else
            printf("NIE\n");
    }


    return 0;
}