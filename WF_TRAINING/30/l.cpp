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
const int MAXN = 2e5+10;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}


int N, M, K, A[MAXN], B[MAXN], IND[MAXN], NEED_DEL[MAXN];

struct STN{
	int sm;
    void merge(STN& L, STN& R) {
		sm = L.sm + R.sm;
	}
    void operator=(int a) {
		sm = (a != 0);
	}
};
STN ST[4*MAXN];
void STB(int id = 1, int l = 0, int r = N){
    if(r - l < 2){
        ST[id] = A[l];
        return;
    }
    int m = (l+r)>>1, L = id<<1, R = L|1;
    STB(L, l, m); STB(R, m, r);
    ST[id].merge(ST[L], ST[R]);
}
STN STQ(int x, int y, int id = 1, int l = 0, int r = N){
    if(x == l && y == r) return ST[id];
    int m = (l+r)>>1, L = id<<1, R = L|1;
    if(x >= m) return STQ(x, y, R, m, r);
    if(y <= m) return STQ(x, y, L, l, m);
    STN res, ln = STQ(x, m, L, l, m), rn = STQ(m, y, R, m, r);
    return res.merge(ln, rn), res;
}
void STU(int p, int x, int id = 1, int l = 0, int r = N){
    if(r - l < 2){
        ST[id] = x;
        return;
    }
    int m = (l+r)>>1, L = id<<1, R = L|1;
    if(p < m) STU(p, x, L, l, m);
    else STU(p, x, R, m, r);
    ST[id].merge(ST[L], ST[R]);
}

set<int> inds;

int getBigLeft(int i) {
	auto it = inds.upper_bound(i);
	--it;
	return *it + 1;
}

int getBigRight(int i) {
	auto it = inds.upper_bound(i);
	return *it - 1;
}

bool check_order() {
	vi a;
	FOR(i,1,N-1) if (!NEED_DEL[A[i]]) a.pb(A[i]);
	FOR(i,0,M) if (a[i] != B[i]) return false;
	return true;
}

void solve() {
	rii(N,M); ri(K);
	FOR(i,1,N+1) NEED_DEL[i] = 1;

	FOR(i,1,N+1) ri(A[i]);
	FOR(i,1,N+1) IND[A[i]] = i;
	A[0] = A[N+1] = INF;
	N += 2;

	FOR(i,0,M) ri(B[i]);
	FOR(i,0,M) NEED_DEL[B[i]] = 0;

	multiset<int> available;
	FOR(i,0,K) {
		int l; ri(l);
		available.insert(l);
	}

	STB();
	inds.clear();
	inds.insert(0);
	inds.insert(N-1);
	for(int del = N-2; del >= 1; del--) {
		if (NEED_DEL[del]) {
			int ind = IND[del];


			int lft = getBigLeft(ind), rgt = getBigRight(ind);
			int len = STQ(lft, rgt+1).sm;
			// cout << del << " " << lft << " " << rgt << " " << len << endl;

			auto it = available.upper_bound(len);
			if (it == available.begin()) {
				cout << "NO" << endl;
				return;
			}
			it--;
			if(it == available.end()) {
				cout << "NO" << endl;
				return;
			}

			available.erase(it);

			STU(ind, 0);
		}
		else {
			int ind = IND[del];
			inds.insert(ind);

		}
	}

	// just in case
	if (check_order()) cout << "YES" << endl;
	else cout << "NO" << endl;
}


int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}
