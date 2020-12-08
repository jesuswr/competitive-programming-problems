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
const int MAXN = 1010; // CAMBIAR ESTE
const char GOOD = '#', BAD = '.';

// GJNM
int n, m;
vector<string> M[2];

bool valid(vector<string> &mat, int rows, int cols) {
    bool in = false, found = false;
    FOR(i, 0, rows) {
        in = found = false;
        FOR(j, 0, cols) {
            if (mat[i][j] == GOOD) {
                if (in == false && found == true)
                    return false;
                in = true, found = true;
            }
            else {
                in = false;
            }
        }
    }
    return true;
}

bool full_row(vector<string> &mat, int rows, int cols) {
    FOR(i, 0, rows) {
        bool full = true;
        FOR(j, 0, cols) {
            if (mat[i][j] == GOOD)
                full = false;
        }
        if (full)
            return true;
    }
    return false;
}

bool valid(int i, int j) {
    return min(i, j) >= 0 && i < n && j < m && M[0][i][j] == GOOD;
}

void dfs(vector<string> &mat, int i, int j) {
    mat[i][j] = '-';
    for (int di : {1, 0, -1}) {
        for (int dj : {1, 0, -1}) {
            if (abs(di) == abs(dj))
                continue;
            if (valid(i + di, j + dj))
                dfs(mat, i + di, j + dj);
        }
    }
}

int main() {
    rii(n, m);
    M[0] = vector<string>(n, string(m, '0'));
    M[1] = vector<string>(m, string(n, '0'));
    FOR(i, 0, n) {
        cin >> M[0][i];
    }
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            M[1][j][n - 1 - i] = M[0][i][j];
        }
    }
    if (!valid(M[0], n, m) || !valid(M[1], m, n)) {
        printf("-1\n");
        return 0;
    }
    if (full_row(M[0], n, m) ^ full_row(M[1], m, n)) {
        printf("-1\n");
        return 0;
    }
    int comp = 0;
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            if (M[0][i][j] == GOOD) {
                comp++;
                dfs(M[0], i, j);
            }
        }
    }
    printf("%d\n", comp);
    return 0;
}