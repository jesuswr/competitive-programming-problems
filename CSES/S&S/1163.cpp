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
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM

int main() {
    int l, n; rii(l, n);
    set< pii > segs;
    multiset<int> szs;
    segs.insert({0, l});
    szs.insert(l);
    while (n--) {
        int p; ri(p);
        auto it = segs.ub(make_pair(p, p));
        --it;

        szs.erase(szs.find(it->S - it->F));
        if (it->F != p) {
            segs.insert(make_pair(it->F, p));
            szs.insert(p - it->F);
        }
        if (it->S != p) {
            segs.insert(make_pair(p, it->S));
            szs.insert(it->S - p);
        }
        segs.erase(it);
        printf("%d\n", *szs.rbegin());
    }
    return 0;
}