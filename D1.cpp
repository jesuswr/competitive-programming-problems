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
bool can(vi &a) {
    int n = SZ(a);
    a.pb(0);
    // FOR(i, 0, n) printf("%d ", a[i]);
    // printf("\n");
    FOR(i, 0, n) {
        if (a[i] & 1) {
            if (a[i + 1] & 1)
                ++i;
            else if (i + 2 < n && (a[i + 1] & 1) == 0 && (a[i + 2] & 1) == 0) {
                --a[i + 1];
                --a[i + 2];
                ++i;
            }
            else
                return false;
        }
    }
    return true;
}

int main() {
    int n; ri(n);
    vi a(n);
    FOR(i, 0, n) ri(a[i]);
    FOR(i, 0, n) a[i] &= 1;
    vi st;
    FOR(i, 0, n) {
        st.pb(a[i]);
        int m = SZ(st);
        if (m > 1 && st[m - 1] == st[m - 2]) {
            st.pop_back();
            st.pop_back();
        }
    }
    if (SZ(st) <= 1)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}