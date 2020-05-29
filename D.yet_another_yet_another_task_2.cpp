#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 2e5; // CAMBIAR ESTE

// GJNM
int A[maxN];

struct SUM_NODE{
	int tot_sum;
	int right_sum;
	int left_sum;
};

SUM_NODE SUM[4*maxN];

SUM_NODE build_sums(int l, int r, int ind){
	if ( l == r ){
		return SUM[ind] = {A[l], max(A[l],0), max(A[l],0)};
	}

	int mid = (l+r)/2;
	SUM_NODE left = build_sums(l, mid, 2*ind+1);
	SUM_NODE right = build_sums(mid+1, r, 2*ind+2);

	SUM[ind].tot_sum = left.tot_sum + right.tot_sum;
	SUM[ind].right_sum = max(right.right_sum, left.right_sum + right.tot_sum);
	SUM[ind].left_sum = max(left.left_sum, left.tot_sum + right.left_sum);
	return SUM[ind];
}

SUM_NODE ret_sum(int l, int r, int ql, int qr, int ind){
	if ( l > qr || r < ql )
		return {-INF, -INF, -INF};
	if ( l >= ql && r <= qr )
		return SUM[ind];

	int mid = (l+r)/2;
	SUM_NODE left = ret_sum(l,mid,ql,qr,2*ind+1);
	SUM_NODE right = ret_sum(mid+1,r,ql,qr,2*ind+2);

	if ( right.tot_sum == -INF )
		return left;
	if ( left.tot_sum == -INF )
		return right;

	SUM_NODE ret;
	ret.tot_sum = left.tot_sum + right.tot_sum;
	ret.right_sum = max(right.right_sum, left.right_sum + right.tot_sum);
	ret.left_sum = max(left.left_sum, left.tot_sum + right.left_sum);
	return ret;
}

int L[maxN], R[maxN];

int main(){
	int n;
	ri(n);
	FOR(i,0,n){
		ri(A[i]);
	}
	build_sums(0, n-1, 0);
	int ans = 0;

	stack <int> greater;
	FOR(i,0,n){
		while( !greater.empty() && A[greater.top()] <= A[i] )
			greater.pop();
		if ( greater.empty() )
			L[i] = 0;
		else
			L[i] = greater.top()+1;
		greater.push(i);
	}

	while( !greater.empty() )
		greater.pop();

	ROF(i,n-1,-1){
		while( !greater.empty() && A[greater.top()] <= A[i] )
			greater.pop();
		if ( greater.empty() )
			R[i] = n-1;
		else
			R[i] = greater.top()-1;
		greater.push(i);
	}


	FOR(i,0,n){
		int pos_ans = 0;
		if ( L[i] != i )
			pos_ans += ret_sum(0,n-1,L[i],i-1,0).right_sum;
		if ( R[i] != i )
			pos_ans += ret_sum(0,n-1,i+1,R[i],0).left_sum;
		ans = max(ans, pos_ans);
	}
	printf("%d\n", ans);
	return 0;
}