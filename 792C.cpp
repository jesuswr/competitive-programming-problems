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
const int MAXN = 2e5; // CAMBIAR ESTE

// GJNM
string t;
int N;
int A[MAXN];
int DP[MAXN][4][4];
piii NXT[MAXN][4][4];

int f(int p, int s, int mod) { // position-start?-sum % 3
    if (p == N && mod == 0) return DP[p][s][mod] = (s == 0 ? 0 : INF);
    if (p >= N) return INF;
    if (DP[p][s][mod] != -1) return DP[p][s][mod];
    int &ret = DP[p][s][mod] = INF;
    if (s == 1 && A[p] == 0) {
        NXT[p][s][mod] = {p + 1, {s, mod}};
        return ret = 1 + f(p + 1, s, mod);
    }
    ret = min(f(p + 1, 0, (mod + A[p]) % 3) , 1 + f(p + 1, s, mod) );
    if (ret == 1 + f(p + 1, s, mod)) NXT[p][s][mod] = {p + 1, {s, mod}};
    else NXT[p][s][mod] = {p + 1, {0, (mod + A[p]) % 3}};
    return ret;
}

int main() {
    cin >> t;
    N = SZ(t);
    memset(DP, -1, sizeof(DP));
    FOR(i, 0, N) A[i] = t[i] - '0';
    int ans = f(0, 1, 0);
    if (ans == INF) {
        FOR(i, 0, N) if (A[i] == 0) {printf("0\n"); return 0;}
        printf("-1\n");
    }
    else {
        int p = 0, s = 1, m = 0;
        while (p < N) {
            int new_p = NXT[p][s][m].F, new_s = NXT[p][s][m].S.F, new_m = NXT[p][s][m].S.S;
            if (DP[p][s][m] == DP[new_p][new_s][new_m]) printf("%d", A[p]);
            p = new_p;
            s = new_s;
            m = new_m;
        }
        printf("\n");
    }

    return 0;
}