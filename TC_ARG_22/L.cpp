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

int N, P;
ii T[MAXN];
ll ANS[MAXN];

int main(){
	rii(N,P);
	FOR(i,0,N) {
		ri(T[i].F);
		T[i].S = i;
	}

	sort(T, T+N);
	priority_queue<int> pq;

	ll nxt = 0;
	int l = 0;
	int p = 0;
	while (p < N) {
		if (pq.empty())
			nxt = max(nxt, 1ll * T[l].F);
		while(l < N && T[l].F <= nxt) {
			pq.push(-T[l].S);
			++l;
		}	
		++p;
		int ind = -pq.top();
		pq.pop();
		ANS[ind] = nxt + P;
		nxt += P;
	}

	for(int i = 0; i < N; ++i) printf("%lld ", ANS[i]);
	putchar('\n');


	return 0;
}
