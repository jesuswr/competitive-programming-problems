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

#include <cmath>
#define PI 3.14159265358979323846264338327950288

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM
long double f(long double ang, long double side1, long double side2){
	return max(cos(ang)*side1, cos(ang)*side2);

}

int main(){
	int t;
	ri(t);
	while(t--){
		int n;
		scanf("%d", &n);
		n = 2*n;
		long double angle = PI/n;
		
		if ( n & 2 ){
			long double sd1 = 1/tan(angle)/2, sd2 = 1/sin(angle)/2;
			long double low = 0, high = angle/2;
			int it = 80;
			while(it--){
				long double a = low + (high-low)/3;
				long double b = low + 2*(high-low)/3;
				if ( f(a, sd1, sd2) > f(b,sd1,sd2) ){
					low = a;
				}
				else{
					high = b;
				}
			}
			printf("%.9Lf\n", 2*f(low,sd1,sd2));
		}
		else{
			printf("%.9Lf\n", 1.0/tan(angle));
		}
	}
	return 0;
}