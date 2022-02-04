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

int main() {
    ri(N);
    vector<tuple<int, int, int>> rgs;
    int cst = 0;
    FOR(i, 0, N) {
        int a; ri(a);
        vector<tuple<int, int, int>> new_rgs;
        for (auto [l, r, gcd] : rgs) {
            int new_gcd = __gcd(gcd, a);
            if (SZ(new_rgs) == 0)
                new_rgs.pb({l, r, new_gcd});
            else {
                auto [_l, _r, _gcd] = new_rgs.back();
                if (new_gcd == _gcd) {
                    new_rgs.pop_back();
                    new_rgs.push_back({_l, r, new_gcd});
                }
                else
                    new_rgs.pb({l, r, new_gcd});
            }
        }
        int l = i, r = i, new_gcd = a;
        if (SZ(new_rgs) == 0)
            new_rgs.pb({l, r, new_gcd});
        else {
            auto [_l, _r, _gcd] = new_rgs.back();
            if (new_gcd == _gcd) {
                new_rgs.pop_back();
                new_rgs.push_back({_l, r, new_gcd});
            }
            else
                new_rgs.pb({l, r, new_gcd});
        }

        // for (auto [_l, _r, gcd] : new_rgs) {
        // printf("%d %d %d\n", _l, _r, gcd);
        // }

        bool upd = 0;
        for (auto [_l, _r, gcd] : new_rgs) {
            int aux_r = i - _l + 1, aux_l = i - _r + 1;
            if (gcd <= aux_r && gcd >= aux_l) {
                upd = 1;
                break;
            }
        }
        if (upd) {
            new_rgs.clear();
            new_rgs.pb({0, i, 1});
            cst++;
        }


        swap(rgs, new_rgs);
        printf("%d ", cst);
    }
    printf("\n");
    return 0;
}