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
#define riii(a,b,c) ri(a), ri(b), ri(c)
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

int N, M, Q;
int A[MAXN];
int father[MAXN], siz[MAXN];
ll SM[MAXN];
void makeSet(int n, int m){
	for (int i = n; i <= m; ++i){
		father[i] = -1;
		siz[i] = 0;
		SM[i] = A[i];
	}
}
int find(int x){
	if (father[x]==-1)  return x;
	return father[x] = find(father[x]);
}
void unio(int x, int y){ 
	if (siz[x] > siz[y]) {
		father[y] = x;
		SM[x] += SM[y];
	}
	else{
		father[x] = y;
		SM[y] += SM[x];
		if ( siz[x] == siz[y] ) siz[y]++;
	}
}

vector< tuple<int, int, int> > E;
int Ei = 0;
priority_queue< tuple<ll, int, int, int> > pq;

int main(){
	riii(N, M, Q);
	FOR(i,0,N) ri(A[i]);
	FOR(_,0,M) {
		int u,v,w; riii(u,v,w);
		--u; --v;
		E.pb({w,u,v});
	}
	FOR(i,0,Q) {
		int x,k; rii(x,k); --x;
		pq.push({-k, k, x, i});
	}
	sort(all(E));
	makeSet(0, N-1);

	vector<ll> ANS(Q);
	while(!pq.empty()) {
		auto [sm, k, x, qi] = pq.top(); pq.pop();
		sm = -sm;
		// cout << sm << " " << k << " " << x + 1 << " " << qi << endl;
		while(Ei < sz(E)) {
			auto [w, u, v] = E[Ei];
			if (w <= sm) {
				// cout << w << " " << u + 1 << " " << v + 1 << endl;
				u = find(u), v = find(v);
				if (u != v) unio(u, v);
				++Ei;
			}
			else break;
		}

		if (sm < SM[find(x)] + k) 
			pq.push({-(SM[find(x)] + k), k, x, qi});
		else
			ANS[qi] = sm;
	}

	FOR(i,0,Q) printf("%lld\n", ANS[i]);


	return 0;
}
