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
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
int h, w;
int M[21][21];


void solve() {
    rii(h, w);
    FOR(i, 0, h) FOR(j, 0, w) M[i][j] = 0;
    for (int i = 0; i < w; i += 2) M[0][i] = 1;
    if (h > 2) {
        for (int i = w - 1; i >= 0; i -= 2) M[h - 1][i] = 1;

        for (int i = 2; i < h - 2; i += 2) M[i][0] = 1;

        for (int i = h - 3; i >= 2; i -= 2) M[i][w - 1] = 1;
    }

    FOR(i, 0, h) {
        FOR(j, 0, w) printf("%d", M[i][j]);
        printf("\n");
    }

}

int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}