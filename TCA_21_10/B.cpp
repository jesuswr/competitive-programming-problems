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
    string in;
    getline(cin, in);
    int m;
    FOR(i, 0, SZ(in)) if (in[i] == '=') {
        string _aux;
        FOR(j, i + 2, SZ(in)) _aux.pb(in[j]);
        m = stoi(_aux);
    }


    FOR(__aux, 1,  m + 1) {
        int pos = 1, neg = 0;
        for (auto c : in) {
            if (c == '+')
                pos++;
            if (c == '-')
                neg += __aux;
        }
        int n;
        FOR(i, 0, SZ(in)) if (in[i] == '=') {
            string aux;
            FOR(j, i + 2, SZ(in)) aux.pb(in[j]);
            n = stoi(aux);
        }
        n += neg;
        vi p;
        FOR(i, 0, pos) p.pb(n / pos);
        FOR(i, 0, n % pos) p[i]++;
        bool posss = 1;
        for (int x : p) if (x <= 0 || x > n - neg) {
                posss = 0;
            }
        if (!posss)
            continue;

        printf("Possible\n");
        FOR(i, 0, SZ(in)) {
            if (in[i] == '?' && (i == 0 || in[i - 2] == '+')) {
                printf("%d", p.back());
                p.pop_back();
            }
            else if (in[i] == '?')
                printf("%d", __aux);
            else
                printf("%c", in[i]);
        }
        printf("\n");
        return 0;
    }
    printf("Impossible\n");
    return 0;
}