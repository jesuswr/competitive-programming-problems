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
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
int cnt[8];

int main() {
    int n;
    ri(n);
    cnt[0] = 1, cnt[7] = 2;
    n -= 2;

    FOR(i, 0, 8) {
        int add = min(n, 8 - cnt[i]);
        n -= add;
        cnt[i] += add;
    }

    vii ans;
    int last = 0;

    FOR(i, 0, 8) {
        if (cnt[i] == 0)
            continue;

        int new_last = 1 - last;
        if (i == 7)
            new_last = 7;
        ans.pb({i, last});

        if (cnt[i] == 1)
            continue;

        int j = 0;
        while (cnt[i] > 2) {
            if (last == j || new_last == j) {
                j++;
                continue;
            }
            cnt[i]--;
            ans.pb({i, j});
            j++;
        }

        ans.pb({i, new_last});
        last = new_last;
    }

    for (auto p : ans) {
        printf("%c%d ", (p.F + 'a'), p.S + 1);
    } printf("\n");


    return 0;
}