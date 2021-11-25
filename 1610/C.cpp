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
int N;
int L[MAXN], R[MAXN];

bool valid(int k) {
    int l = 0, r = k - 1;
    //printf("%d : \n", k);
    for (int i = 0; i < N && l < k; ++i) {
        //printf("\t %d %d %d\n", i, l, r);
        if (L[i] >= l && R[i] >= r) {
            l++;
            r--;
            //printf("\t\tyess\n");
        }
    }
    return l == k;
}

void solve() {
    ri(N);
    FOR(i, 0, N) rii(R[i], L[i]);
    int lo = 1, hi = N;
    while (lo < hi) {
        int mi = lo + (hi - lo + 1) / 2;
        if (valid(mi))
            lo = mi;
        else
            hi = mi - 1;
    }
    printf("%d\n", lo);
}

int main() {
    int t; ri(t);
    while (t--)
        solve();

    return 0;
}