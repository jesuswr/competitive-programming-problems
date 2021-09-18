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
#include <random>
#include <chrono>

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
const int MAXN = 2010; // CAMBIAR ESTE
const int MOD = 1e9 + 7;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int m, d;
string s;

int P10[MAXN];
int DP[MAXN][MAXN][2];
int f(int p, int rem, int h) {
    int &ret = DP[p][rem][h];
    if (ret != -1) {
        // printf("\t%d %d %d : %d\n", p, rem, h, ret);
        return ret;
    }
    if (p == SZ(s)) {
        // printf("\t%d %d %d : %d\n", p, rem, h, (rem == 0) && (h == 0));
        return ret = (rem == 0) && (h == 0);
    }
    int dig = s[p] - '0';
    ret = 0;
    if ((SZ(s) - p) & 1) {
        FOR(a, p + 1 == SZ(s), 10) {
            if (a == d)
                continue;
            if (a < dig)
                ret += f(p + 1, (P10[p] * a + rem) % m, 0);
            else if (a == dig)
                ret += f(p + 1, (P10[p] * a + rem) % m, h);
            else
                ret += f(p + 1, (P10[p] * a + rem) % m, 1);
            ret %= MOD;
        }
    }
    else {
        if (d < dig)
            ret = f(p + 1, (P10[p] * d + rem) % m, 0);
        else if (d == dig)
            ret = f(p + 1, (P10[p] * d + rem) % m, h);
        else
            ret = f(p + 1, (P10[p] * d + rem) % m, 1);
    }
    // printf("%d %d %d : %d\n", p, rem, h, ret);
    return ret;
}

int g() {
    bool good = 1;
    for (int i = SZ(s) - 2; i >= 0; i -= 2) good &= (d == (s[i] - '0'));
    for (int i = SZ(s) - 1 ; i >= 0; i -= 2) good &= (d != (s[i] - '0'));
    int rem = 0;
    FOR(i, 0, SZ(s))
    rem = (rem + (s[i] - '0') * P10[i]) % m;
    return (rem == 0 && good);
}

int main() {
    rii(m, d);
    P10[0] = 1;
    FOR(i, 1, MAXN) P10[i] = (P10[i - 1] * 10) % m;
    cin >> s; reverse(ALL(s));
    memset(DP, -1, sizeof(DP));
    int fa = f(0, 0, 0);
    int ga = g();
    // cout << "////////////////" << endl;
    cin >> s; reverse(ALL(s));
    memset(DP, -1, sizeof(DP));
    int fb = f(0, 0, 0);
    printf("%d\n", (fb + ga - fa + MOD) % MOD);
    return 0;
}