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
const int MOD = 1e9 + 7;

// GJNM
int n, m;
string s, t;
vi ind;
int DP[2][MAXN];


int main() {
    cin >> s >> t;
    ri(m);

    t = t + t;

    n = SZ(s);
    FOR(i, 0, n) {
        if (t.compare(i, n, s) == 0){
            DP[m & 1][i] = 1;
        }
    }

    for (int i = m - 1; i >= 0; --i) {
        int curr = i & 1; int prev = curr ^ 1;

        int sm = 0;
        FOR(j, 0, n) {
            sm += DP[prev][j];
            if (sm >= MOD)
                sm -= MOD;
        }

        FOR(j, 0, n) DP[curr][j] = (sm - DP[prev][j] + MOD) % MOD;
    }

    printf("%d\n", DP[0][0]);

    return 0;
}