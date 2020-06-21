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
const int maxN = 1e5+10; // CAMBIAR ESTE

// GJNM
ll A[maxN], B[maxN], C[maxN];
ll CNT[maxN];

int main(){
	int n, q;
	ri(n);
	ll tot_sum = 0;
	FOR(i,0,n){
		rl(A[i]);
		tot_sum += A[i];
		CNT[A[i]]++;
	}
	ri(q);
	FOR(i,0,q){
		rll(B[i], C[i]);
		tot_sum -= CNT[B[i]]*B[i];
		CNT[C[i]] += CNT[B[i]];
		tot_sum += CNT[B[i]]*C[i];
		CNT[B[i]] = 0;
		printf("%lld\n", tot_sum);
	}


	return 0;
}