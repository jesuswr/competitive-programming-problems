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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e6 + 10; // CAMBIAR ESTE

// GJNM
int n, m;
int b[(int)1e3 + 10];
int dp[(int)1e3 + 10][(int)1e3 + 10];

int f(int pos, int sm) {
    if (sm == 0)
        return 1;
    if (pos >= m)
        return 0;
    if (dp[pos][sm] != -1)
        return dp[pos][sm];
    dp[pos][sm] = 0;
    int aux_sm = sm;
    FOR(i, 0, b[pos] + 1) {
        if (f(pos + 1, aux_sm  ))
            return dp[pos][sm] = 1;
        aux_sm += pos;
        if (aux_sm >= m)
            aux_sm -= m;
    }
    return 0;
}

int main() {
    rii(n, m);
    FOR(i, 0, n) {
        int a;
        ri(a);
        b[a % m]++;
    }
    FOR(i, 0, m + 1) {
        FOR(j, 0, m + 1) {
            dp[i][j] = -1;
        }
    }
    FOR(i, 0, m) {
        if (b[i] == 0)
            continue;
        int aux_sm = i;
        FOR(j, 1, b[i] + 1) {
            if (f(i + 1, aux_sm)) {
                printf("YES\n");
                return 0;
            }
            aux_sm += i;
            if (aux_sm >= m)
                aux_sm -= m;
        }
    }
    printf("NO\n");

    return 0;
}