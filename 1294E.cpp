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
const int MAXN = 2e5 + 10; // CAMBIAR ESTE

// GJNM
int N, M;
vector<vi> MAT;
int DP[MAXN];

int main() {
    rii(N, M);
    MAT = vector<vector<int>>(N, vector<int>(M));
    FOR(i, 0, N) FOR(j, 0, M) ri(MAT[i][j]), MAT[i][j]--;
    ll ans = 0;
    FOR(c, 0, M) {
        FOR(r, 0, N) DP[r] = 0;
        FOR(r, 0, N) {
            int _r = MAT[r][c] / M;
            int _c = MAT[r][c] % M;
            if (_r >= N || _c != c)
                continue;
            DP[(r - _r + N) % N]++;
        }
        int curr = N - DP[0];
        FOR(r, 1, N) curr = min(curr, N - DP[r] + r);
        ans += curr;
    }
    printf("%lld\n", ans);
    return 0;
}