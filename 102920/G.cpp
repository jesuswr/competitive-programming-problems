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
const ll LLINF = 2e17;
const int MAXN = 2e6; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
ll N, D;
ll X[MAXN];


ll go(ll d) {
    ll l = 0, r = 0, dta = 0;
    FOR(i, 0, N) {
        ll aux = X[0] + dta;
        dta += d;
        if (aux > X[i]) r = max(r, aux - X[i]);
        else l = max(l, X[i] - aux);
    }
    return (l + r) / 2;
}

int main() {
    rll(N, D);
    D *= 10;
    FOR(i, 0, N) rl(X[i]);
    FOR(i, 0, N) X[i] = X[i] * 10;
    ll ans = min(go(D), go(-D));
    printf("%lld.%lld\n", ans / 10, ans % 10);

    return 0;
}