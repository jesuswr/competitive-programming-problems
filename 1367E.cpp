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
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM
int n, k;
int cnt[26];

bool good(int len) {
    priority_queue< pair<int, int> > pq;
    FOR(i, 0, 26) {
        pq.push({cnt[i], i});
    }

    int cycle = k % len;
    int need = len / __gcd(len, cycle);
    int need_n = len / need;

    while (need_n > 0) {
        if (pq.top().F < need)
            return false;
        else {
            pii aux = pq.top();
            pq.pop();
            need_n--;
            pq.push({aux.F - need, aux.S});
        }
    }
    return true;
}

int main() {
    int t; ri(t);
    while (t--) {
        rii(n, k);
        string s; cin >> s;
        for (auto c : s)
            cnt[c - 'a']++;

        int ans;
        FOR(i, 1, n + 1) {
            if (good(i))
                ans = i;
        }

        printf("%d\n", ans);

        FOR(i,0,26) cnt[i] = 0;
    }
    return 0;
}