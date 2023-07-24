#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define FOR(i,n,m) for (int i = n; i < (int)m; i++)
#define ROF(i,n,m) for (int i = n; i > (int)m; i--)
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define ri(a) scanf("%d", &a)
#define rii(a, b) ri(a), ri(b)
#define lri(a) scanf("%lld", &a)
#define lrii(a, b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = (1<<16) + 5;

void fastIO() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
}

const int SHIFT = 1<<15;

string s;
int ans[MAXN];

int main() {
    // freopen("hard.in", "r", stdin); // redirects standard input
    // freopen("hard.out", "w", stdout); // redirects standard output

    while(getline(cin, s)) {
        stringstream ss(s);
        int L = -SHIFT, R = SHIFT-1;
        string x;

        while (ss >> x) {
            if (x[0] == '>') ss >> L;
            if (x[0] == '<') ss >> R;
        }

        if (L <= R) ans[L+SHIFT]++, ans[R+SHIFT+1]--;
    }

    FOR(i,1,MAXN) ans[i] += ans[i-1];

    bool allTrue = true;
    bool allFalse = true;

    FOR(i,0,2*SHIFT) {
        if (ans[i] > 0) allFalse = false;
        else allTrue = false;
    }

    if (allTrue) cout << "true\n";
    else if (allFalse) cout << "false\n";
    else {
        vii res;
        int pos = 0;
        while (pos < 2*SHIFT) {
            while (pos < 2*SHIFT && !ans[pos]) pos++;
            int L = pos;
            while (pos < 2*SHIFT && ans[pos]) pos++;
            int R = pos;

            res.pb({L, R});
        }

        FOR (i,0,sz(res)) {
            if (i) cout << " ||\n";
            auto [L, R] = res[i];

            if (L == 0) cout << "x <= " << R-1-SHIFT;
            else if (R == 2*SHIFT) cout << "x >= " << L-SHIFT;
            else cout << "x >= " << L-SHIFT << " && x <= " << R-1-SHIFT;
        }
        cout << endl;
    }


    return 0;
}
