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
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
// Todos los rangos son semi-abiertos [a,b)
int N, M, A[MAXN];
struct STN {
    int mx;
    void merge(STN& L, STN& R) {
        mx = max(L.mx, R.mx);
    }
    void operator=(int a) {
        mx = a;
    }
};
STN ST[4 * MAXN];
void STB(int id = 1, int l = 0, int r = N) {
    if (r - l < 2) {
        ST[id] = A[l];
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    STB(L, l, m); STB(R, m, r);
    ST[id].merge(ST[L], ST[R]);
}
int STQ(int k, int id = 1, int l = 0, int r = N) {
    if (ST[id].mx < k)
        return -1;
    if (r - l < 2) {
        ST[id].mx -= k;
        return l;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    int res = STQ(k, L, l, m);
    if (res == -1)
        res = STQ(k, R, m, r);
    ST[id].merge(ST[L], ST[R]);
    return res;
}

int main() {
    rii(N, M);
    FOR(i, 0, N) ri(A[i]);
    STB();
    while (M--) {
        int r; ri(r);
        printf("%d ", STQ(r) + 1);
    }
    printf("\n");
    return 0;
}