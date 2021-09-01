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
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
ll A[MAXN];

int main() {
    ri(N);
    FOR(i, 0, N) rl(A[i]);
    FOR(i, 0, N) if (i & 1) A[i] = -A[i];
    ll ans = 0;

    for (int i = 0; i < N; i += 2) {
        ll need = 0;
        ll sm = 0;
        for (int j = i + 1; j < N; ++j) {
            if (j & 1) {
                ll aux_sm = sm;
                ll ai = A[i], aj = -A[j];
                ll aux_need = need;
                if (aux_need < 0) {
                    ll move = min(ai, -aux_need);
                    aux_need += move;
                    ai -= move;
                    aux_sm += move;
                }
                if (aux_sm > 0) {
                    ll move = min(aux_sm, aj);
                    aj -= move;
                    aux_sm -= move;
                }
                if (aux_need == 0 && aux_sm == 0)
                    ans += min(ai, aj) + (i != j - 1);

                sm += A[j];
                need = min(need, sm);
            }
            else
                sm += A[j];
        }
    }

    printf("%lld\n", ans);

    return 0;
}