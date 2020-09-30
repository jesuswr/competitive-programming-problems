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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
int c[10];
vi ans;

int main() {
    int v;
    ri(v);
    int mn = 1;
    FOR(i, 1, 10) {
        ri(c[i]);
        if (c[i] <= c[mn]) {
            mn = i;
        }
    }

    if (v < c[mn]){
        printf("-1\n");
        return 0;
    }

    while (v >= c[mn]) {
        ans.pb(mn);
        v -= c[mn];
    }

    FOR(i, 0, ans.size()) {
        ROF(num, 9, -1) {
            if (num > ans[i]) {
                if (v + c[ans[i]] >= c[num]) {
                    v += c[ans[i]];
                    v -= c[num];
                    ans[i] = num;
                }
            }
        }
    }
    for(auto x : ans){
        printf("%d", x);
    }
    printf("\n");


    return 0;
}