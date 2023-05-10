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


int main(){
	int n; ri(n);
	if (n == 2) cout << "10" << endl;
	else if (n == 3) cout << "Unlucky" << endl;
	else {
		string s;
		while(n > 0) {
			if (n == 5) {
				s += "10001";
				n -= 5;
			}
			else if (n == 6) {
				s += "100110";
				n -= 6;
			}
			else if (n == 7) {
				s += "1000110";
				n -= 7;
			}
			else {
				s += "1001";
				n -= 4;
			}
		}
		cout << s << endl;
	}
	return 0;
}
