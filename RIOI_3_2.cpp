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
const int MOD = 1e9 + 7;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, M;
int DP[2][21][100010];
int f(int fst, int p, int sm) {
    if (sm < 0)
        return 0;
    if (p == 0)
        return DP[fst][p][sm] = 1;
    if (DP[fst][p][sm] != -1)
        return DP[fst][p][sm];

    DP[fst][p][sm] = f(0, p, sm - p) + (fst == 0 ? f(1, p - 1, sm) : 0);
    if (DP[fst][p][sm] >= MOD)
        DP[fst][p][sm] -= MOD;
    return DP[fst][p][sm];
}

int main() {
    memset(DP, -1, sizeof(DP));
    int t; ri(t);
    while (t--) {
        rii(N, M);
        printf("%d\n", f(1, N, M));
    }

    return 0;
}