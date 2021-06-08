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
const int MAXN = 4e5; // CAMBIAR ESTE

// GJNM
int N, M;
int A[MAXN]; char C[MAXN];
int T[MAXN];


void f(const vector<tuple<int, char, int>> &a) {
    deque<tuple<int, int>> st;

    for (auto [pos, c, i] : a) {
        if (c == 'L') {
            if (st.empty()) {
                st.push_front({ -pos, i});
            }
            else {
                auto [pos2, i2] = st.back(); st.pop_back();
                int t = (pos - pos2) / 2;
                T[i] = T[i2] = t;
            }
        }
        else {
            st.push_back({pos, i});
        }
    }
    while (st.size() > 1) {
        auto [pos, i] = st.back(); st.pop_back();
        auto [pos2, i2] = st.back(); st.pop_back();
        int t = (2 * M - pos2 - pos) / 2;
        T[i] = T[i2] = t;
    }
}

void solve() {
    rii(N, M);
    FOR(i, 0, N) T[i] = -1;
    FOR(i, 0, N) ri(A[i]);
    FOR(i, 0, N) cin >> C[i];
    vector<tuple<int, char, int>> odd, even;
    FOR(i, 0, N) {
        if (A[i] & 1) odd.pb({A[i], C[i], i});
        else even.pb({A[i], C[i], i});
    }
    sort(ALL(odd)); sort(ALL(even));
    f(odd), f(even);
    FOR(i, 0, N) printf("%d ", T[i]);
    printf("\n");
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}