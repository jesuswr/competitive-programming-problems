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
int R, C, A, B;
int As[maxN], Bs[maxN];

char M[500][500];

int main(){
	rii(R, C), rii(A, B);
	FOR(i,0,A)
		ri(As[i]);
	FOR(i,0,B)
		ri(Bs[i]);

	char c1 = 'B', c2 = 'W';
	int curr_row = 0;
	FOR(i,0,A){
		FOR(j,0,As[i]){
			M[curr_row+j][0] = c1;
		}
		swap(c1,c2);
		curr_row += As[i];
	}
	FOR(i,0,R){
		int curr_col = 0;
		char c1 = M[i][0];
		char c2 = (c1 == 'W' ? 'B' : 'W');
		FOR(j,0,B){
			FOR(c,0,Bs[j]){
				M[i][curr_col + c] = c1;
			}
			swap(c1,c2);
			curr_col += Bs[j];
		}
	}


	FOR(i,0,R){
		FOR(j,0,C){
			printf("%c", M[i][j]);
		}
		printf("\n");
	}

	return 0;

}