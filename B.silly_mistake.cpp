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

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e5+5; // CAMBIAR ESTE

// GJNM
int n;
int a[maxN];
int vis[(int)1e6+5];
int day[(int)1e6+5];
queue<int> q;
int main()
{
	ri(n);
	FOR(i,0,n) ri(a[i]);
	int e = 0;
	int c = 1;
	int d = 0;
	FOR(i,0,n){
		d++;
		if ( a[i] > 0 ){
			if ( day[a[i]] == c){
				printf("-1\n");
				return 0;
			}
			if ( vis[a[i]] == 1 ) {
				printf("-1\n");
				return 0;
			}
			else{
				vis[a[i]] = 1;
				e++;
			}
		}
		else{
			if ( day[-a[i]] == c){
				printf("-1\n");
				return 0;
			}
			if ( vis[-a[i]] == 0 ){
				printf("-1\n");
				return 0;
			}
			else{
				vis[-a[i]] = 0;
				e--;
				day[-a[i]] = c;;
			}
		}
		if ( e == 0 ){
			c++;
			q.push(d);
			d = 0;
		}
	}
	if ( e != 0 ) printf("-1\n");
	else{
		printf("%d\n",(int)q.size() );
		while(!q.empty()){
			printf("%d ",q.front() );
			q.pop();
		}
		printf("\n");
	}
	return 0;
}