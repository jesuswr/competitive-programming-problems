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
const int MAXN = 1e5 + 10; // CAMBIAR ESTE

// GJNM
int N;
string s;
int DP[MAXN][2][2];

int f(int p, int c1, int c2) {
    if (p >= N) return 0;
    if (DP[p][c1][c2] != -1) return DP[p][c1][c2];
    DP[p][c1][c2] = INF;
    FOR(i, 0, 26) {
        if (s[p] == i + 'a' && c1 > 0) continue;

        int new_c2 = s[p + 2] == i + 'a';
        int new_c1 = s[p + 1] == i + 'a'; new_c1 = max(new_c1, c2);
        int extra = s[p] != i + 'a';
        DP[p][c1][c2] = min(DP[p][c1][c2], extra + f(p + 1, new_c1, new_c2));
    }
    return DP[p][c1][c2];
}


int main() {
    int t; ri(t);
    while (t--) {
        cin >> s;
        N = SZ(s);
        s += "$$$$$";
        FOR(i, 0, N + 10) FOR(j, 0, 2) FOR(k, 0, 2) DP[i][j][k] = -1;
        printf("%d\n", f(0, 0, 0));
    }

    return 0;
}