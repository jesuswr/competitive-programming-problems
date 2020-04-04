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
const int maxN = 101; // CAMBIAR ESTE

// GJNM
int row[maxN][maxN], col[maxN][maxN];
bool ROW[maxN], COL[maxN];

int main(){
	int t, t2;
	t = 1;
	ri(t2);

	while(t<=t2){
		int n;
		int num;
		ri(n);

		int cnt = 0;
		int rowsR = 0;
		int colsR = 0;

		FOR(i,0,n){
			FOR(j,0,n){
				ri(num);

				if ( i == j )
					cnt += num;

				if ( col[j][num] == t && !COL[j] ){
					colsR++;
					COL[j] = true;
				}
				else
					col[j][num] = t;

				if ( row[i][num] == t && !ROW[i] ){
					rowsR++;
					ROW[i] = true;
				}
				else
					row[i][num] = t;
			}
		}

		printf("Case #%d: %d %d %d\n", t++, cnt, rowsR, colsR );

		FOR(i,0,maxN){
			ROW[i] = false;
			COL[i] = false;
		}
	}

	return 0;
}