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
const int MAXN = 10001; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int MN_DIV[MAXN];
void pre() {
    FOR(i, 0, MAXN) MN_DIV[i] = INF;
    FOR(i, 2, MAXN) if (MN_DIV[i] == INF) {
        for (int j = i; j < MAXN; j += i)
            MN_DIV[j] = min(MN_DIV[j], i);
    }
}
int N;
int A[MAXN], F[MAXN];


int main() {
    pre();
    while (scanf("%d\n", &N) != EOF) {
        FOR(i, 0, N) {
            ri(A[i]);
            F[A[i]]++;
        }

        ll ans = 0;
        if (N >= 4)
            ans = (1ll * N * (N - 1) * (N - 2) * (N - 3)) / 24ll;

        for (int dv = 2; dv < MAXN; ++dv) {
            int aux = dv;
            int cnt = 0;
            bool good = 1;
            while (aux > 1) {
                int aux_d = MN_DIV[aux];
                ++cnt;
                aux /= aux_d;
                if (aux % aux_d == 0) {
                    good = 0;
                    break;
                }
            }
            if (!good)
                continue;

            int tmp = 0;
            for (aux = dv; aux <  MAXN; aux += dv)
                tmp += F[aux];
            if (cnt & 1)
                ans -= (1ll * tmp * (tmp - 1) * (tmp - 2) * (tmp - 3)) / 24ll;
            else
                ans += (1ll * tmp * (tmp - 1) * (tmp - 2) * (tmp - 3)) / 24ll;
            // printf("%d : %lld\n", dv, (1ll * tmp * (tmp - 1) * (tmp - 2) * (tmp - 3)) / 24ll);
        }

        printf("%lld\n", ans);


        FOR(i, 0, N) F[A[i]]--;
    }

    return 0;
}