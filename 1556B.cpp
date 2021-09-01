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
int N, A[MAXN];
void solve() {
    ri(N);
    FOR(i, 0, N) ri(A[i]);
    FOR(i, 0, N) A[i] &= 1;
    int CNT[2] = {0, 0};
    FOR(i, 0, N) CNT[A[i]]++;
    if (abs(CNT[0] - CNT[1]) > 1) {
        printf("-1\n");
        return;
    }
    ll ans = LLINF;
    {
        int fst[2] = {0, 0};
        ll cnt = 0;
        int B[MAXN];
        FOR(i, 0, N) B[i] = A[i];
        for (int i = 0; i < N; ++i) {
            while (fst[0] < N && B[fst[0]] != 0) fst[0]++;
            while (fst[1] < N && B[fst[1]] != 1) fst[1]++;

            if (i & 1) {
                if (fst[1] == N) {
                    cnt = LLINF;
                    break;
                }
                cnt += abs(i - fst[1]);
                swap(B[i], B[fst[1]]);
            }
            else {
                if (fst[0] == N) {
                    cnt = LLINF;
                    break;
                }
                cnt += abs(i - fst[0]);
                swap(B[i], B[fst[0]]);
            }
            B[i] = -1;
        }
        ans = min(ans, cnt);
    }

    {
        int fst[2] = {0, 0};
        ll cnt = 0;
        int B[MAXN];
        FOR(i, 0, N) B[i] = A[i];
        for (int i = 0; i < N; ++i) {
            while (fst[0] < N && B[fst[0]] != 0) fst[0]++;
            while (fst[1] < N && B[fst[1]] != 1) fst[1]++;

            if (i & 1) {
                if (fst[0] == N) {
                    cnt = LLINF;
                    break;
                }
                cnt += abs(i - fst[0]);
                swap(B[i], B[fst[0]]);
            }
            else {
                if (fst[1] == N) {
                    cnt = LLINF;
                    break;
                }
                cnt += abs(i - fst[1]);
                swap(B[i], B[fst[1]]);
            }
            B[i] = -1;
        }
        ans = min(ans, cnt);
    }
    if (ans == LLINF)
        printf("-1\n");
    else
        printf("%lld\n", ans);
}

int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}