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

int N;
ll A[MAXN];
int L[MAXN], R[MAXN];

int main(){
	ri(N);
	FOR(i,0,N) lri(A[i]);

	stack<int> st;
	FOR(i,0,N) {
		while(!st.empty() && A[st.top()] >= A[i]) st.pop();
		if (st.empty()) L[i] = 0;
		else L[i] = st.top() + 1;
		st.push(i);
	}
	while(!st.empty()) st.pop();
	ROF(i,N-1,0) {
		while(!st.empty() && A[st.top()] >= A[i]) st.pop();
		if (st.empty()) R[i] = N-1;
		else R[i] = st.top() - 1;
		st.push(i);
	}

	int s = 0, e = 0; 
	ll r = -1;
	FOR(i,0,N) {
		ll curr = (R[i] - L[i] + 1) * A[i];
		// cout << i + 1 << "     " << L[i] + 1 << " " << R[i] + 1 << " : " << curr << endl;
		if (curr > r) {
			s = L[i] + 1;
			e = R[i] + 1;
			r = curr;
		}
		else if (curr == r && L[i] + 1 < s) {
			s = L[i] + 1;
			e = R[i] + 1;
			r = curr;
		}
	}
	printf("%d %d %lld\n", s, e, r);
	return 0;
}
