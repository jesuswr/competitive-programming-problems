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
const int MAXN = 5e5+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int N, M;
int A[MAXN];

bool valid(int k) {
	int aux = M;
	priority_queue<int> pq;
	FOR(i,0,k) pq.push(-A[i]);
	FOR(i,k+1,N) pq.push(-A[i]);
	pq.push(-(M+1));
	pq.push(-(M+1));

	FOR(_,0,k-1) {
		aux += pq.top();
		pq.pop();
	}

	int op1 = 0;
	FOR(_,0,2) {
		op1 -= pq.top();
		pq.pop();
		if (k == 0) break;
	}
	int op2 = A[k];

	aux -= min(op1, op2);
	
	return aux >= 0;
}

void solve(){
	rii(N,M);
	FOR(i,0,N) ri(A[i]);
	int lo = -1, hi = N-1;
	while(lo < hi) {
		int mi = lo + (hi - lo + 1) / 2;
		if (valid(mi)) lo = mi;
		else hi = mi-1;
	}
	cout << N - lo << endl;	

}



int main(){
	int t; ri(t);
	while(t--) solve();
	return 0;
}
