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
string big;
string small[MAXN];
int cnt[30];
int n, l, k;

int calc_lo() {
    if (small[k - 1].size() == 0)
        return 0;

    int ind = small[k - 1].size() - 1;
    FOR(i, 0, k) {
        if (small[i].size() == small[k - 1].size() && small[i][ind] == small[k - 1][ind])
            return i;
    }

    return 0;
}

int main() {
    riii(n, l, k);
    cin >> big;
    for (auto c : big)
        cnt[c - 'a']++;

    int curr = 0;
    FOR(i, 0, l) {
        int lo = calc_lo();
        FOR(i, lo, k) {
            while (cnt[curr] == 0)
                curr++;
            small[i].pb('a' + curr);
            cnt[curr]--;
        }
    }
    while (small[k - 1].size() < l) {
        while (cnt[curr] == 0)
            curr++;
        small[k - 1].pb('a' + curr);
        cnt[curr]--;
    }
    FOR(i, 0, n) {
        while (small[i].size() < l) {
            while (cnt[curr] == 0)
                curr++;
            small[i].pb('a' + curr);
            cnt[curr]--;
        }
    }
    FOR(i, 0, n) {
        cout << small[i] << endl;
    }

    return 0;
}