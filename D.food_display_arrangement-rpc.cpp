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
#define all(s) s.begin(),s.end()

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e5 + 10; // CAMBIAR ESTE

// GJNM
int n;

int a[MAXN], b[MAXN];

void compress() {
    FOR(i, 0, n) {
        b[i] = a[i];
    }
    sort(b, b + n);
    map<int, int> new_val;
    FOR(i, 0, n) {
        new_val[b[i]] = i;
    }
    FOR(i, 0, n) {
        a[i] = new_val[a[i]];
    }
}

bool DELETED[MAXN];
bool IN_Q[MAXN];
int FIRST[MAXN], LAST[MAXN];

int main() {
    ri(n);
    FOR(i, 0, n) {
        ri(a[i]);
    }
    compress();
    FOR(i, 0, MAXN) {
        FIRST[i] = INF;
        LAST[i] = -1;
    }

    FOR(i, 0, n) {
        FIRST[a[i]] = min(FIRST[a[i]], i);
        LAST[a[i]] = i;
    }

    queue<int> sweep;
    int ans = 0;
    FOR(i, 0, n) {
        if (DELETED[a[i]])
            continue;
        if (i == FIRST[a[i]])
            sweep.push(a[i]);
        if (i == LAST[a[i]]) {
            while (!sweep.empty()) {
                int aux = sweep.front(); sweep.pop();
                if (a[i] == aux)
                    continue;
                ans++;
                DELETED[aux] = true;
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}