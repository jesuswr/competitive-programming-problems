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
const int LOG = 18; // CAMBIAR ESTE

// GJNM
int N, Q;
int A[MAXN];

int MND[MAXN];
void pre() {
    FOR(i, 0, MAXN) MND[i] = INF;
    FOR(i, 2, MAXN) {
        if (MND[i] != INF) continue;
        for (int j = i; j < MAXN; j += i)
            MND[j] = min(MND[j], i);
    }
}

int NXT[MAXN][LOG];
int NXT_D[MAXN];
void pre2() {
    FOR(b, 0, LOG) NXT[N][b] = N;
    for (int i = N - 1; i >= 0; --i) {
        NXT[i][0] = NXT[i + 1][0];
        while (A[i] > 1) {
            int div = MND[A[i]];
            while (A[i] % div == 0) A[i] /= div;
            if (NXT_D[div] > 0) NXT[i][0] = min(NXT[i][0], NXT_D[div]);
            NXT_D[div] = i;
        }

        for (int b = 1; b < LOG; ++b)
            NXT[i][b] = NXT[ NXT[i][b - 1] ][b - 1];
    }
}

int main() {
    pre();
    rii(N, Q);
    FOR(i, 0, N) ri(A[i]);
    pre2();
    FOR(_, 0, Q) {
        int l, r; rii(l, r); --l, --r;
        int ans = 0;
        while (l <= r) {
            int b = 0;
            for (int aux = 1; aux < LOG; ++aux) {
                if (NXT[l][aux] <= r && NXT[l][aux] > NXT[l][b])
                    b = aux;
            }
            ans += (1 << b);
            l = NXT[l][b];
        }
        printf("%d\n", ans);
    }

    return 0;
}