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
int N;
string M[51];

void solve() {
    ri(N);
    FOR(i, 0, N) cin >> M[i];

    int bst = INF, bst_cnt = 0;
    FOR(i, 0, N) {
        int x_cnt = 0, o_cnt = 0;
        FOR(j, 0, N) {
            if (M[i][j] == 'X')
                x_cnt++;
            else if (M[i][j] == 'O')
                o_cnt++;
        }
        if (o_cnt == 0) {
            if (N - x_cnt < bst) {
                bst = N - x_cnt;
                bst_cnt = 1;
            }
            else if (N - x_cnt == bst)
                bst_cnt++;
        }
    }

    FOR(i, 0, N) {
        int x_cnt = 0, o_cnt = 0;
        FOR(j, 0, N) {
            if (M[j][i] == 'X')
                x_cnt++;
            else if (M[j][i] == 'O')
                o_cnt++;
        }
        if (o_cnt == 0) {
            if (N - x_cnt < bst) {
                bst = N - x_cnt;
                bst_cnt = 1;
            }
            else if (N - x_cnt == bst)
                bst_cnt++;
        }
    }

    FOR(i, 0, N) FOR(j, 0, N) {
        if (M[i][j] == '.') {
            int x_cnt1 = 0, o_cnt1 = 0;
            FOR(k, 0, N) {
                if (M[i][k] == 'X')
                    x_cnt1++;
                else if (M[i][k] == 'O')
                    o_cnt1++;
            }
            int x_cnt2 = 0, o_cnt2 = 0;
            FOR(k, 0, N) {
                if (M[k][j] == 'X')
                    x_cnt2++;
                else if (M[k][j] == 'O')
                    o_cnt2++;
            }

            if (o_cnt2 == 0 && o_cnt1 == 0)
                if (x_cnt1 == N - 1 && x_cnt2 == N - 1 && bst == 1)
                    bst_cnt--;
        }
    }

    if (bst == INF)
        printf("Impossible\n");
    else
        printf("%d %d\n", bst, bst_cnt);

}

int main() {
    int t; ri(t);
    FOR(i, 1, t + 1) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}