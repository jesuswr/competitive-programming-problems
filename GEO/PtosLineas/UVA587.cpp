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
vector<pair<int, string>> proc_inp(string s) {
    vector<pair<int, string>> ret;
    s = ',' + s;
    int i = 0;
    while (s[i] == ',') {
        ++i;
        int aux = 0;
        string t;
        while ('0' <=  s[i] && s[i] <= '9') {
            aux = 10 * aux + (s[i] - '0');
            ++i;
        }
        while ('A' <=  s[i] && s[i] <= 'Z') {
            t.pb(s[i]);
            ++i;
        }
        ret.pb({aux, t});
    }
    return ret;
}

typedef double T;
typedef complex<T> pt;
#define x real() // DO NOT USE x & y AS VARIABLE NAMES!!!
#define y imag()
#define mkt make_tuple
const double PI = 2 * acos(0.0);

int sgn(T a) {return (a < 0) - (a > 0);}
T sq(pt p) {return p.x * p.x + p.y * p.y;}
double abs(pt p) {return sqrt(sq(p));}

// Transformations
pt translate(pt v, pt p) {return p + v;} //Move p through v
map<string, pt> MP;


int main() {
    MP["N"] = {1, 0};
    MP["E"] = {0, 1};
    MP["S"] = { -1, 0};
    MP["W"] = {0, -1};
    MP["NE"] = {sqrt(2) / 2, sqrt(2) / 2};
    MP["SE"] = { -sqrt(2) / 2, sqrt(2) / 2};
    MP["NW"] = {sqrt(2) / 2, -sqrt(2) / 2};
    MP["SW"] = { -sqrt(2) / 2, -sqrt(2) / 2};

    int _t = 0;
    string s;
    while (getline(cin, s), s[0] != 'E') {
        pt p = {0, 0};
        for (auto [len, dir] : proc_inp(s))
            p = translate(1.0 * len * MP[dir], p);
        printf("Map #%d\n", ++_t);
        printf("The treasure is located at (%.3lF,%.3lF).\n", p.y, p.x);
        printf("The distance to the treasure is %.3lF.\n\n", abs(p));
    }
    return 0;
}








