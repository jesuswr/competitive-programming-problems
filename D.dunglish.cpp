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
int n, m;
vector<string> s;
map<string, vector<pair<string, bool>>> mp;

int main() {
    ri(n);
    FOR(i, 0, n) {
        string aux; cin >> aux;
        s.pb(aux);
    }
    ri(m);
    FOR(i, 0, m) {
        string aux1, aux2, aux3;
        cin >> aux1 >> aux2 >> aux3;
        if (aux3[0] == 'c')
            mp[aux1].pb({aux2, true});
        else
            mp[aux1].pb({aux2, false});
    }
    vector<string> ans;
    ll good = 1, all = 1;
    FOR(i, 0, n) {
        ll act_good = 0, act_all = 0;
        for (auto psb : mp[s[i]]) {
            if (psb.S)
                act_good++;
            act_all++;
            if (ans.size() <= i)
                ans.pb(psb.F);
        }
        good = good * act_good;
        all = all * act_all;
    }

    if (all == 1) {
        for (auto s : ans)
            cout << s << " ";
        if (good == 1)
            cout << "correct\n";
        else
            cout << "incorrect\n";
    }
    else {
        cout << good << " correct\n";
        cout << all - good << " incorrect\n";
    }

    return 0;
}