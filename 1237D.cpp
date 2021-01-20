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

using namespace std;

typedef long long ll;
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
const int MAXN = 3e5 + 10; // CAMBIAR ESTE

// GJNM

// Todos los rangos son semi-abiertos [a,b)
int N, A[MAXN], NXT[MAXN];
struct STN {
    int mn;
    void merge(STN& L, STN& R) {
        mn = min(L.mn, R.mn);
    }
    void operator=(int a) {
        mn = a;
    }
};
STN ST[4 * MAXN];
void STB(int id = 1, int l = 0, int r = 3 * N) {
    if (r - l < 2) {
        ST[id] = A[l];
        return;
    }
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    STB(L, l, m); STB(R, m, r);
    ST[id].merge(ST[L], ST[R]);
}
int STQ(int x, int y, int mn, int id = 1, int l = 0, int r = 3 * N) {
    if (x >= r || y <= l || ST[id].mn >= mn) return -1;
    if (l == r - 1 && ST[id].mn < mn) return l;
    int m = (l + r) >> 1, L = id << 1, R = L | 1;
    int op1 = STQ(x, y, mn, L, l, m);
    if (op1 != -1) return op1;
    return STQ(x, y, mn, R, m, r);
}

int DP[MAXN];
int f(int p) {
    if (DP[p] != -1) return DP[p];
    if (p + 1 != NXT[p]) {
        int q = STQ(p + 1, NXT[p], (A[p] + 1) / 2);
        if (q != -1) return DP[p] = q;
    }
    if (NXT[p] == 3 * N) return DP[p] = INF;
    else return DP[p] = f(NXT[p]);
}

int main() {
    ri(N);
    FOR(i, 0, N) {
        ri(A[i]);
        A[N + i] = A[2 * N + i] = A[i];
    }
    STB();
    stack<int> st;
    for (int i = 3 * N - 1; i >= 0; i--) {
        while (!st.empty() && A[st.top()] < A[i]) st.pop();

        if (st.empty()) NXT[i] = 3 * N;
        else NXT[i] = st.top();
        st.push(i);
    }
    memset(DP, -1, sizeof(DP));
    for (int i = N - 1; i >= 0; i--) f(i);
    FOR(i, 0, N) {
        if (DP[i] == INF) printf("%d ", -1);
        else printf("%d ", DP[i] - i);
    }
    printf("\n");
    return 0;
}