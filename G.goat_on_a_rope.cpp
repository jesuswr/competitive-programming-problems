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
	double x,y,x1,y1,x2,y2;
	scanf("%lF %lF %lF %lF %lF %lF", &x, &y, &x1, &y1, &x2, &y2);
	double ans;
	if ( x >= min(x1,x2) && x <= max(x1,x2) ){
		ans = min( abs(y1-y) , abs(y2-y) );
	}
	else if ( y >= min(y1,y2) && y <= max(y1,y2) ){
		ans = min( abs(x1-x) , abs(x2-x) );
	}
	else{
		double dist1 = (x1-x)*(x1-x) + (y1-y)*(y1-y);
		double dist2 = (x1-x)*(x1-x) + (y2-y)*(y2-y);
		double dist3 = (x2-x)*(x2-x) + (y2-y)*(y2-y);
		double dist4 = (x2-x)*(x2-x) + (y1-y)*(y1-y);
		ans = sqrt( min( min(dist1,dist2) , min(dist3,dist4)));
	}
	printf("%.3lF\n", ans);
	return 0;
}