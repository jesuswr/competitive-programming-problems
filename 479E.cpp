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
const int MAXN = 5010; // CAMBIAR ESTE
const int MOD = 1e9 + 7;


struct BIT {
    ll A[MAXN];
    void upd(int p, ll val) {
        p++;    // esto es porque el bit esta indexado desde 1
        for (; p < MAXN; p += p & -p) // se puede cambiar maxN por n+1 si hace falta mas velocidad
            A[p] += val;
    }
    ll sum(int p) {
        p++;
        ll ret = 0;
        for (; p; p -= p & -p)
            ret += A[p];
        return ret;
    }
};

BIT bits[MAXN];

int main() {
    int N, A, B, K; rii(N, A), rii(B, K);
    FOR(i, 1, N + 1) {
        if (i != B)
            bits[0].upd(i, 1);
    }
    FOR(i, 1, K + 1) {
        FOR(a, 1, B) { // [1,B)
            int dist = B - a - 1;
            ll sm = bits[i - 1].sum(a - 1) - bits[i - 1].sum(max(0, a - dist - 1));
            sm += bits[i - 1].sum(a + dist) - bits[i - 1].sum(a);
            bits[i].upd(a, sm % MOD);
        }
        FOR(a, B + 1, N + 1) { // [B+1, N]
            int dist = a - B - 1;
            ll sum = bits[i - 1].sum(a - 1) - bits[i - 1].sum(B);
            sum += bits[i - 1].sum(min(a + dist, N)) - bits[i - 1].sum(a);
            bits[i].upd(a, sum % MOD);
        }
    }
    printf("%lld\n", (bits[K].sum(A) - bits[K].sum(A - 1) + MOD) % MOD);

    return 0;
}