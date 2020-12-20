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

using namespace std;

typedef long long ll;
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
const int MAXN = 510; // CAMBIAR ESTE

// GJNM
bool DP1[2][MAXN][MAXN]; // ->

int main() {
    int n, k; rii(n, k);
    DP1[0][0][0] = true;
    set<int> ans;
    for (int i = 1; i <= n; i++) {
        int x; ri(x);
        int curr = i & 1;
        int prev = curr ^ 1;
        for (int set1 = 0; set1 <= k; set1++) {
            for (int set2 = 0; set2 <= k - set1; set2++) {
                DP1[curr][set1][set2] = DP1[prev][set1][set2];
                if (set1 >= x)
                    DP1[curr][set1][set2] |= DP1[prev][set1 - x][set2];
                if (set2 >= x)
                    DP1[curr][set1][set2] |= DP1[prev][set1][set2 - x];

                if (set1 + set2 == k && DP1[curr][set1][set2])
                    ans.insert(set1), ans.insert(set2);
            }
        }
    }
    printf("%d\n", SZ(ans));
    for (auto x : ans)
        printf("%d ", x);
    printf("\n");

    return 0;
}