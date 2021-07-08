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

// GJNM

int main() {
    map<string, long double> mp;
    string pink = "pink", blue = "blue";

    mp[pink] = 0;

    int n; ri(n);
    FOR(_, 0, n) {
        string o, w; ld r;
        cin >> o >> w >> r;
        if (mp.find(w) == mp.end())
            continue;

        if (mp.find(o) == mp.end())
            mp[o] = mp[w] + log(r);
        else
            mp[o] = max(mp[o], mp[w] + log(r));
    }

    if (mp.find(blue) == mp.end())
        printf("0.000000000\n");
    else if (mp[blue] >= 10.0)
        printf("10.000000000\n");
    else
        printf("%.9Lf\n", min( exp(mp[blue]), (ld)10)  );

    return 0;
}