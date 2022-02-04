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
string S;
deque<int> OC[26];

int main() {
    ri(N);
    cin >> S;
    for (int i = 0; i < N; ++i) OC[S[i] - 'a'].push_back(i);

    int l = 0, r = N - 1;
    while (l < r) {
        int bg, sm;
        bool found = false;
        for (bg = l; bg < r; ++bg) {
            for (sm = 0; sm < S[bg] - 'a'; ++sm) {
                if (!OC[S[bg] - 'a'].empty() && !OC[sm].empty() && OC[S[bg] - 'a'].front() < OC[sm].back()) {
                    found = true;
                    bg = S[bg] - 'a';
                    break;
                }
            }
            if (found)
                break;
        }
        if (!found) break;
        l = OC[bg].front() + 1;
        r = OC[sm].back() - 1;
        swap(S[l - 1], S[r + 1]);
        FOR(i, 0, 26) {
            while (!OC[i].empty() && OC[i].front() < l) {
                OC[i].pop_front();
            }
            while (!OC[i].empty() && OC[i].back() > r) {
                OC[i].pop_back();
            }
        }
    }
    cout << S << endl;


    return 0;
}