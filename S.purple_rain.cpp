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
char C[maxN];
int B[maxN], A[maxN];

int main(){
	scanf("%s", C);
	int n = strlen(C);
	FOR(i,0,n){
		B[i] = ( C[i] == 'B' ? 1 : -1 );
		A[i] = -B[i];
	}
	ROF(i,n-2,-1){
		B[i] = max(B[i], B[i] + B[i+1]);
		A[i] = max(A[i], A[i] + A[i+1]);
	}
	int mx = -1;
	FOR(i,0,n){
		mx = max(mx, max(B[i],A[i]));
	}
	FOR(i,0,n){
		if ( A[i] == mx ){
			int sm = 1;
			int ind = i;
			while(sm < mx){
				ind++;
				sm += (C[ind] == 'R' ? 1 : -1);
			}
			printf("%d %d\n",i+1, ind+1 );
			break;
		}
		else if ( B[i] == mx ){
			int sm = 1;
			int ind = i;
			while(sm < mx){
				ind++;
				sm += (C[ind] == 'B' ? 1 : -1);
			}
			printf("%d %d\n",i+1, ind +1);
			break;
		}
	}
	return 0;
}