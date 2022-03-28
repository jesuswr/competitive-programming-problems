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
const int MAXN = 70000; // CAMBIAR ESTE
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N[3];
int X[3][MAXN];
const int OFFSET = 30005;
bool H[MAXN];

int main() {
    FOR(i, 0, 3) {
        ri(N[i]);
        FOR(j, 0, N[i]) ri(X[i][j]);
    }
    sort(X[0], X[0] + N[0]);
    sort(X[1], X[1] + N[1]);
    sort(X[2], X[2] + N[2]);

    FOR(i, 0, N[2]) H[X[2][i] + OFFSET] = 1;
    
    int ans = 0;
    int i1 = 0;
    FOR(i0, 0, N[0]) {
        // printf("%d \n", i0);
        while (i1 < N[1] && 2 * X[1][i1] - X[0][i0] < X[2][0]) ++i1;
        // printf("\t%d\n", i1);
        FOR(i, i1, N[1]) {
            int nx = 2 * X[1][i] - X[0][i0];
            // printf("\t\t%d\n", nx);
            if (nx > X[2][N[2] - 1])
                break;
            ans += H[OFFSET + nx];
        }
    }
    printf("%d\n", ans);

    return 0;
}