#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int dasds;
#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define ri(a) dasds=scanf("%d", &a)
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
const int MAXN = 2e5+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}
// tp = 0 solved
// tp = 1 not solved
// tp = 2 don't know

struct problem {
	int tp, x, y;
};

int n, m;
int a[MAXN], b[MAXN];
vector<problem> frozen[MAXN];

char tmp[5];
void readPerson(int i) {
	rii(a[i], b[i]);
	FOR(j,0,m) {
		dasds=scanf("%s", tmp);
		int t = 0, x = 0, y = 0;
		if (tmp[0] == '+') {
			t = 0;
			dasds=scanf("%d/%d", &x, &y);
		}
		if (tmp[0] == '-') {
			t = 1;
			ri(x);
		}
		if (tmp[0] == '.') {
			t = 1;
		}

		if(tmp[0] == '?') {
			t = 2;
			rii(x, y);
		}

		frozen[i].pb({t, x, y});
	}
}

vi mskBucket[15];

void go(int per) {
    for(int msk : mskBucket[a[per]]) {
        vector<problem> cp;
        vector<int> add;
        bool g = 1;
        FOR(pro,0,m) {
            problem curr = frozen[per][pro];
            int can_add = 0;
            if ((msk >> pro) & 1) { // want to solve
                if (frozen[per][pro].tp == 0) curr = frozen[per][pro];
                else if (frozen[per][pro].tp == 1) {
                    g = 0;
                    break;
                }
                else {
                    curr.tp = 0;
                    curr.y = 240;
                    curr.x = frozen[per][pro].y - frozen[per][pro].x + 1;
                    can_add = frozen[per][pro].x - 1;
                }
            }
            else { // dont want to solve
                if (frozen[per][pro].tp == 0) {
                    g = 0;
                    break;
                }
                else if (frozen[per][pro].tp == 1) {
                    curr = frozen[per][pro];
                }
                else {
                    curr.tp = 1;
                    curr.x = frozen[per][pro].y;
                }
            }
            cp.pb(curr);
            add.pb(can_add);
        }

        if (!g) continue;
        int penalty = b[per];
        FOR(pro,0,m) if (cp[pro].tp == 0) {
            penalty = penalty - (20 * (cp[pro].x - 1) + cp[pro].y);
        }

        if (penalty < 0) continue;

        FOR(pro,0,m) if (add[pro] > 0) {
            int need = min(penalty / 20, add[pro]);
            add[pro] -= need;
            penalty -= 20 * need;
            cp[pro].x += need;
        }

        FOR(pro,0,m) if (cp[pro].y == 240) {
            int need = min(penalty, 59);
            penalty -= need;
            cp[pro].y += need;
        }


        if (penalty == 0) {
            printf("Yes\n");
            for(auto p : cp) {
                if (p.tp == 0) {
                    printf("+ %d/%d\n", p.x, p.y);
                }
                else {
                    if (p.x == 0) printf(".\n");
                    else printf("- %d\n", p.x);
                }
            }
            return;
        }
    }
    printf("No\n");
}

int main() {
	rii(n,m);
	FOR(i,0,n) readPerson(i);
    FOR(i,0,1<<m) {
        int cnt = 0;
        FOR(b,0,m) if ((i >> b) & 1) ++cnt;
        mskBucket[cnt].pb(i);
    }

    FOR(i,0,n) go(i);
	return 0;
}