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
const int MAXN = 2e5+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}


int main(){
	int t; ri(t);
	int _i = 0;
	while(t--) {
		int x, y, k; rii(x,y); ri(k);
		printf("Case #%d: ", ++_i);
		if (x > y) 
			printf("%d\n", k);
		else {
			int carry = 0;
			int ans = 0;
			int need = 11 * y;
			FOR(_,0,k) {
				carry += 9 * x;
				if (carry >= need) {
					carry -= need;
					ans++;
				}
				else {
					carry += 2 * x;
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
