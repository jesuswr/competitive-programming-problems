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
long double P[10];

long double f(int ind){
	long double num = 3.5;
	FOR(i,0,6){
		if ( i == ind )
			continue;
		num -= P[i]*(i+1);
	}
	num /= P[ind];
	return num;
}

int main(){
	FOR(i,0,6)
		scanf("%Lf", P+i);

	long double mx = 1e4;
	FOR(i,0,6){
		if ( P[i] > 0 ){
			mx = min(mx, abs((i+1)-f(i)));
		}
	}
	printf("%.3Lf\n", mx);
	return 0;
}