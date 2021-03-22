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
const int MAXN = 110; // CAMBIAR ESTE
const int ALPHA = 26;

// GJNM
string S1, S2, V;

int PI[MAXN];
void pf() {
    int n = SZ(V);
    FOR(i, 1, n) {
        int j = PI[i - 1];
        while (j > 0 && V[j] != V[i]) j = PI[j - 1];
        if (V[i] == V[j]) PI[i] = j + 1;
    }
}

int NXT[MAXN][ALPHA];
void pre() {
    int n = SZ(V);
    V += '$';
    FOR(i, 0, n + 1) {
        FOR(j, 0, ALPHA) {
            int k = i;
            while (k > 0 && V[k] != ('A' + j)) k = PI[k - 1];
            if (V[k] == ('A' + j)) NXT[i][j] = k + 1;
        }
    }
    V.pop_back();
}

int DP[MAXN][MAXN][MAXN];
bool VIS[MAXN][MAXN][MAXN];
int f(int p1, int p2, int pi) {
    if (pi == SZ(V)) return DP[p1][p2][pi] = -INF;
    if (p1 == SZ(S1) || p2 == SZ(S2)) return 0;
    int &ret = DP[p1][p2][pi];
    if (VIS[p1][p2][pi]) return ret;
    VIS[p1][p2][pi] = true;

    ret = max(f(p1 + 1, p2, pi), f(p1, p2 + 1, pi));
    if (S1[p1] == S2[p2]) ret = max(ret, 1 + f(p1 + 1, p2 + 1, NXT[pi][S1[p1] - 'A']));
    return ret;
}

int main() {
    cin >> S1 >> S2 >> V;
    pf();
    pre();
    int ans = f(0, 0, 0);
    if (ans == 0) printf("0");
    else {
        int p1 = 0, p2 = 0, pi = 0;
        while (DP[p1][p2][pi] > 0) {
            if (DP[p1][p2][pi] == DP[p1 + 1][p2][pi]) ++p1;
            else if (DP[p1][p2][pi] == DP[p1][p2 + 1][pi]) ++p2;
            else {
                printf("%c", S1[p1]);
                pi = NXT[pi][S1[p1] - 'A'];
                ++p1, ++p2;
            }
        }
    }
    printf("\n");
    return 0;
}