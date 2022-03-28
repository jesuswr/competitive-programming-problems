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
const int MAXN = 1e5; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
// Todos los rangos son semi-abiertos [a,b)
int N, Q, A[MAXN];
pii B[MAXN];
int PRV[MAXN], NXT[MAXN];

void pre() {
    stack<int> st;
    FOR(i, 0, N) {
        while (!st.empty() && B[st.top()] < B[i])
            st.pop();
        PRV[i] = (st.empty() ? -1 : st.top());
        st.push(i);
    }
    while (!st.empty()) st.pop();
    FOR(_i, 0, N) {
        int i = N - _i - 1;
        while (!st.empty() && B[st.top()] < B[i])
            st.pop();
        NXT[i] = (st.empty() ? N : st.top());
        st.push(i);
    }
}

int main() {
    rii(N, Q);
    FOR(i, 0, N) ri(A[i]);
    FOR(i, 0, N - 1) B[i].F = abs(A[i] - A[i + 1]);
    FOR(i, 0, N - 1) B[i].S = i;
    --N;
    pre();
    while (Q--) {
        int l, r; rii(l, r);
        --l; r -= 2;
        ll ans = 0;
        for (int i = l; i <= r; ++i)
            ans += 1ll * B[i].F * (i - max(l, PRV[i] + 1) + 1) * (min(r, NXT[i] - 1) - i + 1);
        printf("%lld\n", ans);
    }

    return 0;
}