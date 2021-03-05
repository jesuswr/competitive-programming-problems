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
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
int N, M;
ll DP[1 << 18][100];
bool VIS[1 << 18][100];
ll TEN[20];
ll A[20];

int MSK[10];
vi INDS[10];


ll f(int msk, int mod, int p = N - 1) {
    if (msk == (1 << N) - 1) return mod == 0;
    if (VIS[msk][mod]) return DP[msk][mod];
    VIS[msk][mod] = true;
    ll &ret = DP[msk][mod] = 0;
    FOR(i, p == N - 1, 10) {
        if ((MSK[i] & msk) == MSK[i]) continue;
        for (auto j : INDS[i]) {
            if (msk & (1 << j)) continue;
            ret += f(msk | (1 << j), (mod + TEN[p] * i) % M, p - 1);
            break;
        }
    }
    return ret;
}

int main() {
    {
        TEN[0] = 1;
        FOR(i, 1, 19) TEN[i] = 10ll * TEN[i - 1];
        ll aux_n;
        rl(aux_n);
        while (aux_n > 0) {
            A[N++] = aux_n % 10;
            aux_n /= 10;
        }
        FOR(i, 0, N) {
            MSK[A[i]] |= (1 << i);
            INDS[A[i]].pb(i);
        }
    }
    ri(M);
    ll tot = f(0, 0);
    printf("%lld\n", tot);
    return 0;
}