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
const int MOD = 998244353;

// GJNM
int N;
int DP[MAXN];
int MN_D[MAXN];

void pre() {
    FOR(i, 2, MAXN) {
        if (MN_D[i] != 0) continue;
        int j = i;
        while (j <= N) {
            if (MN_D[j] == 0) MN_D[j] = i;
            else MN_D[j] = min(MN_D[j], i);
            j += i;
        }
    }
}


int main() {
    ri(N);
    pre();
    int prev = 0;
    for (int i = 1; i <= N; ++i) {
        int aux = i;
        int sum = 1;
        while (aux > 1) {
            int d = MN_D[aux];
            int mult = 0;
            while (aux % d == 0) {
                mult++;
                aux = aux / d;
            }
            sum *= (mult + 1);
        }

        DP[i] += sum;
        if (DP[i] >= MOD) DP[i] -= MOD;

        DP[i] += prev;
        if (DP[i] >= MOD) DP[i] -= MOD;
        prev += DP[i];
        if (prev >= MOD) prev -= MOD;
    }
    printf("%d\n", DP[N]);
    return 0;
}