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

int main() {
    string s; cin >> s;
    vi cnt(26);
    for (auto c : s) cnt[c - 'A']++;

    int odd = -1;
    FOR(i, 0, 26) if (cnt[i] & 1) {
        if (odd != -1) {
            printf("NO SOLUTION\n");
            return 0;
        }
        odd = i;
    }
    string pal;
    FOR(i, 0, 26) if (i != odd)
        FOR(_, 0, cnt[i] / 2) pal += 'A' + i;

    if (odd != -1) {
        FOR(i, 0, cnt[odd]) pal += 'A' + odd;
    }

    FOR(i, 0, 26) if (25 - i != odd)
        FOR(_, 0, cnt[25 - i] / 2) pal += 'A' + (25 - i);

    cout << pal << endl;
    return 0;
}