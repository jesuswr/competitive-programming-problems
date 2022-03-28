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
const int MAXN = 600; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, K;

bool VIS[MAXN];
bool ANS[MAXN];
int G[MAXN][MAXN];

int main() {
    rii(N, K);
    FOR(i, 0, N) FOR(j, 0, N) if (i != j) G[i][j] = INF;

    FOR(i, 0, N) {
        int k; ri(k);
        FOR(_, 0, k) {
            int j; ri(j); --j;
            if (i == j) continue;
            G[i][j] = 1;
        }
    }
    FOR(k, 0, N) FOR(i, 0, N) FOR(j, 0, N) G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
    FOR(i, 0, N) {
        int cnt = 0;
        FOR(j, 0, N) cnt += G[j][i] < INF;
        ANS[i] = cnt > K;
    }
    FOR(i, 0, N) printf("%d\n", ANS[i]);
    return 0;
}