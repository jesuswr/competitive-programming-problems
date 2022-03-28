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
int query(int a, int b, int c) {
    printf("? %d %d %d", a, b, c);
    cout << endl;
    int ans; ri(ans);
    return ans;
}

void solve() {
    int n; ri(n);
    int a = 1, b = 2;
    int dff = -1;
    for (int i = 3; i < n; i += 2) {
        int mx = -1;
        set<int> news;
        for (int o1 : {a, b, i, i + 1})
            for (int o2 : {b, i, i + 1})
                for (int o3 : {i, i + 1}) {
                    if (o1 < o2 && o2 < o3 ) {
                        int val = query(o1, o2, o3);
                        if (val > mx) {
                            mx = val;
                            news.clear();
                            news.insert(o1);
                            news.insert(o2);
                            news.insert(o3);
                        }
                        else if (val == mx && SZ(news) == 3) {
                            set<int> aux;
                            if (news.find(o1) != news.end())
                                aux.insert(o1);
                            if (news.find(o2) != news.end())
                                aux.insert(o2);
                            if (news.find(o3) != news.end())
                                aux.insert(o3);
                            swap(aux, news);
                        }
                    }
                }
        a = *news.begin();
        b = *news.rbegin();
        dff = max(dff, mx);
    }
    if (n & 1) {
        int aux = 1;
        while (aux == a || aux == b) aux++;
        int op1 = query(a, aux, n), op2 = query(b, aux, n);
        if (op1 > op2 && op1 > dff) {
            dff = op1;
            a = a;
            b = n;
        }
        if (op2 > dff) {
            dff = op2;
            a = n;
            b = b;
        }
    }


    printf("! %d %d", a, b);
    cout << endl;
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}