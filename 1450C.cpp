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
const int MAXN = 369; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
char M[MAXN][MAXN];

void solve() {
    ri(N);
    FOR(i, 0, N) dadsadasda = scanf("%s", M[i]);
    vector<vector<int>> cnt(3, vi(2));
    FOR(i, 0, N) FOR(j, 0, N) if (M[i][j] != '.')cnt[(i + j) % 3][M[i][j] == 'X']++;
    int mn = INF;
    FOR(a, 0, 3) FOR(b, 0, 3) if (a != b) mn = min(mn, cnt[a][0] + cnt[b][1]);
    FOR(a, 0, 3) FOR(b, 0, 3) if (a != b && mn == cnt[a][0] + cnt[b][1]) {
        FOR(i, 0, N) FOR(j, 0, N) if (M[i][j] != '.') {
            if ((i + j) % 3 == a)
                M[i][j] = 'X';
            else if ((i + j) % 3 == b)
                M[i][j] = 'O';
        }
        FOR(i, 0, N) printf("%s\n", M[i]);
        return;
    }
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}