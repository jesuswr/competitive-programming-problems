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
const int MAXN = 6e5 + 10; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM

// Todos los rangos son semi-abiertos [a,b)
int N, Q;
bool FND[MAXN];

ll BIT[MAXN];
void updBIT(int p, ll val){
    p++;
    for(; p < MAXN; p += p&-p) BIT[p] += val;
}
ll sumBIT(int p){
    p++;
    ll ret = 0;
    for(; p; p -= p&-p) ret += BIT[p];
    return ret;
}

struct event {
    bool is_q;
    int i;
    int x;
    int l, r;

    bool operator<(event &other) {
        if (x != other.x)
            return x > other.x;
        return
            is_q < other.is_q;
    }
};


int main() {
    rii(N, Q);
    vector<event> ord;
    FOR(i, 0, N) {
        event aux;
        aux.is_q = false;
        aux.i = i;
        ri(aux.x);
        ord.pb(aux);
    }
    FOR(i, 0, Q) {
        int a, p, f; riii(a, p, f);
        event aux;
        aux.is_q = true;
        aux.i = i;
        aux.x = p;
        aux.l = a;
        aux.r = a + f;
        ord.pb(aux);
    }
    sort(ALL(ord));
    vi ans(Q);
    for (auto &e : ord) {
        if (e.is_q) {
            if (FND[e.l - 1])
                ans[e.i] = 0;
            else if (e.l != e.r)
                ans[e.i] = sumBIT(e.r - 1) - sumBIT(e.l - 1);
        }
        else {
            FND[e.i] = 1;
            updBIT(e.i, 1);
        }
    }
    for (auto x : ans) printf("%d\n", x);

    return 0;
}