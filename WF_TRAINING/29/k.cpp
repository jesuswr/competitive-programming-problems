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
#define lri(a) das=scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 5e5+55;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

ll BIT[2][MAXN], LOGN = log2(MAXN)+1;
void updBIT(int k, int p, ll val){ 
    p++;	
    for(; p < MAXN; p += p&-p) BIT[k][p] += val;
}

ll sumBIT(int k, int p){
    p++;
    ll ret = 0;
    for(; p; p -= p&-p) 
    	ret += BIT[k][p];
    return ret;
}

// lower bound on prefix sum
int bit_search(int k, int v){
	int sum = 0;
	int pos = 0;
	
	for(int i=LOGN; i>=0; i--){
		if(pos + (1 << i) < MAXN and sum + BIT[k][pos + (1 << i)] < v){
			sum += BIT[k][pos + (1 << i)];
			pos += (1 << i);
		}
	}

	return pos + 1; 
}



int N; ll K;
ii A[MAXN];
int B[MAXN];

void compress() {
	FOR(i,0,N) B[i] = A[i].F;
	sort(B, B+N);
	FOR(i,0,N) A[i].S = lower_bound(B, B+N, A[i].F) - B;
}


bool valid(int sz) {
	// cout << sz << endl;
	ll tot = 0;
	FOR(i,0,sz) {
		updBIT(0, A[i].S, A[i].F);
		updBIT(1, A[i].S, 1);
		tot += A[i].F;
	}

	int m = (sz + 1) / 2;
	bool g = 0;
	int lsti;
	FOR(i,0,N-sz+1) {
		lsti = i;
		int midInd = bit_search(1, m) - 1;
		ll lsum = sumBIT(0, midInd);
		ll rsum = tot - lsum;
		ll lcnt = sumBIT(1, midInd);
		ll rcnt = sz - lcnt;
		ll val = (lcnt * B[midInd] - lsum) + (rsum - rcnt * B[midInd]);
		// cout << "    " << i << " " << val << endl;
		if (K >= val) {
			g = 1;
			break;
		}

		if (i + sz < N) {
			tot -= A[i].F;
			tot += A[i+sz].F;
			updBIT(0, A[i].S, -A[i].F);
			updBIT(1, A[i].S, -1);
			updBIT(0, A[i+sz].S, A[i+sz].F);
			updBIT(1, A[i+sz].S, 1);
		}
	}

	FOR(i,lsti,lsti+sz) {
		updBIT(0, A[i].S, -A[i].F);
		updBIT(1, A[i].S, -1);
	}
	return g;

}


void solve() {
	ri(N); lri(K);
	FOR(i,0,N) ri(A[i].F);
	FOR(i,0,N) A[i].F -= i;
	compress();


	int lo = 1, hi = N;
	while(lo < hi) {
		int mi = lo + (hi - lo + 1) / 2;
		if (valid(mi)) 
			lo = mi;
		else
			hi = mi - 1;
	}
	cout << lo << endl;
}


int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}
