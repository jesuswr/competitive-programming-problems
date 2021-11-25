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
const int MAXN = 1e5 + 69; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
long double PRE_S[MAXN], PRE_D[MAXN];

int main() {
    int n; ri(n);
    int curr = 1;
    while (n--) {
        string s; cin >> s;
        if (s[0] == 'R') {
            int ci; ri(ci);
            PRE_S[curr] = PRE_S[curr - 1] + ci;
            PRE_D[curr] = PRE_D[curr - 1] + ci * ci;
            ++curr;
        }
        else {
            int t; ri(t);
            long double sum = PRE_S[curr - 1] - PRE_S[curr - t - 1];
            long double sum_sq = PRE_D[curr - 1] - PRE_D[curr - t - 1];
            long double u = sum / t;
            long double ans = sqrt((sum_sq - 2 * u * sum + t * u * u) / (1.0 * t)) / sqrt(1.0 * t);
            // cout << sum << endl;
            // cout << sum_sq << endl;
            // cout << u << endl;
            // cout << (sum_sq - 2 * u * sum + u * u) / (1.0 * t) << endl;
            printf("%.10Lf %.10Lf\n", u - 2 * ans, u + 2 * ans);
        }
    }

    return 0;
}