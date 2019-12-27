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
int arr[maxN+1];

int main()
{
	int ze, on, tw, th;
	rii(ze,on);
	rii(tw,th);
	arr[0] = -13;

	if ( ze && on && tw && th && on - ze > tw - th ){
		arr[1] = 1;
		on--;
	}
	else if ( ze ){
		arr[1] = 0;
		ze--;
	}else if ( on ){
		arr[1] = 1;
		on--;
	}else if ( tw ){
		arr[1] = 2;
		tw--;
	}else{
		arr[1] = 3;
		th--;
	}
	int i = 2;
	while( true ){
		if ( arr[i-1] == 0 ){
			if ( on ){
				on--;
				arr[i] = 1;
			}
			else{
				break;
			}
		}
		else if ( arr[i-1] == 1 ){
			if ( ze ){
				ze--;
				arr[i] = 0;
			}
			else if ( tw ){
				tw--;
				arr[i] = 2;
			}
			else{
				break;
			}
		}
		else if ( arr[i-1] == 2 ){
			if ( on ){
				on--;
				arr[i] = 1;
			}
			else if ( th ){
				th--;
				arr[i] = 3;
			}
			else{
				break;
			}
		}
		else{
			if ( tw ){
				tw--;
				arr[i] = 2;
			}
			else{
				break;
			}
		}
		i++;
	}
	//printf("%d %d %d %d\n", ze,on,tw,th);
	if ( arr[1] == 0 && on){
		arr[0] = 1;
		on--;
	}
	else if ( arr[1] == 1 && tw ){
		arr[0] = 2;
		tw--;
	}
	else if ( arr[1] == 2 && th ){
		arr[0] = 3;
		th--;
	}
	if ( ze || th || tw || on ){
		printf("NO\n");
	}else{
		printf("YES\n");
		int j = 0;
		if ( arr[j] < -0 )
			j++;
		FOR(jj,j,i)
			printf("%d ",arr[jj] );
		printf("\n");
	}
	return 0;
}