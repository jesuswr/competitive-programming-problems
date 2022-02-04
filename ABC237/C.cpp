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
    string s;
    cin >> s;

    int a_cnt = 0;
    for (auto c : s) a_cnt += c == 'a';


    if (a_cnt == SZ(s)) printf("Yes\n");
    else {
        int begin_a = 0;
        int end_a = 0;
        int ind = 0;
        while (s[ind] == 'a') {
            begin_a++;
            ind++;
        }
        ind = SZ(s) - 1;
        while (s[ind] == 'a') {
            end_a++;
            ind--;
        }
        if (end_a < begin_a)
            printf("No\n");
        else {
            int l = begin_a, r = SZ(s) - 1 - end_a;
            while (l < r) {
                if (s[l] == s[r]) {
                    ++l;
                    --r;
                }
                else {
                    printf("No\n");
                    return 0;
                }
            }
            printf("Yes\n");
        }
    }


    return 0;
}