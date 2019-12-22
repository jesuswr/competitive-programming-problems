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
#define f first
#define s second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM
char w[200009], w2[200009];

int main()
{
	int n,k;
	rii(n,k);
	scanf("%s",w);
	strcpy(w2,w);
	FOR(i,0,n-k){
		w2[i+k] = w2[i];
	}
	if ( strcmp(w2,w) < 0 ){
		int zi = -1;
		FOR(i,0,k){
			if ( w2[i] != '9' ){
				zi = max( i , zi );
			}
		}
		w2[zi] = (int)(w2[zi]+1);
		w2[zi+k] = w2[zi];
		FOR(i,zi+1,k){
			w2[i] = w2[i+k] = '0';
		}
		FOR(i,0,n-k){
			w2[i+k] = w2[i];
		}
	}
	printf("%d\n", n);
	w2[n] = '\0';
	printf("%s\n", w2);

	return 0;
}