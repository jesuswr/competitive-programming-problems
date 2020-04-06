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
class dsu{
	private:
		int *father;
		int *height;
		int n;
	public:
		dsu(int sz){
			father = (int *)malloc( sizeof(int) * sz );
			height = (int *)malloc( sizeof(int) * sz );
			n = sz;
			FOR(i,0,n){
				father[i] = -1;
				height[i] = 0;
			}
		}

		int find(int x){
			if ( father[x] == -1 )
				return x;
			else
				return father[x] = find(father[x]);
		}

		void join(int x, int y){
			x = find(x);
			y = find(y);

			if ( height[x] > height[y] ){
				father[y] = x;
			}
			else{
				father[x] = y;
				if ( height[x] == height[y] )
					height[y]++;
			}
		}

		void show(){
			printf("FATHERS:\n\t");
			FOR(i,0,n)
				printf("%d ", father[i]);
			printf("\n");

			printf("HEIGHT:\n\t");
			FOR(i,0,n)
				printf("%d ", height[i]);
			printf("\n");
		}

		~dsu(){
			free(height);
			free(father);
		}
};

int main(){
	dsu mydsu(5);
	mydsu.show();
	mydsu.join(0,1);
	mydsu.show();
	mydsu.join(2,3);
	mydsu.show();
	mydsu.join(0,2);
	mydsu.show();
	cout << mydsu.find(0) << endl;
	mydsu.show();


	return 0;
}