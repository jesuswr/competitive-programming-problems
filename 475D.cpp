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
const int MAXN = 1e5 + 1; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
// Todos los rangos son semi-abiertos [a,b)
int N, A[MAXN];

int GCD[MAXN][21];
void pre() {
    for (int i = N - 1; i >= 0; --i) {
        GCD[i][0] = A[i];
        for (int p = 1; p < 21 && (i + (1 << p)) <= N; ++p) {
            GCD[i][p] = __gcd(GCD[i][p - 1], GCD[i + (1 << (p - 1))][p - 1]);
        }
    }
}

int main() {
    ri(N);
    FOR(i, 0, N) ri(A[i]);
    pre();
    map<int, ll> cnt;
    FOR(i, 0, N) {
        int l = i;
        int gcd = A[i];
        while (l < N) {
            gcd = __gcd(gcd, A[l]);
            int u = l;
            bool change = 1;
            while (change && u < N) {
                change = 0;
                for (int p = 20; p >= 0; --p) {
                    if ((GCD[u][p] != 0) && __gcd(GCD[u][p], gcd) == gcd) {
                        u = u + (1 << p);
                        change = 1;
                        break;
                    }
                }
            }
            cnt[gcd] += u - l;
            // printf("[%d, %d) : %d\n", i, u, gcd);
            l = u;
        }
    }
    int q; ri(q);
    while (q--) {
        int x; ri(x);
        printf("%lld\n", cnt[x]);
    }
    return 0;
}