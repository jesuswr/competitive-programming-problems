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
const int MAXN = 1e6 + 10; // CAMBIAR ESTE
const int MOD = 1e9 + 7;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, M, P_LEN;
int X[MAXN];
char S[MAXN], P[MAXN];
bool MATCH[MAXN];

bool kmp() {
    vi pi(P_LEN + 1);
    P[P_LEN] = '$';
    FOR(i, 1, P_LEN + 1) {
        int j = pi[i - 1];
        while (j > 0 && P[j] != P[i]) j = pi[j - 1];
        if (P[i] == P[j]) pi[i] = j + 1;
    }

    int lst = 0;
    FOR(i, 0, N) {
        int j = lst;
        int curr = 0;
        while (j > 0 && S[i] != P[j]) j = pi[j - 1];
        if (S[i] == P[j]) curr = j + 1;

        if (MATCH[i] && curr != P_LEN)
            return false;
        lst = curr;
    }
    return true;
}

int main() {
    rii(N, M);
    dadsadasda = scanf("%s", P);
    P_LEN = strlen(P);
    FOR(i, 0, M) {
        ri(X[i]); --X[i];
        MATCH[X[i] + P_LEN - 1] = true;
    }

    for (int i = 0, j = 0; i < N; ++i) {
        while (j < M && (i - X[j]) >= P_LEN) ++j;
        if (j < M && i - X[j] < P_LEN && i >= X[j])
            S[i] = P[i - X[j]];
        else
            S[i] = '?';
    }

    if (!kmp()) {
        printf("0\n");
        return 0;
    }
    int ans = 1;
    FOR(i, 0, N) {
        if (S[i] == '?') ans = (1ll * ans * 26) % MOD;
    }
    printf("%d\n", ans);

    return 0;
}