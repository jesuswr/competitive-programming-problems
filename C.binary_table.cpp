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
#define ALL(s) s.begin(),s.end()
#define SZ(s) (int)s.size()

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 110; // CAMBIAR ESTE

// GJNM
int n, m;
vi ans;
int M[MAXN][MAXN];
char M2[MAXN][MAXN];

int get_sm(int r, int c) {
    return M[r][c] + M[r + 1][c] + M[r][c + 1] + M[r + 1][c + 1];
}

void fix(int r, int c, int sm) {
    if (sm == 0)
        return;
    if (sm == 1) {
        int need_0 = 2, need_1 = 1;
        FOR(i, r, r + 2) {
            FOR(j, c, c + 2) {
                if (M[i][j] == 0 && need_0 >= 1) {
                    ans.pb(i + 1), ans.pb(j + 1);
                    M[i][j] = 1;
                    need_0--;
                }
                else if (M[i][j] == 1 && need_1 >= 1) {
                    ans.pb(i + 1), ans.pb(j + 1);
                    M[i][j] = 0;
                    need_1--;
                }
            }
        }
        fix(r, c, 2);
    }
    if (sm == 2) {
        int need_0 = 2, need_1 = 1;
        FOR(i, r, r + 2) {
            FOR(j, c, c + 2) {
                if (M[i][j] == 0 && need_0 >= 1) {
                    ans.pb(i + 1), ans.pb(j + 1);
                    M[i][j] = 1;
                    need_0--;
                }
                else if (M[i][j] == 1 && need_1 >= 1) {
                    ans.pb(i + 1), ans.pb(j + 1);
                    M[i][j] = 0;
                    need_1--;
                }
            }
        }
        fix(r, c, 3);
    }
    if (sm == 3) {
        int need_0 = 0, need_1 = 3;
        FOR(i, r, r + 2) {
            FOR(j, c, c + 2) {
                if (M[i][j] == 0 && need_0 >= 1) {
                    ans.pb(i + 1), ans.pb(j + 1);
                    M[i][j] = 1;
                    need_0--;
                }
                else if (M[i][j] == 1 && need_1 >= 1) {
                    ans.pb(i + 1), ans.pb(j + 1);
                    M[i][j] = 0;
                    need_1--;
                }
            }
        }
    }
    if (sm == 4) {
        int need_0 = 0, need_1 = 3;
        FOR(i, r, r + 2) {
            FOR(j, c, c + 2) {
                if (M[i][j] == 0 && need_0 >= 1) {
                    ans.pb(i + 1), ans.pb(j + 1);
                    M[i][j] = 1;
                    need_0--;
                }
                else if (M[i][j] == 1 && need_1 >= 1) {
                    ans.pb(i + 1), ans.pb(j + 1);
                    M[i][j] = 0;
                    need_1--;
                }
            }
        }
        fix(r, c, 1);
    }
}

void put_zeros(int col) {
    int need_change = 3;
    if (M[n - 1][col] == 1) {
        ans.pb(n), ans.pb(col + 1);
        need_change--;
        M[n - 1][col] = 0;
    }
    if (M[n - 1][col + 1] == 1) {
        ans.pb(n), ans.pb(col + 2);
        need_change--;
        M[n - 1][col + 1] = 0;
    }

    if (need_change >= 1) {
        M[n - 2][col] = 1 - M[n - 2][col];
        need_change--;
        ans.pb(n - 1), ans.pb(col + 1);
    }
    if (need_change >= 1) {
        M[n - 2][col + 1] = 1 - M[n - 2][col + 1];
        need_change--;
        ans.pb(n - 1), ans.pb(col + 1 + 1);
    }
}

void put_zeros2(int row) {
    int need_change = 3;
    if (M[row][m - 1] == 1) {
        ans.pb(row + 1), ans.pb(m);
        need_change--;
        M[row][m - 1] = 0;
    }
    if (M[row + 1][m - 1] == 1) {
        ans.pb(row + 2), ans.pb(m);
        need_change--;
        M[row + 1][m - 1] = 0;
    }

    if (need_change >= 1) {
        M[row][m - 2] = 1 - M[row][m - 2];
        need_change--;
        ans.pb(row + 1), ans.pb(m - 1);
    }
    if (need_change >= 1) {
        M[row + 1][m - 2] = 1 - M[row + 1][m - 2];
        need_change--;
        ans.pb(row + 2), ans.pb(m - 1);
    }
}

void pm() {
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void solve() {
    rii(n, m);
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            scanf("%1d", &M[i][j]);
        }
    }


    if ((n & 1) && (m & 1)) {
        if (M[n - 1][m - 1] == 1) {
            ans.pb(n), ans.pb(m);
            M[n - 1][m - 1] = 0;
            ans.pb(n - 1), ans.pb(m);
            ans.pb(n), ans.pb(m - 1);
            M[n - 1][m - 2] = 1 - M[n - 1][m - 2];
            M[n - 2][m - 1] = 1 - M[n - 2][m - 1];
        }
    }
    if (n & 1) {
        for (int j = 0; j < m - 1; j += 2) {
            int sm = M[n - 1][j] + M[n - 1][j + 1];
            if (sm == 0)
                continue;
            put_zeros(j);
        }
    }
    if (m & 1) {
        for (int i = 0; i < n - 1; i += 2) {
            int sm = M[i][m - 1] + M[i + 1][m - 1];
            if (sm == 0)
                continue;
            put_zeros2(i);
        }
    }


    for (int i = 0; i < n - 1; i += 2) {
        for (int j = 0; j < m - 1; j += 2) {
            int sm = get_sm(i, j);
            fix(i, j, sm);
        }
    }

    printf("%d", SZ(ans) / 6);
    int cnt = 0;
    for (auto x : ans) {
        if (cnt % 6 == 0)
            printf("\n");
        cnt++;
        printf("%d ", x);
    }
    printf("\n");
    ans.clear();
}

int main() {
    int t;
    ri(t);
    while (t--)
        solve();
    return 0;
}