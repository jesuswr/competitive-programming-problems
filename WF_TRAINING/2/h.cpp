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
const int MAXN = 5e+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N;
ll A[MAXN];

int father[MAXN], hei[MAXN], siz[MAXN], L[MAXN], R[MAXN];
ll sm[MAXN];
void makeSet(int n, int m) {
	for(int i = n; i <= m; ++i) {
		father[i] = -1;
		hei[i] = 0;
		siz[i] = 1;
		sm[i] = A[i];
		L[i] = R[i] = i;
	}
}
int find(int x){
	if (father[x]==-1)  return x;
	return father[x] = find(father[x]);
}
// x is to the left of y
void unio(int x, int y){ 
	x = find(x);
	y = find(y);
	if (hei[x] > hei[y]) {
		father[y] = x;
		sm[x] += sm[y];
		siz[x] += siz[y];
		R[x] = R[y];
	}
	else{
		father[x] = y;
		sm[y] += sm[x];
		siz[y] += siz[x];
		L[y] = L[x];
		if ( hei[x] == hei[y] ) hei[y]++;
	}
}

void expand(int x, ll k) {
	int l = (x - 1 + N) % N, r = (x + 1) % N;
	bool c = 1;
	while(c) {
		c = 0;
		if (find(x) != find(l) && (siz[find(l)] > 1 || A[l] <= k + sm[find(x)] )) {
			unio(l, x);
			c = 1;
			l = (L[find(x)] - 1 + N) % N;
		}
		if (find(x) != find(r) && (siz[find(r)] > 1 || A[r] <= k + sm[find(x)] )) {
			unio(x, r);
			c = 1;
			r = (R[find(x)] + 1) % N;
		}
	}
}

bool valid(ll k) {
	makeSet(0, N-1);
	FOR(i,0,N) {
		if (i == find(i) && A[i] <= k) {
			expand(i, k);
		}
	}
	return siz[find(0)] == N;
}


int main(){
	ri(N);
	FOR(i,0,N) lri(A[i]);

	ll lo = 0, hi = 1e13;
	while(lo < hi) {
		ll mi = lo + (hi - lo) / 2;
		if (valid(mi)) hi = mi;
		else lo = mi + 1;
	}
	cout << lo << endl;
	return 0;
}
