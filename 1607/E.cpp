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
    int t; ri(t);
    while (t--) {
        int n, m; rii(n, m);
        string s; cin >> s;
        int l = 0, r = 0, u = 0, d = 0;
        int mxl = 0, mxr = 0, mxu = 0, mxd = 0;
        for (auto c : s) {
            if (c == 'L') {
                ++l;
                --r;
                if (l > mxl) {
                    if (mxl + 1 + mxr < m)
                        mxl++;
                    else
                        break;
                }
            }
            else if (c == 'R') {
                ++r;
                --l;
                if (r > mxr) {
                    if (mxl + 1 + mxr < m)
                        mxr++;
                    else
                        break;
                }
            }
            else if (c == 'D') {
                ++d;
                --u;
                if (d > mxd) {
                    if (mxd + 1 + mxu < n)
                        mxd++;
                    else
                        break;
                }
            }
            else {
                ++u;
                --d;
                if (u > mxu) {
                    if (mxd + 1 + mxu < n)
                        mxu++;
                    else
                        break;
                }
            }
        }
        printf("%d %d\n", 1 + mxu, 1 + mxl);
    }

    return 0;
}