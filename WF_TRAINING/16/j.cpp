    #include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define FOR(i,n,m) for (int i = n; i < (int)m; i++)
#define ROF(i,n,m) for (int i = n; i > (int)m; i--)
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define ri(a) scanf("%d", &a)
#define rii(a, b) ri(a), ri(b)
#define lri(a) scanf("%lld", &a)
#define lrii(a, b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 1e4+5;

void fastIO() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
}

int n, w, h, m;

ll cnt[MAXN];
bitset<MAXN> s[MAXN];
ll sufX[MAXN], sufY[MAXN];
int L[MAXN], R[MAXN];

bool check(int level) {
    if (level == h) return true;
    if (cnt[level] == 0) return false;
    if (level == 0) return true;
    
        ll xfloor = sufX[level] / cnt[level];
        ll xceil = (sufX[level] + cnt[level] - 1) / cnt[level];

        ll xl = 2*L[level-1];
        ll xr = 2*R[level-1]+2;

        // printf("%d %lld %lld %lld %lld\n", level, xfloor, xceil, xl, xr);

        if (xfloor < xl || xceil > xr) return false;
        if (xfloor == xceil && (xfloor == xl || xfloor == xr)) return false;
    }


    ll yfloor = sufY[level] / cnt[level];
    ll yceil = (sufY[level] + cnt[level] - 1) / cnt[level];

    ll yl = 2*L[level-1];
    ll yr = 2*R[level-1]+2;

    // printf("%d %lld %lld %lld %lld\n", level, yfloor, yceil, yl, yr);
    if (yfloor < yl || yceil > yr) return false;
    if (yfloor == yceil && (yfloor == yl || yfloor == yr)) return false;
    return true;
}

void remove(int level, int k) {
    s[level][k] = 1;
    while (L[level] < n && s[level][L[level]]) L[level]++;
    while (R[level] >= 0 && s[level][R[level]]) R[level]--;

    ROF(i,level,-1) {
        if (i&1) { sufY[i] -= 2*k+1; sufX[i] -= n; }
        else { sufX[i] -= 2*k+1; sufY[i] -= n; }
        cnt[i]--;
    }

    // printf("%lld %lld %d\n", sufX[level], sufY[level], cnt[level]);
}

vii queries;

int main() {
    freopen("jenga.in", "r", stdin); // redirects standard input
    freopen("jenga.out", "w", stdout); // redirects standard output

    rii(n, w);
    rii(h, m);

    ROF(i,h-1,-1) {
        sufX[i] = sufX[i+1];
        sufY[i] = sufY[i+1];
        cnt[i] = cnt[i+1] + n;

        FOR(j,0,n) {
            if (i&1) { sufY[i] += 2*j+1; sufX[i] += n; }
            else { sufX[i] += 2*j+1; sufY[i] += n; }
        }

        L[i] = 0; R[i] = n-1;
    }

    FOR(i,0,m) {
        int level, k;
        rii(level, k); level--, k--;
        queries.pb({level, k});
    }

    int cnt = 1;
    for (auto &[level, k] : queries) {
        remove(level, k);
        ROF(i,level+1,0) {
            if (!check(i)) {
                printf("yes\n%d\n", cnt);
                return 0;
            }
        }

        cnt++;
    }

    printf("no\n");



    return 0;
}
