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
const int MAXN = 3e5+5;

struct bit {
	vector<ll> BIT;
	bit(int n) {
		BIT.resize(n+1);
	}
	void updBIT(int p, ll val){ 
		p++;	
		for(; p < sz(BIT); p += p&-p) BIT[p] += val;
	}
	ll sumBIT(int p){
		p++;
		ll ret = 0;
		for(; p; p -= p&-p) 
			ret += BIT[p];
		return ret;
	}
};

int N;
int A[MAXN], B[MAXN];

bool cmp_a(int i, int j) {
	if (A[i] != A[j]) return A[i] < A[j];
	return i < j;
}
bool cmp_b(int i, int j) {
	if (B[i] != B[j]) return B[i] < B[j];
	return i < j;
}

int Ai[MAXN], Bi[MAXN];
ll calc_n_moves() {
	FOR(i,0,N) Ai[i] = Bi[i] = i;
	sort(Ai, Ai+N, cmp_a);
	sort(Bi, Bi+N, cmp_b);

	ll mvs = 0;
	bit ab(N), bb(N);
	FOR(i,0,N) ab.updBIT(i, 1), bb.updBIT(i, 1);

	FOR(i,0,N) {
		int ai = ab.sumBIT(Ai[i]), bi = bb.sumBIT(Bi[i]);
		mvs += abs(ai - bi);
		ab.updBIT(Ai[i], -1);
		bb.updBIT(Bi[i], -1);
	}

	return mvs;
}

map<int, set<int>> mpa, mpb;
vi ord;
vi nxt, prv;

void swap_l(int i, int l, ll &mvs) {
	if (mvs == 0) exit(0);
	--mvs;
	mpa[A[l]].erase(l);
	mpa[A[l]].insert(i);
	mpa[A[i]].erase(i);
	mpa[A[i]].insert(l);
	swap(A[i], A[l]);
	cout << l + 1 << " " << i + 1 << endl;
}

void swap_r(int i, int r, ll &mvs) {
	if (A[i] == A[r])
		swap_r(r, nxt[r], mvs);
	if (mvs == 0) exit(0);
	--mvs;
	assert(A[i] != A[r]);
	mpa[A[r]].erase(r);
	mpa[A[r]].insert(i);
	mpa[A[i]].erase(i);
	mpa[A[i]].insert(r);
	swap(A[i], A[r]);
	cout << i + 1 << " " << r + 1 << endl;
}

void dlt(int i) {
	if (prv[i] != -1) nxt[prv[i]] = nxt[i];
	if (nxt[i] != -1) prv[nxt[i]] = prv[i];
	mpa[A[i]].erase(i);
	mpb[A[i]].erase(i);
}

void print_moves(ll mx_mvs) {
	nxt.resize(N);
	prv.resize(N);
	ord.resize(N);
	FOR(i,0,N) {
		mpa[A[i]].insert(i);
		mpb[B[i]].insert(i);
		nxt[i] = (i + 1 < N ? i + 1 : -1);
		prv[i] = (i > 0 ? i - 1 : - 1);
		ord[i] = A[i];
	}
	sort(all(ord));


	for(int x : ord) {
		int i = *mpa[x].begin(), wi = *mpb[x].begin();
		// cout << " \t";
		// FOR(i,0,N) cout << A[i] << " ";
		// cout << endl;
		// for(int x : mpa[x]) cout << "\t" << x << endl;
		// cout << "\t" << x << " " << i << " " << wi << endl;

		while(i < wi) {
			swap_r(i, nxt[i], mx_mvs);
			i = nxt[i];
		}
		while(i > wi) {
			swap_l(i, prv[i], mx_mvs);
			i = prv[i];
		}
		dlt(i);
	}
	

}





int main(){
	ri(N);
	FOR(i,0,N) ri(A[i]);
	FOR(i,0,N) ri(B[i]);

	ll mvs = calc_n_moves();
	cout << mvs << endl;
	if (mvs > 2e5) mvs = 2e5;
	print_moves(mvs);
	return 0;
}
