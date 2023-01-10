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
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 1e6+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int MX_D[MAXN], CNT[MAXN];

void pre(){
	for(int i = 2; i < MAXN; ++i){
		if (MX_D[i]) continue;
		for(int j = i; j < MAXN; j += i) MX_D[j] = i;
	}
}

int main(){
	pre();
	int n, k;
	rii(n, k);

	while(n--) {
		int a; ri(a);
		while (a > 1) {
			int d = MX_D[a];
			int cnt = 0;
			while(a % d == 0) {
				++cnt;
				a /= d;
			}
			CNT[d] = max(CNT[d], cnt);
		}
	}

	bool g = 1;
	while(k > 1){
		int d = MX_D[k];
		int cnt = 0;
		while(k % d == 0) {
			++cnt;
			k /= d;
		}
		if (cnt > CNT[d]) g = 0;
	}
	
	cout << (g ? "Yes" : "No") << endl;
	return 0;
}
