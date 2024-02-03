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
const int MAXN = 25;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N, K;
queue<int> Q[MAXN];

int main(){
	freopen("easy.in", "r", stdin);
	freopen("easy.out", "w", stdout);

	int its = 0;
	rii(N,K);
	FOR(i,0,N) {
		int szi; ri(szi);
		its = max(its, szi);
		while(szi--) {
			int a; ri(a);
			Q[i].push(a);
		}
	}

	int ans = 0, picks = 0;
	FOR(_,0,its) {
		FOR(i,0,N) {
			int x = Q[i].empty() ? 50 : Q[i].front();
			if (!Q[i].empty()) Q[i].pop();
			if (picks < K && ans <= x) {
				picks++;
				ans += x;
			}
		} 
	}
	ans += (K - picks) * 50;
	cout << ans << endl;


	return 0;
}
