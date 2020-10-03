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
const int MAXN = 1010; // CAMBIAR ESTE

// GJNM
int a[MAXN];
int n;

bool bad() {
    FOR(i, 0, n) {
        if (a[i] != i)
            return true;
    }
    return false;
}

void solve() {
    ri(n);
    FOR(i, 0, n) {
        ri(a[i]);
    }

    vi moves;

    while (bad()) {
        vi cnt(n + 1, 0);
        FOR(i, 0, n) {
            cnt[a[i]]++;
        }
        int mex;
        FOR(i,0,n+1){
            if (cnt[i] == 0){
                mex = i;
                break;
            }
        }

        if (mex == n) {
            FOR(i, 0, n) {
                if (a[i] != i) {
                    a[i] = mex;
                    moves.pb(i);
                    break;
                }
            }
        }
        else {
            a[mex] = mex;
            moves.pb(mex);
        }
    }


    printf("%zu\n", moves.size());
    for (auto x : moves)
        printf("%d ", x + 1);
    printf("\n");

}



int main() {
    int t;
    ri(t);
    while (t--)
        solve();

    return 0;
}