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
const int MAXN = 1010; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
int M[MAXN][MAXN];
bool V[MAXN][MAXN];

bool valid(int x, int y) {
    return max(x, y) < N && min(x, y) >= 0;
}

void solve() {
    ri(N);
    FOR(i, 0, N) FOR(j, 0, N) ri(M[i][j]);
    FOR(i, 0, N) FOR(j, 0, N) V[i][j] = 0;
    int xr = 0;
    FOR(i, 1, N) FOR(j, 0, N) {
        int cnt = 0;
        for (auto [di, dj] : { make_pair(1, 0), make_pair( -1, 0), make_pair(0, 1), make_pair(0, -1) }) {
            if (valid(i + di - 1, j + dj) && V[i + di - 1][j + dj])
                cnt++;
        }
        if (cnt % 2 == 0) {
            xr ^= M[i][j];
            V[i][j] = 1;
        }
    }
    printf("%d\n", xr);
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}