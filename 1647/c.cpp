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

char M[110][110];
void solve() {
    int n, m; rii(n, m);
    FOR(i, 0, n) qwert = scanf("%s\n", M[i]);
    if (M[0][0] == '1') {
        printf("-1\n");
        return;
    }
    printf("%d\n", n * m);
    for (int i = n - 1; i >= 0; --i) for (int j = m - 1; j >= 0; --j) {
            if (M[i][j] == '0')
                printf("%d %d %d %d\n", i + 1, j + 1, i + 1, j + 1);
            else {
                if (i > 0) printf("%d %d %d %d\n", i, j + 1, i + 1, j + 1);
                else if (j > 0) printf("%d %d %d %d\n", i + 1, j, i + 1, j + 1);
            }
        }
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}
