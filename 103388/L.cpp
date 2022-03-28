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
const int MAXN = 6e5 + 29; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, M;
string S;

struct DSU {
    int father[MAXN], siz[MAXN];
    void makeSet(int n, int m) {
        for (int i = n; i <= m; ++i) {
            father[i] = -1;
            siz[i] = 0;
        }
    }
    int find(int x) {
        if (father[x] == -1)
            return x;
        return father[x] = find(father[x]);
    }
    void unio(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (siz[x] > siz[y])
            father[y] = x;
        else {
            father[x] = y;
            if ( siz[x] == siz[y] ) siz[y]++;
        }
    }
};

DSU dsu[20];


int main() {
    rii(N, M);
    cin >> S;
    FOR(b, 0, 20) dsu[b].makeSet(0, 2 * N - 1);
    FOR(_, 0, M) {
        int l, r; rii(l, r);
        --l, --r;
        int sz = r - l + 1, pl = l, pr = 2 * N - 1 - r;
        for (int b = 19; b >= 0; --b) {
            if ((sz >> b) & 1) {
                dsu[b].unio(pl, pr);
                pl += 1 << b;
                pr += 1 << b;
            }
        }
    }
    for (int b = 19; b > 0; --b) {
        for (int i = 0; i + (1 << b) <= 2 * N; ++i) {
            int p = dsu[b].find(i);
            dsu[b - 1].unio(i, p);
            dsu[b - 1].unio(i + (1 << (b - 1)), p + (1 << (b - 1)));
        }
    }

    FOR(i, 0, N) dsu[0].unio(i, 2 * N - 1 - i);

    vi ans(2 * N);
    FOR(i, 0, N) if (S[i] != '?')
        ans[ dsu[0].find(i) ] |= 1 << (S[i] - '0');
    ll cnt = 1;
    const ll MOD = 1e9 + 7;
    FOR(i, 0, 2 * N) {
        if (dsu[0].find(i) != i) continue;
        if (ans[i] == 0) cnt = (cnt * 2) % MOD;
        else if (ans[i] == 3) cnt = 0;
    }

    printf("%lld\n", cnt);
    return 0;
}