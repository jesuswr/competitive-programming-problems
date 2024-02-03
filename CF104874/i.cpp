#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int das;
#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) das=scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) das=scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 1e9;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 2e5+5;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N;
int X[MAXN], Y[MAXN], H[MAXN];


int main(){
	ri(N);
	FOR(i,0,N) rii(X[i], Y[i]), ri(H[i]);
	int min_x = INF, max_x = -INF, min_y = INF, max_y = -INF;
	FOR(i,0,N) {
		min_x = min(min_x, X[i] - H[i] );
		max_x = max(max_x, X[i] + H[i] );
		min_y = min(min_y, Y[i] - H[i] );
		max_y = max(max_y, Y[i] + H[i] );
	}

	int mx_diff = max(max_x - min_x, max_y - min_y);
	int h = (mx_diff + 1) / 2;
	cout << (min_x + max_x) / 2 << " " << (min_y + max_y) / 2 << " " << h << endl;

	return 0;
}
