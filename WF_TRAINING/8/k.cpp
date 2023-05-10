#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dasdas;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) dasdas=scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) dasdas=scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define X second
#define Y first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 2e5+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

unordered_map<int, int> CNT[MAXN];
int L[MAXN], R[MAXN];

void go_l(const vi &xs) {
	unordered_set<int> lv;
	lv.reserve(sz(xs) * 2);

	for(int x : xs) {
		L[x] = sz(lv);

		for(auto [abs_y, cnt] : CNT[x]) {
			if (cnt == 2) {
				if (lv.find(abs_y + (INF - x) + 1) != lv.end() ) lv.erase( abs_y + (INF - x) + 1);
			}
			else if (cnt == 1) {
				if (lv.find(abs_y + (INF - x) + 1) != lv.end() ) lv.erase( abs_y + (INF - x) + 1);
				else lv.insert(abs_y + (INF - x) + 1); 
			}
		}
		
	}
}
void go_r(const vi &xs) {
	unordered_set<int> lv;
	lv.reserve(sz(xs) * 2);

	for(int x : xs) {
		int aux = 0;
		for(auto [abs_y, cnt] : CNT[x]) {
			aux += cnt;
		}

		R[x] = sz(lv) + aux;
		// cout << x << "  " << L[x] << "  " << R[x] << endl;
 
		for(auto [abs_y, cnt] : CNT[x]) {
			if (cnt == 2) {
				if (lv.find(abs_y + x + 1) != lv.end() ) lv.erase( abs_y + x + 1);
			}
			else if (cnt == 1) {
				if (lv.find(abs_y + x + 1) != lv.end() ) lv.erase( abs_y + x + 1);
				else lv.insert(abs_y + x + 1); 
			}
		}
	}
}

void solve() {
	int n, y; rii(n,y);
	vii pt(n);
	vi xs;
	FOR(i,0,n) {
		rii(pt[i].X, pt[i].Y);
		pt[i].X += 5;
		pt[i].Y -= y;
		FOR(x,pt[i].X-2, pt[i].X+3) xs.pb(x);
		CNT[pt[i].X][abs(pt[i].Y)] += 1;
		// printf("(%d, %d)\n", pt[i].X, pt[i].Y);
	}
	sort(xs.begin(), xs.end());
    xs.resize(unique(xs.begin(), xs.end()) - xs.begin());

	go_l(xs);
	reverse(all(xs));
	go_r(xs);

	int mn = INF, mx = 0;
	for(int x : xs) mn = min(mn, L[x] + R[x]), mx = max(mx, L[x] + R[x]);

	cout << mn << " " << mx << endl;
	for(int x : xs) {
		L[x] = R[x] = 0;
		CNT[x].clear();
	}
}

int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}
