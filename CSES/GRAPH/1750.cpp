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
const int MAXN = 2e5 + 69; // CAMBIAR ESTE
const int LOGK = 30;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, Q;
int SUC[LOGK + 1][MAXN];

int main() {
    rii(N, Q);
    FOR(i, 0, N) {
        int a; ri(a);
        SUC[0][i] = a - 1;
    }
    for (int k = 1; k <= LOGK; ++k)
        FOR(i, 0, N) SUC[k][i] = SUC[k - 1][ SUC[k - 1][i] ];
    while (Q--) {
        int a, k; rii(a, k); --a;
        for (int b = LOGK; b >= 0; --b)
            if ((k >> b) & 1)
                a = SUC[b][a];
        printf("%d\n", a + 1);
    }

    return 0;
}