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
const int MAXN = 2e6; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, K;
ld P;

int count(int msk) {
    int ret = 0;
    FOR(b, 0, N) if ((msk >> b) & 1)
        ret++;
    return ret;
}

long double DP[2][1 << 10];

int main() {
    dadsadasda = scanf("%d %d %Lf", &N, &K, &P);
    // printf("%d %d %Lf\n", N, K, P);
    for (int t = MAXN - 2; t >= 0; --t) {
        int curr = t & 1;
        int prev = curr ^ 1;
        for (int lst = 0; lst < (1 << N); ++lst) {
            DP[curr][lst] = 0;
            if (count(lst) >= K)
                DP[curr][lst] = t ;
            else
                DP[curr][lst] = P * DP[prev][(1 << (N - 1)) | (lst >> 1)] + (1 - P) * DP[prev][lst >> 1];
            // printf("%d %d %Lf\n", t, lst, DP[curr][lst]);
        }
    }

    printf("%.15Lf\n", DP[0][0]);
    return 0;
}