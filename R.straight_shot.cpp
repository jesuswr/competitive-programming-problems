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
long double L[200], R[200], V[200]; 

int main(){
	int n;
	long double x, v;
	scanf("%d %Lf %Lf", &n, &x, &v);
	FOR(i,0,n)
		scanf("%Lf %Lf %Lf", L+i, R+i, V+i);

	long double num = 0, den = x;
	FOR(i,0,n)
		num += (R[i] - L[i])*V[i];

	long double vy = num/den;
	long double ans = sqrt(v*v - vy*vy);
	long double min_time = x/v;
	long double time = x/ans;
	if ( time <= 2*min_time )
		printf("%.3Lf\n", time);
	else
		printf("Too hard\n");
	

	return 0;
}