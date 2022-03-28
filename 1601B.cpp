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
const int MAXN = 3e5 + 69; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
int A[MAXN], B[MAXN];
int CST[MAXN];
vi G[MAXN];
int F[MAXN];
int J[MAXN];

int main() {
    FOR(i, 0, MAXN) CST[i] = INF;
    ri(N);
    FOR(i, 0, N) ri(A[i + 1]);
    FOR(i, 0, N) ri(B[i + 1]);

    queue<int> nxts;
    for (int i = N - 1; i >= 0; --i) nxts.push(i);
    queue<int> q;
    q.push(N);
    CST[N] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        while (!nxts.empty() && nxts.front() >= u - A[u]) {
            int v = nxts.front();
            v = v + B[v];
            if (CST[u] + 1 < CST[v]) {
                J[v] = nxts.front();
                F[v] = u;
                CST[v] = CST[u] + 1;
                q.push(v);
            }
            nxts.pop();
        }
    }

    if (CST[0] == INF)
        printf("-1\n");
    else {
        vi ans;
        int u = 0;
        while (u != N) {
            ans.pb(J[u]);
            u = F[u];
        }
        reverse(ALL(ans));
        printf("%d\n", CST[0]);
        for (int j : ans) printf("%d ", j);
        printf("\n");
    }

    return 0;
}