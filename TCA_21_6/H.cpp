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

int main() {
    ri(N);
    set<string> have;
    FOR(i, 0, N) {
        string s; cin >> s;
        have.insert(s);
    }

    string OPTS = "RGBYW12345";
    int ans = 69;
    FOR(i, 0, 1 << SZ(OPTS)) {
        int cnt = 0;
        vector<set<string>> groups; groups.pb(have);
        FOR(b, 0, SZ(OPTS)) if ((i >> b) & 1) {
            ++cnt;
            vector<set<string>> new_groups;
            for (auto st : groups) {
                set<string> contains, doesnt_contain;
                for (auto s : st) {
                    if (s[0] == OPTS[b] || s[1] == OPTS[b])
                        contains.insert(s);
                    else
                        doesnt_contain.insert(s);
                }
                if (!contains.empty())
                    new_groups.pb(contains);
                if (!doesnt_contain.empty())
                    new_groups.pb(doesnt_contain);
            }
            groups = new_groups;
        }
        bool good = true;
        for (auto st : groups) if (st.size() > 1)
                good = false;
        if (good)
            ans = min(ans, cnt);
    }
    printf("%d\n", ans);
    return 0;
}