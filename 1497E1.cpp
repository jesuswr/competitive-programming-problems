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
const int MAXN = 2e5 + 100; // CAMBIAR ESTE
const int MAXA = 1e7 + 10;

// GJNM
int SIEVE[MAXA];
void pre() {
    FOR(i, 2, MAXA) {
        if (SIEVE[i] != 0) continue;
        int j = i;
        while (j < MAXA) {
            SIEVE[j] = i;
            j += i;
        }
    }
}

int N, K;
int A[MAXA];

int main() {
    pre();
    int t; ri(t);
    while (t--) {
        rii(N, K);
        FOR(i, 0, N) ri(A[i]);
        FOR(i, 0, N) {
            int aux_a = 1;
            while (A[i] > 1) {
                int cnt = 0;
                int aux_d = SIEVE[A[i]];
                while (A[i] % aux_d == 0) {
                    ++cnt;
                    A[i] /= aux_d;
                }
                if (cnt & 1) aux_a *= aux_d;
            }
            A[i] = aux_a;
        }

        int ans = 1;
        set<int> active;
        FOR(i, 0, N) {
            if (active.find(A[i]) == active.end()) {
                active.insert(A[i]);
            }
            else {
                ++ans;
                active.clear();
                active.insert(A[i]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}