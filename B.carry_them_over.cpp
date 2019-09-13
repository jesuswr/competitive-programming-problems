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
char w1[32];
char w2[32];
int w3[32];

void p ( int a , int b)
{
	FOR(i,a,b+1) printf("%d",w3[i] );
	printf(" ");
}

int main()
{
	while (true)
	{
		scanf("%s %s",w1,w2);
		int s1 = strlen(w1)-1, s2 = strlen(w2)-1;
		if ( s1 == 0 && s2 == 0 && w1[0] == '0' && w2[0] == '0' ) return 0;
		int s3 = max(s2,s1);
		int s3aux = s3;
		int carry = 0;

		while( s1 >= 0 || s2 >=0 )
		{
			if ( s1 == -1 )
			{
				printf("0 + %c\n",w2[s2] );
				w3[s3] = int(w2[s2]-'0') + carry;
				carry = w3[s3]/10;
				w3[s3] %= 10;
				printf("Current: ");
				p(s3,s3aux);
				printf("Carry: %d\n", carry);
				s2--;
				s3--;
			}
			else if ( s2 == -1 )
			{
				printf("%c + 0\n", w1[s1]);
				w3[s3] = int(w1[s1]-'0') + carry;
				carry = w3[s3]/10;
				w3[s3] %= 10;
				printf("Current: ");
				p(s3,s3aux);
				printf("Carry: %d\n", carry);
				s1--;
				s3--;
			}
			else
			{
				printf("%c + %c\n", w1[s1],w2[s2]);
				w3[s3] = int(w2[s2]-'0') + int(w1[s1]-'0') + carry;
				carry = w3[s3]/10;
				w3[s3] %= 10;
				printf("Current: ");
				p(s3,s3aux);
				printf("Carry: %d\n", carry);
				s2--;
				s1--;
				s3--;
			}
		}
	}
	return 0;
}