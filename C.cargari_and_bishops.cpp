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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
int n;
ll mat[2010][2100];
ll diag1[4010], diag2[4010];

int main() {
    ri(n);
    FOR(r, 0, n) {
        FOR(c, 0, n) {
            rl(mat[r][c]);
            diag1[r + c] += mat[r][c];
            diag2[n - 1 + r - c] += mat[r][c];
        }
    }

    ll black = -1, white = -1;
    int br, bc, wr, wc;

    FOR(r, 0, n) {
        FOR(c, 0, n) {
            if ((r + c) & 1) { // white
                ll old_w = white;
                white = max(white, diag1[r + c] + diag2[n - 1 + r - c] - mat[r][c]);
                if (old_w != white) {
                    wr = r + 1;
                    wc = c + 1;
                }
            }
            else { // black
                ll old_b = black;
                black = max(black, diag1[r + c] + diag2[n - 1 + r - c] - mat[r][c]);
                if (old_b != black) {
                    br = r + 1;
                    bc = c + 1;
                }
            }
        }
    }
    printf("%lld\n", black + white);
    printf("%d %d %d %d\n", br, bc, wr, wc);

    return 0;
}