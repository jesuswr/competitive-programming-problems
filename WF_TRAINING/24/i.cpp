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
const int MAXN = 2e5+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}


int main()
{
	vector< pair<long double, int> > pp;
	int n, w, u, v, t1, t2;
	rii(n,w), rii(u,v), rii(t1,t2);
	for (int i = 1; i <= n; i++) {
		int m;
		char s[20];
		scanf("%s", s);
		ri(m);
		while (m--) {
			int len, pos;
			rii(len, pos);
			if (s[0] == 'E')
				pos = -pos;
			
			long double l = (long double) pos / u;
			l -= (long double) w * i / v;
			long double r = (long double) (pos + len) / u;
			r -= (long double) w * (i - 1) / v;
			pp.push_back(make_pair(l, 1));
			pp.push_back(make_pair(r, -1));
		}
	}
	pp.push_back(make_pair(1e15, 1));
	pp.push_back(make_pair(t1, 0));
	sort(pp.begin(), pp.end());
	
	long double ans = 0;
	int tmp = 0;
	for (int i = 0; i < sz(pp) - 1; i++)	{
		tmp += pp[i].second;
		if (tmp == 0 && pp[i].first >= t1) ans = max(ans, min((long double) t2, pp[i + 1].first) - pp[i].first);
	}
	printf("%.12Lf\n", ans);
	return 0;
}
 