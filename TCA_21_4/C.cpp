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
const int MAXN = 1e5 + 10; // CAMBIAR ESTE
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
int B[MAXN];
int A[2][MAXN];

int qry(int x, int l, int r) {
    int ret = A[x][r];
    if (l > 0) ret -= A[x][l - 1];
    return ret;
}

int main() {
    ri(N);
    FOR(i, 0, N) {
        int a; ri(a);
        A[a - 1][i]++;
        if (i > 0) {
            A[0][i] += A[0][i - 1];
            A[1][i] += A[1][i - 1];
        }
        B[i] = a - 1;
    }

    vii ans;
    for (int t = 1; t <= N; ++t) {
        int i = 0;
        int won[2] = {0, 0};
        bool good = true;
        int lst;
        while (i < N && good) {
            if (max(qry(0, i, N - 1), qry(1, i, N - 1)) < t) {
                good = false;
                break;
            }

            int lo = i, hi = N - 1;
            while (lo < hi) {
                int mi = lo + (hi - lo) / 2;
                if (max(qry(0, i, mi), qry(1, i, mi)) >= t)
                    hi = mi;
                else
                    lo = mi + 1;
            }

            won[B[lo]]++;
            lst = B[lo];
            i = lo + 1;
        }
        if (good && lst == B[N - 1] && won[lst] > won[lst ^ 1]) {
            ans.pb({won[lst], t});
        }
    }
    sort(ALL(ans));
    printf("%d\n", SZ(ans));
    FOR(i, 0, SZ(ans)) printf("%d %d\n", ans[i].F, ans[i].S);
    return 0;
}