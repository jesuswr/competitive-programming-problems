#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dadsadasda;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) dadsadasda = scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) dadsadasda = scanf("%lld", &a)
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


int main() {
    int t; ri(t);
    while (t--) {
        int n; ri(n);
        vi a(n + 1), b(n);
        FOR(i, 0, n) ri(a[i]);
        FOR(i, 0, n) b[i] = a[i];
        FOR(i, 1, n - 1) {
            if (a[i] > max(a[i - 1], a[i + 1]))
                a[i + 1] = max(a[i], a[i + 2]);
        }
        int cnt = 0;
        FOR(i, 0, n) cnt += a[i] != b[i];
        printf("%d\n", cnt);
        FOR(i, 0, n) printf("%d ", a[i]);
        printf("\n");
    }
    return 0;
}
