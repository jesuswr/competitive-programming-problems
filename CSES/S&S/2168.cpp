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
const int MAXN = 2e5 + 10; // CAMBIAR ESTE
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
struct range {
    int l, r, i;

    bool operator<(const range &b) {
        if (l != b.l)
            return l < b.l;
        return r > b.r;
    }
};

bool comp2(const range &a, const range &b) {
    if (a.r != b.r)
        return a.r < b.r;
    return a.l > b.l;
}

int CONT[MAXN], IS_CONT[MAXN];

int main() {
    int n; ri(n);
    vector<range> sweep(n);
    FOR(i, 0, n) {
        rii(sweep[i].l, sweep[i].r);
        sweep[i].i = i;
    }

    sort(ALL(sweep));
    int mx = 0;
    for (auto e : sweep) {
        if (e.r <= mx)
            IS_CONT[e.i] = 1;
        else
            mx = e.r;
    }
    sort(ALL(sweep), comp2);
    int mn = 0;
    for (auto e : sweep) {
        if (e.l <= mn)
            CONT[e.i] = true;
        else
            mn = e.l;
    }

    FOR(i, 0, n) printf("%d ", CONT[i]);
    printf("\n");
    FOR(i, 0, n) printf("%d ", IS_CONT[i]);
    printf("\n");

    return 0;
}