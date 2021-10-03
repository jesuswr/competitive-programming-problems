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
const int MAXN = 1e6 + 69; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int MX[MAXN][2];
int ANS[MAXN];
int F[MAXN];

int main() {
    memset(MX, -1, sizeof(MX));
    int n; ri(n);
    ANS[0] = 0;
    FOR(_u, 1, n + 1) {
        int u = _u;
        ri(F[u]); --F[u];
        ANS[u] = 1;
        while (u != 0) {
            // printf("\t%d %d\n", u + 1, F[u] + 1);
            if (MX[F[u]][0] < ANS[u]) {
                MX[F[u]][1] = MX[F[u]][0];
                MX[F[u]][0] = ANS[u];
            }
            else if (MX[F[u]][1] < ANS[u])
                MX[F[u]][1] = ANS[u];

            int new_ans = max(MX[F[u]][0], MX[F[u]][1] + 1 * (F[u] != 0));
            if (new_ans == ANS[F[u]])
                break;
            ANS[F[u]] = new_ans;
            u = F[u];
        }
        printf("%d ", ANS[0]);
    }
    printf("\n");
    return 0;
}