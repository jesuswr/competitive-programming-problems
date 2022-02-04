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
const int MAXN = 1e5; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int T[4];
vi ans;
vector<ld> ans2;
ld mx = -1;

vector<ld> help(ld a, ld b, ld c, ld d) {
    vector<ld> aux = {a, b, c, d};
    return aux;
}

void go(vi i) {
    ll lft = T[i[0]] * T[i[3]] + T[i[1]] + T[i[2]], rgt = T[i[0]] + T[i[3]] + T[i[1]] * T[i[2]];
    ll diff = lft - rgt;
    if (diff == 0) {
        mx = max(mx, (ld)lft);
        if (mx == (ld)lft) {
            ans = i;
            ans2 = help(T[i[0]], T[i[1]], T[i[2]], T[i[3]]);
        }
    }
    if (diff > 0) { // probar 1 y 4
        if (T[i[3]] - 1 > 0) {
            ld x = ((ld)diff) / (T[i[3]] - 1 );
            if (diff <= T[i[0]] * (T[i[3]] - 1 )) {
                if (mx <= rgt - x) {
                    ans = i;
                    ans2 = help(T[i[0]] - x, T[i[1]], T[i[2]], T[i[3]]);
                }
                mx = max(mx, rgt - x);
            }
        }
        if (T[i[0]] - 1 > 0) {
            ld x = ((ld)diff) / (T[i[0]] - 1 );
            if (diff <= T[i[3]] * (T[i[0]] - 1 )) {
                if (mx <= rgt - x) {
                    ans = i;
                    ans2 = help(T[i[0]], T[i[1]], T[i[2]], T[i[3]] - x);
                }
                mx = max(mx, rgt - x);
            }
        }
    }
    else { // probar 2 y 3
        diff = -diff;
        if (T[i[2]] - 1 > 0) {
            ld x = ((ld)diff) / (T[i[2]] - 1 );
            if (diff <= T[i[1]] * (T[i[2]] - 1 )) {
                if (mx <= lft - x) {
                    ans = i;
                    ans2 = help(T[i[0]], T[i[1]] - x, T[i[2]], T[i[3]]);
                }
                mx = max(mx, lft - x);
            }
        }
        if (T[i[1]] - 1 > 0) {
            ld x = ((ld)diff) / (T[i[1]] - 1 );
            if (diff <= T[i[2]] * (T[i[1]] - 1 )) {
                if (mx <= lft - x) {
                    ans = i;
                    ans2 = help(T[i[0]], T[i[1]], T[i[2]] - x, T[i[3]]);
                }
                mx = max(mx, lft - x);
            }
        }
    }
}


int main() {
    FOR(i, 0, 4) ri(T[i]);

    vi inds = {0, 1, 2, 3};
    do {
        go(inds);
    } while (next_permutation(ALL(inds)));

    FOR(i, 0, 4) printf("%d ", ans[i] + 1);
    printf("\n");
    FOR(i, 0, 4) printf("%.8Lf ", ans2[i]);
    printf("\n");
    return 0;
}