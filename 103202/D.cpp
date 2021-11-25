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
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
string s;
vector<string> ANS;
void dfs(int i, int odd = 0, int even = 1, int sm = 0) {
    if (i == N) {
        if (abs(odd - even) <= 1)
            ANS.pb(s);
        return;
    }
    if (SZ(ANS) < 100 && abs(odd - even) - 1 <= N - i) {
        s.pb('b');
        dfs(i + 1, odd + (sm & 1), even + (~sm & 1), sm);
        s.pop_back();
    }
    if (SZ(ANS) < 100 && abs(odd - even) - 1 <= N - i) {
        s.pb('r');
        dfs(i + 1, odd + (~sm & 1), even + (sm & 1), sm + 1);
        s.pop_back();
    }
}

int main() {
    ri(N);
    dfs(0);
    printf("%lld\n", ((1ll * N + 1) / 2) * ((1ll * N + 2) / 2));
    for (auto t : ANS) cout << t << endl;
    return 0;
}