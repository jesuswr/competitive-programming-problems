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
int n, k;
char mat[400][400];

void solve() {
    rii(n, k);
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            mat[i][j] = '0';
        }
    }

    printf("%d\n", (k % n ? 2 : 0));
    int col = 0;
    while (k) {
        int aux_col = col;
        int aux_row = 0;
        while (k && aux_row < n) {
            k--;
            mat[aux_row][aux_col] = '1';
            aux_row++;
            aux_col = (aux_col + 1) % n;
        }
        col++;
    }
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }
}


int main() {
    int t; ri(t);
    while (t--)
        solve();
    return 0;
}