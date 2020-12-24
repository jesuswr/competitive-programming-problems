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
#include <list>

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
const int MAXN = 2e5 + 1; // CAMBIAR ESTE

// GJNM
int N;
int A[MAXN];
int DP[MAXN];
vi G[MAXN];

int main() {
    ri(N);
    FOR(i, 0, N) ri(A[i]);
    FOR(i, 0, N) DP[i] = INF;
    FOR(i, 0, N) {
        if (i - A[i] >= 0) G[i - A[i]].pb(i);
        if (i + A[i] < N) G[i + A[i]].pb(i);
    }
    list<int> on;
    FOR(i, 0, N) {
        if (i - A[i] >= 0 && ((A[i] ^ A[i - A[i]]) & 1)) DP[i] = 1;
        if (i + A[i] < N && ((A[i] ^ A[i + A[i]]) & 1)) DP[i] = 1;
        if (DP[i] == 1) on.push_back(i);
    }


    while (SZ(on)) {
        list<int> new_on;
        for (auto i : on) {
            for (auto j : G[i]) {
                int old = DP[j];
                if ((A[i] & 1) == (A[j] & 1)) DP[j] = min(DP[j], DP[i] + 1);
                if (old > DP[j]) new_on.push_back(j);
            }
        }
        swap(on, new_on);
    }

    FOR(i, 0, N) {
        if (DP[i] >= INF) printf("-1 ");
        else printf("%d ", DP[i]);
    }
    putchar('\n');

    return 0;
}