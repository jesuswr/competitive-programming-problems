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
int N;
vector<vi> ans;

vector<vi> ins(int x) {
    vector<vi> ret;
    bool left = false;
    for (auto &v : ans) {
        int n = SZ(v);
        if (left) {
            for (int j = 0; j <= n; j++) {
                vi aux;
                for (int i = 0; i < j; i++) aux.pb(v[i]);
                aux.pb(x);
                for (int i = j; i < n; i++) aux.pb(v[i]);
                ret.pb(aux);
            }
        }
        else {
            for (int j = n; j >= 0; j--) {
                vi aux;
                for (int i = 0; i < j; i++) aux.pb(v[i]);
                aux.pb(x);
                for (int i = j; i < n; i++) aux.pb(v[i]);
                ret.pb(aux);
            }
        }
        left = !left;
    }
    return ret;
}


int main() {
    ri(N);
    ans.pb({1});
    FOR(i, 2, N + 1) {
        ans = ins(i);
    }

    for (auto v : ans) {
        for (auto x : v) printf("%d ", x);
        printf("\n");
    }

    return 0;
}