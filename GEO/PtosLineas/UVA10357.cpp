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

typedef long long T;
typedef complex<T> pt;
#define x real() // DO NOT USE x & y AS VARIABLE NAMES!!!
#define y imag()
#define mkt make_tuple
const double PI = 2 * acos(0.0);


int sgn(T a) {return (a < 0) - (a > 0);}
T sq(pt p) {return p.x * p.x + p.y * p.y;}
double abs(pt p) {return sqrt(sq(p));}

ll X[MAXN], Y[MAXN], V[MAXN];

int main() {
    int n, m;
    qwert = scanf("PLAYERS=%d\n", &n);
    FOR(i, 0, n) qwert = scanf("%lld %lld %lld\n", X + i, Y + i, V + i);
    qwert = scanf("BALLS=%d\n", &m);
    FOR(_, 0, m) {
        ll a, b, c, d, e, f, g;
        qwert = scanf("%lld %lld %lld %lld %lld %lld %lld\n", &a, &b, &c, &d, &e, &f, &g);
        ll t = max( (-b - sqrt(b * b - 4 * a * c)) / (2 * a)  , (-b + sqrt(b * b - 4 * a * c)) / (2 * a) );
        if (a * t * t + b * t + c > 0) ++t;
        pt p = {d * t + e, f * t + g};
        if (p.x < 0 || p.y < 0) {
            printf("Ball %d was foul at (%lld,%lld)\n", _ + 1, p.x, p.y);
            continue;
        }
        bool good = 0;
        FOR(j, 0, n) {
            pt q = {X[j], Y[j]};
            good |= (abs(p - q) / V[j]) <= t;
        }
        if (good)
            printf("Ball %d was caught at (%lld,%lld)\n", _ + 1, p.x, p.y);
        else
            printf("Ball %d was safe at (%lld,%lld)\n", _ + 1, p.x, p.y);
    }


    return 0;
}
