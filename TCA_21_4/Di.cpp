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
const int MAXN = 1e5 + 69; // CAMBIAR ESTE
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, A[MAXN], B[MAXN];
int CNT[MAXN];

bool valid(int k) {
    FOR(i, 0, N + 1) CNT[i] = 0;
    FOR(i, 0, N) CNT[A[i]]++;

    priority_queue<tuple<int, int>> pq;
    FOR(i, 0, N) if (CNT[i + 1] > 0) pq.push({CNT[i + 1], i + 1});

    FOR(i, 0, N) {
        if (i >= k + 1 && CNT[B[i - k - 1]])
            pq.push({CNT[B[i - k - 1]], B[i - k - 1]});

        if (pq.empty())
            return false;
        auto [cnt, ind] = pq.top(); pq.pop();
        B[i] = ind;
        --CNT[ind];
    }
    return true;
}

void solve() {
    ri(N);
    FOR(i, 0, N) ri(A[i]);
    int lo = 0, hi = N;
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
    while (t--) solve();
    return 0;
}