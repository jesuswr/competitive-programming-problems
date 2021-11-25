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
const int MAXN = 1e6 + 1; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM

int SV[MAXN];
void pre() {
    FOR(i, 2, MAXN) if (SV[i] == 0) {
        int j = i;
        while (j < MAXN) {
            SV[j] = i;
            j += i;
        }
    }
}

int count(int x) {
    int ret = 1;
    while (x > 1) {
        int aux = 0;
        int d = SV[x];
        while (x % d == 0) {
            aux++;
            x /= d;
        }
        ret *= (aux + 1);
    }
    return ret;
}

void solve() {
    int n; ri(n);
    int bst = 1, cnt = 1;
    FOR(i, 2, n + 1) {
        int aux = count(i);
        if (aux > cnt) {
            bst = i;
            cnt = aux;
        }
    }
    printf("%d\n", bst);
}



int main() {
    pre();
    int t; ri(t);
    while (t--) {
        solve();
    }
    return 0;
}