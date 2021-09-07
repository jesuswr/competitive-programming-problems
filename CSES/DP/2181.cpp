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
const int MAXN = 1e5; // CAMBIAR ESTE
const int MOD = 1e9 + 7;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, M;


vi NXT[1 << 10];
void pre() {
    // int mx = 0;
    FOR(msk, 0, 1 << N) {
        FOR(nxt_msk, 0, 1 << N) {
            int b = 0;
            bool add = true;
            while (b < N && add) {
                bool l = (msk >> b) & 1, r = (nxt_msk >> b) & 1;
                if (l && r)
                    add = false;
                else if (!l && r)
                    ++b;
                else if (l && !r)
                    ++b;
                else if (b + 1 < N) {
                    bool nl = (msk >> (b + 1)) & 1, nr = (nxt_msk >> (b + 1)) & 1;
                    if (nl || nr)
                        add = false;
                    else
                        b += 2;
                }
                else
                    add = false;
            }
            if (add)
                NXT[msk].pb(nxt_msk);
        }
        // mx = max(mx, SZ(NXT[msk]));
    }
    // printf("%d\n", mx);
}

int DP[1001][1 << 10];


int main() {
    rii(N, M);
    pre();
    DP[M][0] = 1;
    for (int i = M - 1; i >= 0; --i)
        for (int msk = 0; msk < (1 << N); ++msk)
            for (int nxt_msk : NXT[msk]) {
                DP[i][msk] += DP[i + 1][nxt_msk];
                if (DP[i][msk] >= MOD)
                    DP[i][msk] -= MOD;
            }
    printf("%d\n", DP[0][0]);
    return 0;
}