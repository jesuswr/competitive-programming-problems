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

using namespace std;

typedef long long ll;
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
const int MAXN = 510; // CAMBIAR ESTE

// GJNM
map<string, int> str_to_i;
map<int, string> i_to_str;
int N;
vi G[MAXN];
int D[MAXN][MAXN];
int FAT[MAXN][MAXN];

int mn = INF;
pii xy;

void bfs(int s) {
    FOR(i, 0, N) D[s][i] = 1e5;
    D[s][s] = 0;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto y : G[x]) {
            if (D[s][y] > D[s][x] + 1) {
                D[s][y] = D[s][x] + 1;
                FAT[s][y] = x;
                q.push(y);
            }
            if (y == s && D[s][x] + 1 < mn) {
                mn = D[s][x] + 1;
                xy = {s, x};
            }
        }
    }
}

int main() {
    ri(N);
    FOR(i, 0, N) {
        string s; cin >> s;
        str_to_i[s] = i;
        i_to_str[i] = s;
    }

    FOR(i, 0, N) {
        string trash; int k;
        cin >> trash >> k;
        FOR(_, 0, k) {
            cin >> trash;
            string line;
            getline(cin, line);
            line.pb(',');
            string tmp;
            for (auto c : line) {
                if (c == ' ') continue;
                if (c == ',') {
                    G[i].pb(str_to_i[tmp]);
                    tmp.clear();
                }
                else tmp.pb(c);
            }
        }
    }
    FOR(i, 0, N) bfs(i);
    if (mn == INF) printf("SHIP IT\n");
    else {
        vector<string> out;
        int a = xy.F, b = xy.S;
        while (69) {
            out.pb(i_to_str[b]);
            if (a == b) break;
            b = FAT[a][b];
        }
        reverse(ALL(out));
        for (auto s : out) cout << s << " ";
        cout << endl;
    }
    return 0;
}