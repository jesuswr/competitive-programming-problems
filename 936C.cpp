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
int N;
string S, T;
vi ops;

bool good() {
    vi cnt(30);
    FOR(i, 0, N) {
        cnt[S[i] - 'a']++;
        cnt[T[i] - 'a']--;
    }
    FOR(i, 0, 30) if (cnt[i] != 0)
        return false;
    return true;
}

void op(int x) {
    ops.pb(x);
    string aux;
    for (int i = N - 1; i >= N - x; --i)
        aux.pb(S[i]);
    for (int i = 0; i < N - x; ++i)
        aux.pb(S[i]);
    S = aux;
}

int main() {
    ri(N);
    cin >> S;
    cin >> T;

    if (!good()) {
        printf("-1\n");
        return 0;
    }

    int x = 0;
    bool ord = 1;
    while (x + 2 <= N) {
        char prv = T[(N - 1) / 2 - x / 2], nxt = T[(N - 1) / 2 + x / 2 + 1];
        if (!ord)
            swap(prv, nxt);
        int prv_i = 0;
        while (S[prv_i] != prv) prv_i++;
        op(N - 1 - prv_i);
        op(N);
        op(x);
        int nxt_i = N - 1;
        while (S[nxt_i] != nxt) --nxt_i;
        op(N - nxt_i);
        op(nxt_i - x - 1);
        x += 2;
        ord = !ord;
    }
    if (!ord)
        op(N);
    if (S != T) {
        bool op1 = 1;
        for (int i = 0; i < N - 1; ++i) op1 &= T[i] == S[i + 1];
        if (op1) {
            op(N - 1);
            op(1);
            op(N);
        }
        else {
            op(1);
            op(N - 1);
            op(N);
        }
    }
    printf("%d\n", SZ(ops));
    for (auto x : ops) printf("%d ", x);
    printf("\n");
    return 0;
}