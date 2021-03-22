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
const int MAXN = 1e6; // CAMBIAR ESTE

// GJNM
ll L, A, B, T, R, N;
vector< pair<ll, ll> > ARR;
ll UBI[MAXN];

long double D[MAXN];
bool BUY[MAXN];
ll PREV[MAXN];

int main() {
    rl(L), rll(A, B), rll(T, R);
    rl(N);
    FOR(i, 0, N) {
        PREV[i] = -1;
        ll aux; rl(aux);
        UBI[i] = aux;
        ARR.pb({aux, i});
    }
    PREV[N] = -1;
    ARR.pb({L, N});
    UBI[N] = L;
    sort(ALL(ARR));
    FOR(i, 0, N + 1) D[i] = 1e14;

    FOR(i, 0, N) {
        ll x = ARR[i].S;
        ll dx = ARR[i].F;
        D[x] = min(D[x], (long double)dx / A);

        {   // no comprar
            auto it = upper_bound(ALL(ARR), make_pair(dx, x));
            ll y = it->S;
            ll dy = it->F;
            if (D[y] > D[x] + ((long double)dy - dx) / A) {
                D[y] = D[x] + ((long double)dy - dx) / A;
                PREV[y] = x;
                BUY[y] = false;
            }
        }

        {
            ll new_dx = dx + A * T + B * R;
            auto it = lower_bound(ALL(ARR), make_pair(new_dx, -1ll));
            if (it == ARR.end() || (it->F) > new_dx) --it;
            ll y = it->S;
            ll dy = it->F;
            long double fst = min(dy - dx, A * T);
            long double snd = min(dy - dx - fst, (long double) B * R);
            if (D[y] > D[x] + fst / A + snd / B) {
                D[y] = D[x] + fst / A + snd / B;
                BUY[y] = true;
                PREV[y] = x;
            }
        }

        {
            ll new_dx = dx + A * T + B * R;
            auto it = lower_bound(ALL(ARR), make_pair(new_dx, -1ll));
            if (it != ARR.end()) {
                ll y = it->S;
                ll dy = it->F;
                long double fst = A * T;
                long double snd = B * R;
                fst += (dy - dx - fst - snd);
                if (D[y] > D[x] + fst / A + snd / B) {
                    D[y] = D[x] + fst / A + snd / B;
                    BUY[y] = true;
                    PREV[y] = x;
                }
            }
        }
    }

    vector<ll> ans;
    ll at = N;
    bool buy = false;
    while (at != -1) {
        if (buy) ans.pb(at);
        buy = BUY[at];
        at = PREV[at];
    }

    printf("%d\n", SZ(ans));
    for (auto x : ans) printf("%lld ", x);
    printf("\n");

    return 0;
}