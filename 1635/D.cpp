#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int qwert;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) qwert = scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) qwert = scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int N, P;
int A[MAXN];
int DP[MAXN];

int main() {
    rii(N, P);
    FOR(i, 0, N) ri(A[i]);
    sort(A, A + N);
    vi G;
    FOR(i, 0, N) {
        int x = A[i];
        while (x > 0) {
            auto it = lower_bound(all(G), x);
            if (it != G.end() && *it == x) break;
            if (x & 1) x >>= 1;
            else if (x & 3) x = 0;
            else x >>= 2;
        }
        if (x == 0) {
            G.pb(A[i]);
            int p2 = 0;
            while ((1ll << (p2 + 1)) <= A[i]) ++p2;
            DP[p2]++;
        }
    }
    int ans = 0;
    FOR(i, 0, P) {
        if (i > 0) DP[i] = (DP[i] + DP[i - 1]) % MOD;
        if (i > 1) DP[i] = (DP[i] + DP[i - 2]) % MOD;
        ans += DP[i];
        ans %= MOD;
    }
    printf("%d\n", ans);


    return 0;
}
