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
const int MAXN = 510; // CAMBIAR ESTE

// GJNM
int R, C;
char M[MAXN][MAXN];
int pre[MAXN][MAXN];

bool valid(int r, int c1, int c2) {
    int sum = pre[r][c2] - (c1 > 0 ? pre[r][c1 - 1] : 0);
    int need = c2 - c1 + 1;
    return sum == need;
}


void solve() {
    rii(R, C);
    FOR(i, 0, R) {
        dadsadasda = scanf("%s", M[i]);
    }
    FOR(i, 0, R) {
        FOR(j, 0, C) {
            pre[i][j] = (M[i][j] == '*');
            if (j > 0)
                pre[i][j] += pre[i][j - 1];
        }
    }
    int ans = 0;
    FOR(r, 0, R) {
        FOR(c, 0, C) {
            int row = r, col1 = c, col2 = c;
            while (row < R && col1 >= 0 && col2 < C && valid(row, col1, col2)) {
                ans++;
                row++;
                col1--;
                col2++;
            }
        }
    }
    printf("%d\n", ans);
}


int main() {
    int t;
    ri(t);
    while (t--)
        solve();
    return 0;
}