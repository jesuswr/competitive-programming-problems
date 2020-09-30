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
string s;

void solve_1(int c) {
    int x = 0, y = 0;
    FOR(i, 1, c) {
        x = x * 10;
        x += (s[i] - '0');
    }
    FOR(i, c + 1, s.size()) {
        y = y * 10;
        y += (s[i] - '0');
    }

    string aux;
    while (y > 0) {
        y--;
        aux.pb( (y % 26) + 'A' );
        y = y / 26;
    }
    reverse(aux.begin(), aux.end());
    cout << aux << x << endl;
}


void solve_2(int c) {
    printf("R" );
    FOR(i, c, s.size()) {
        printf("%c", s[i]);
    }

    int x = 0;
    int pw = 1;
    ROF(i, c - 1, -1) {
        x += pw * (s[i] - 'A' + 1);
        pw = pw * 26;
    }
    printf("C%d\n", x);
}


void solve() {
    cin >> s;

    if (s[0] == 'R' && s[1] <= '9') {
        FOR(i, 2, s.size()) {
            if (s[i] == 'C') {
                solve_1(i);
                return;
            }
        }
    }
    FOR(i, 0, s.size()) {
        if (s[i] <= '9') {
            solve_2(i);
            return;
        }
    }
}

int main() {
    int t;
    ri(t);
    while (t--) {
        solve();
    }

    return 0;
}