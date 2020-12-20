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
const int MAXN = 310; // CAMBIAR ESTE

// GJNM
int N;
char M[MAXN][MAXN];

bool check(int r, int c, int dr, int dc) {
    FOR(_, 0, 3) {
        if (min(r, c) < 0 || max(r, c) >= N || M[r][c] != 'X')
            return false;
        r += dr;
        c += dc;
    }
    return true;
}

void solve() {
    ri(N);
    FOR(i, 0, N) dadsadasda = scanf("%s\n", M[i]);

    int cnt[3] = {0, 0, 0};
    FOR(r, 0, N) FOR(c, 0, N) cnt[(r + c) % 3] += M[r][c] == 'X';
    int mxi = 0;
    FOR(i, 1, 3) {
        if (cnt[i] < cnt[mxi])
            mxi = i;
    }
    FOR(r, 0, N) FOR(c, 0, N) {
        if (M[r][c] == 'X' && (r + c) % 3 == mxi)
            M[r][c] = 'O';
    }

    FOR(i, 0, N) printf("%s\n", M[i]);
}


int main() {
    int t; ri(t);
    while (t--)
        solve();

    return 0;
}