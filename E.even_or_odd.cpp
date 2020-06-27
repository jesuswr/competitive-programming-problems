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
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM

int main(){
	int n;
	ri(n);
	int aux1 = 1;
	int aux2 = 2;
	int sm1 = 0;
	int sm2 = 0;
	FOR(i,0,n){
		sm1 += aux1++;
		sm2 += aux2++;
	}
	if ( (sm1&1) == 0 && (sm2&1) == 0 ){
		printf("Even\n");
	}
	else if ( (sm1&1) == 1 && (sm2&1) == 1 ){
		printf("Odd\n");
	}
	else
		printf("Either\n");
	return 0;
}