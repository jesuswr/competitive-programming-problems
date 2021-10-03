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
int N, M;
int X[MAXN], Y[MAXN];
int D[MAXN];
const int SQ = 300;

int PREF[MAXN];

int CNT[SQ][SQ];
void add(int k) {
    if (X[k] + Y[k] >= SQ) {
        for (int d = D[k]; d < M; d += X[k] + Y[k]) {
            PREF[min(M + 69, d + X[k])] += 1;
            PREF[min(M + 69, d + X[k] + Y[k])] -= 1;
        }
    }
    else {
        int a = X[k] + Y[k];
        int d = (D[k] + X[k]) % a;
        do {
            ++CNT[a][d];
            d = (d + 1) % a;
        } while (d != (D[k] % a));
    }
}
void del(int k, int aux) {
    if (X[k] + Y[k] >= SQ) {
        for (int d = D[k]; d < M; d += X[k] + Y[k]) {
            PREF[min(M + 69, d + X[k])] -= 1;
            PREF[min(M + 69, d + X[k] + Y[k])] += 1;
        }
        for (int d = D[k]; d < M; d += X[k] + Y[k]) {
            if (d + X[k] < aux && d + X[k] + Y[k] >= aux)
                PREF[aux]--;
        }
    }
    else {
        int a = X[k] + Y[k];
        int d = (D[k] + X[k]) % a;
        do {
            --CNT[a][d];
            d = (d + 1) % a;
        } while (d != (D[k] % a));
    }
}
int q(int d) {
    int ans = PREF[d];
    FOR(i, 1, SQ) ans += CNT[i][d % i];
    return ans;
}

int main() {
    rii(N, M);
    FOR(i, 0, N) rii(X[i], Y[i]);
    FOR(d, 0, M) {
        if (d > 0)
            PREF[d] += PREF[d - 1];
        int op, k; rii(op, k); --k;
        if (op == 1) {
            D[k] = d;
            add(k);
        }
        else
            del(k, d);
        printf("%d\n", q(d));
    }

    return 0;
}