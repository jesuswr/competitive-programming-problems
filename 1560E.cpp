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

// GJNM
bool check(vii ord, vi cnt, int tot, vi tot_cnt) {
    int x = 0;
    // FOR(i, 0, 26) printf("\t%c : %d %d\n", 'a' + i, cnt[i], tot_cnt[i]);
    for (auto [_, a] : ord) {
        FOR(i, 0, 30) {
            x += cnt[i];
            tot_cnt[i] -= cnt[i];
        }
        if (tot_cnt[a] != 0) {
            // printf("\tepa\n");
            return false;
        }
        cnt[a] = 0;
    }
    return x == tot;
}

bool final_check(string red, string s, vii ord) {
    string aux;
    for (auto [_, a] : ord) {
        for (char c : red) if (c != '?') aux.pb(c);
        FOR(i, 0, SZ(red)) if (red[i] == a + 'a') {
            red[i] = '?';
        }
    }
    // cout << aux << " " << s << " " << red << endl;
    return aux == s;
}

void solve() {
    string s; cin >> s;
    vi lst_oc(30, -1);
    vi tot_cnt(30, 0);
    FOR(i, 0, SZ(s)) lst_oc[s[i] - 'a'] = i;
    FOR(i, 0, SZ(s)) tot_cnt[s[i] - 'a']++;

    vii ord;
    FOR(i, 0, 30) if (lst_oc[i] != -1) ord.pb({lst_oc[i], i});
    sort(ALL(ord));

    vi cnt(30);
    FOR(i, 0, SZ(s)) {
        cnt[s[i] - 'a']++;
        if (check(ord, cnt, SZ(s), tot_cnt) && final_check(s.substr(0, i + 1), s, ord)) {
            cout << s.substr(0, i + 1) << " ";
            for (auto [_, a] : ord) printf("%c", 'a' + a);
            printf("\n");
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}