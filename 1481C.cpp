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
const int MAXN = 2e5; // CAMBIAR ESTE

// GJNM
int N, M;
int A[MAXN], B[MAXN], C[MAXN], ANS[MAXN];

void solve() {
    rii(N, M);
    FOR(i, 0, N) ri(A[i]);
    FOR(i, 0, N) ri(B[i]);
    FOR(i, 0, M) ri(C[i]);

    vector<stack<int>> have(N + 1), need(N + 1);
    FOR(i, 0, N) have[B[i]].push(i);
    FOR(i, 0, N) if (A[i] != B[i]) need[B[i]].push(i);

    bool alo = false;
    FOR(i, 0, N) if (B[i] == C[M - 1]) alo = true;
    if (!alo) {
        printf("NO\n");
        return;
    }
    int ind = -1;
    for (int i = M - 1; i >= 0; i--) {
        int col = C[i];
        int j;
        if (i == M - 1) {
            if (SZ(need[col]) > 0) {
                ind = need[col].top();
                need[col].pop();
                j = ind;
            }
            else if (SZ(have[col]) > 0) {
                ind = have[col].top();
                j = ind;
            }
        }
        else {
            if (SZ(need[col]) > 0) {
                j = need[col].top();
                need[col].pop();
            }
            else {
                j = ind;
            }
        }
        ANS[i] = j;
    }

    FOR(i, 1, N + 1) if (SZ(need[i]) > 0) {
        printf("NO\n");
        return;
    }
    printf("YES\n");
    FOR(i, 0, M) printf("%d ", ANS[i] + 1);
    printf("\n");
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}