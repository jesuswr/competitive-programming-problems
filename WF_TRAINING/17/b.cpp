#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
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


bool good(ll a, ll b, ll c, ll w, ll h) {
	return (b + 2 * c <= w && 2 * a + 2 * c <= h) || (c + a <= h && 3 * b + c + a <= w);
}


int main(){
	srand ( unsigned ( std::time(0) ) );
	vector<ll> cube(3), rect(2);
	FOR(i,0,3) ri(cube[i]);
	FOR(i,0,2) ri(rect[i]);

	FOR(i,0,100000) {
		random_shuffle (all(cube));
		random_shuffle (all(rect));
		if (good(cube[0], cube[1], cube[2], rect[0], rect[1])) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
