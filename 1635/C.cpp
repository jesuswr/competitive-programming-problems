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

int N;
ll A[MAXN];
void solve() {
    ri(N);
    FOR(i, 0, N) lri(A[i]);
    bool good = 1;
    FOR(i, 1, N) good &= A[i - 1] <= A[i];
    if (good) {
        printf("0\n");
        return;
    }
    if (A[N - 1] < A[N - 2]) {
        printf("-1\n");
        return;
    }
    vector<tuple<int, int, int>> ans;
    for (int i = N - 3; i >= 0; i--) {
        if (A[i] <= A[i + 1]) continue;
        A[i] = A[i + 1] - A[N - 1];
        ans.pb({i + 1, i + 2, N});
        if (A[i] > A[i + 1]) {
            printf("-1\n");
            return;
        }
    }
    printf("%d\n", sz(ans));
    for (auto [x, y, z] : ans) printf("%d %d %d\n", x, y, z);
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}
