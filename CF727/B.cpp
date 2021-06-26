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
const int MAXN = 2e5; // CAMBIAR ESTE

// GJNM
string S;
int PRE[MAXN][30];

int main() {
    int n, q; rii(n, q);
    cin >> S;

    FOR(i, 0, n) {
        ++PRE[i + 1][S[i] - 'a'];
        FOR(j, 0, 30) {
            PRE[i + 1][j] += PRE[i][j];
        }
    }

    while (q--) {
        int l, r; rii(l, r); --l;
        int ans = 0;
        FOR(i, 0, 30) {
            ans += (PRE[r][i] - PRE[l][i]) * (i + 1);
        }
        printf("%d\n", ans);
    }

    return 0;
}