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
ll N;
vi N_DIG;

int main() {
    rl(N);
    {
        ll aux_n = N;
        while (aux_n > 0) {
            N_DIG.pb(aux_n % 10);
            aux_n /= 10;
        }
        reverse(ALL(N_DIG));
    }

    int ans = INF;
    FOR(i, 0, SZ(N_DIG)) FOR(j, 0, SZ(N_DIG)) if (i != j) {
        vi aux;
        FOR(k, 0, SZ(N_DIG)) aux.pb(N_DIG[k]);

        int cnt = 0;
        FOR(k, j, SZ(N_DIG) - 1) {
            swap(aux[k], aux[k + 1]);
            cnt++;
        }
        int epa = 0;
        if (i > j) epa = 1;
        FOR(k, i - epa, SZ(N_DIG) - 2) {
            swap(aux[k], aux[k + 1]);
            cnt++;
        }
        int fst_zero;
        FOR(k, 0, SZ(N_DIG)) if (aux[k] != 0) {
            fst_zero = k;
            break;
        }

        for (int k = fst_zero; k > 0; --k) {
            swap(aux[k], aux[k - 1]);
            cnt++;
        }

        if ((10 * aux[SZ(aux) - 2] + aux[SZ(aux) - 1]) % 25 == 0)
            ans = min(ans, cnt);

    }
    printf("%d\n", (ans == INF ? -1 : ans));
    return 0;
}