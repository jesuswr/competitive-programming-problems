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
const int MAXN = 110; // CAMBIAR ESTE

// GJNM
int N, M;
int P[MAXN][MAXN];
priority_queue<int> PQs[MAXN];
priority_queue<piii> PQ;
bool R[MAXN][MAXN];

void solve() {
    rii(N, M);
    FOR(i, 0, N) FOR(j, 0, M) ri(P[i][j]);
    FOR(i, 0, N) FOR(j, 0, M) {
        R[i][j] = false;
        PQs[i].push(P[i][j]);
        if (SZ(PQ) < M) PQ.push({P[i][j], {i, j}});
        else if (PQ.top().F > P[i][j]) {
            PQ.pop();
            PQ.push({P[i][j], {i, j}});
        }
    }
    FOR(j, 0, M) {
        auto x = PQ.top();
        PQ.pop();
        P[x.S.F][j] = x.F;
        R[x.S.F][j] = true;
    }
    FOR(i, 0, N) {
        FOR(j, 0, M) {
            if (R[i][j]) continue;
            P[i][j] = PQs[i].top();
            PQs[i].pop();
        }
    }

    FOR(i, 0, N) {
        FOR(j, 0, M) printf("%d ", P[i][j]);
        printf("\n");
    }

    FOR(i, 0, N) while (!PQs[i].empty()) PQs[i].pop();
}



int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}