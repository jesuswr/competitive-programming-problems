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
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM
char c[205];
char c2[205];
queue<int> q1, q2;

int main()
{
	int b,w,n;
	b = w = 0;
	ri(n);
	scanf("%s",c);
	FOR(i,0,n) c2[i] = c[i];

	FOR(i,0,n-1){
		if ( c[i] == 'W' ){
			q1.push(i+1);
			c[i] = 'B';
			if ( c[i+1] == 'W' ) c[i+1] = 'B';
			else c[i+1] = 'W';
		}
	}
	FOR(i,0,n-1){
		if ( c2[i] == 'B' ){
			q2.push(i+1);
			c2[i] = 'W';
			if ( c2[i+1] == 'W' ) c2[i+1] = 'B';
			else c2[i+1] = 'W';
		}
	}
	int w1, w2, b1, b2;
	w1 = w2 = b1 = b2 = 0;
	FOR(i,0,n){
		if ( c[i] == 'W' ) w1++;
		if ( c[i] == 'B' ) b1++;
		if ( c2[i] == 'W' ) w2++;
		if ( c2[i] == 'B' ) b2++;
	}
	int aux;
	if ( b1 == 0 || w1 == 0 ){
		aux = q1.size();
		printf("%d\n", aux);
		while ( !q1.empty() ){
			aux = q1.front();
			q1.pop();
			printf("%d ", aux);
		}
	}
	else if ( b2 == 0 || w2 == 0 ){
		aux = q2.size();
		printf("%d\n", aux);
		while ( !q2.empty() ){
			aux = q2.front();
			q2.pop();
			printf("%d ", aux);
		}
	}
	else printf("-1\n");
	return 0;
}