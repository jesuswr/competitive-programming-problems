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

int main() {
    string txt, pat;
    cin >> txt >> pat;
    int cnt = 0;
    vi pi(SZ(pat) + 1);
    FOR(i, 1, SZ(pat)) {
        int j = pi[i - 1];
        while (j > 0 && pat[j] != pat[i]) j = pi[j - 1];
        if (pat[i] == pat[j]) pi[i] = j + 1;
    }
    int lst = 0;
    FOR(i, 0, SZ(txt)) {
        int j = lst;
        while (j > 0 && pat[j] != txt[i]) j = pi[j - 1];
        if (txt[i] == pat[j]) j = j + 1;
        lst = j;
        cnt += lst == SZ(pat);
    }
    printf("%d\n", cnt);
    return 0;
}