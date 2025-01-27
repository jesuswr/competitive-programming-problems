#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define ri(a) scanf("%d", &a)
#define rii(a, b) ri(a), ri(b)
#define lri(a) scanf("%lld", &a)
#define lrii(a, b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 1e6+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}


pair<int, pair<char,int>> P[] = {
    { 988260, {'L', 180} },
    { 984984, {'H', 143} },
    { 971970, {'L', 179} },
    { 964535, {'H', 142} },
    { 955860, {'L', 178} },
    { 944371, {'H', 141} },
    { 939929, {'L', 177} },
    { 924490, {'H', 140} },
    { 924176, {'L', 176} },
    { 908600, {'L', 175} },
    { 904890, {'H', 139} },
    { 893200, {'L', 174} },
    { 885569, {'H', 138} },
    { 877975, {'L', 173} },
    { 866525, {'H', 137} },
    { 862924, {'L', 172} },
    { 848046, {'L', 171} },
    { 847756, {'H', 136} },
    { 833340, {'L', 170} },
    { 829260, {'H', 135} },
    { 818805, {'L', 169} },
    { 811035, {'H', 134} },
    { 804440, {'L', 168} },
    { 793079, {'H', 133} },
    { 790244, {'L', 167} },
    { 776216, {'L', 166} },
    { 775390, {'H', 132} },
    { 762355, {'L', 165} },
    { 757966, {'H', 131} },
    { 748660, {'L', 164} },
    { 740805, {'H', 130} },
    { 735130, {'L', 163} },
    { 723905, {'H', 129} },
    { 721764, {'L', 162} },
    { 708561, {'L', 161} },
    { 707264, {'H', 128} },
    { 695520, {'L', 160} },
    { 690880, {'H', 127} },
    { 682640, {'L', 159} },
    { 674751, {'H', 126} },
    { 669920, {'L', 158} },
    { 658875, {'H', 125} },
    { 657359, {'L', 157} },
    { 644956, {'L', 156} },
    { 643250, {'H', 124} },
    { 632710, {'L', 155} },
    { 627874, {'H', 123} },
    { 620620, {'L', 154} },
    { 612745, {'H', 122} },
    { 608685, {'L', 153} },
    { 597861, {'H', 121} },
    { 596904, {'L', 152} },
    { 585276, {'L', 151} },
    { 583220, {'H', 120} },
    { 573800, {'L', 150} },
    { 568820, {'H', 119} },
    { 562475, {'L', 149} },
    { 554659, {'H', 118} },
    { 551300, {'L', 148} },
    { 540735, {'H', 117} },
    { 540274, {'L', 147} },
    { 529396, {'L', 146} },
    { 527046, {'H', 116} },
    { 518665, {'L', 145} },
    { 513590, {'H', 115} },
    { 508080, {'L', 144} },
    { 500365, {'H', 114} },
    { 497640, {'L', 143} },
    { 487369, {'H', 113} },
    { 487344, {'L', 142} },
    { 477191, {'L', 141} },
    { 474600, {'H', 112} },
    { 467180, {'L', 140} },
    { 462056, {'H', 111} },
    { 457310, {'L', 139} },
    { 449735, {'H', 110} },
    { 447580, {'L', 138} },
    { 437989, {'L', 137} },
    { 437635, {'H', 109} },
    { 428536, {'L', 136} },
    { 425754, {'H', 108} },
    { 419220, {'L', 135} },
    { 414090, {'H', 107} },
    { 410040, {'L', 134} },
    { 402641, {'H', 106} },
    { 400995, {'L', 133} },
    { 392084, {'L', 132} },
    { 391405, {'H', 105} },
    { 383306, {'L', 131} },
    { 380380, {'H', 104} },
    { 374660, {'L', 130} },
    { 369564, {'H', 103} },
    { 366145, {'L', 129} },
    { 358955, {'H', 102} },
    { 357760, {'L', 128} },
    { 349504, {'L', 127} },
    { 348551, {'H', 101} },
    { 341376, {'L', 126} },
    { 338350, {'H', 100} },
    { 333375, {'L', 125} },
    { 328350, {'H', 99} },
    { 325500, {'L', 124} },
    { 318549, {'H', 98} },
    { 317750, {'L', 123} },
    { 310124, {'L', 122} },
    { 308945, {'H', 97} },
    { 302621, {'L', 121} },
    { 299536, {'H', 96} },
    { 295240, {'L', 120} },
    { 290320, {'H', 95} },
    { 287980, {'L', 119} },
    { 281295, {'H', 94} },
    { 280840, {'L', 118} },
    { 273819, {'L', 117} },
    { 272459, {'H', 93} },
    { 266916, {'L', 116} },
    { 263810, {'H', 92} },
    { 260130, {'L', 115} },
    { 255346, {'H', 91} },
    { 253460, {'L', 114} },
    { 247065, {'H', 90} },
    { 246905, {'L', 113} },
    { 240464, {'L', 112} },
    { 238965, {'H', 89} },
    { 234136, {'L', 111} },
    { 231044, {'H', 88} },
    { 227920, {'L', 110} },
    { 223300, {'H', 87} },
    { 221815, {'L', 109} },
    { 215820, {'L', 108} },
    { 215731, {'H', 86} },
    { 209934, {'L', 107} },
    { 208335, {'H', 85} },
    { 204156, {'L', 106} },
    { 201110, {'H', 84} },
    { 198485, {'L', 105} },
    { 194054, {'H', 83} },
    { 192920, {'L', 104} },
    { 187460, {'L', 103} },
    { 187165, {'H', 82} },
    { 182104, {'L', 102} },
    { 180441, {'H', 81} },
    { 176851, {'L', 101} },
    { 173880, {'H', 80} },
    { 171700, {'L', 100} },
    { 167480, {'H', 79} },
    { 166650, {'L', 99} },
    { 161700, {'L', 98} },
    { 161239, {'H', 78} },
    { 156849, {'L', 97} },
    { 155155, {'H', 77} },
    { 152096, {'L', 96} },
    { 149226, {'H', 76} },
    { 147440, {'L', 95} },
    { 143450, {'H', 75} },
    { 142880, {'L', 94} },
    { 138415, {'L', 93} },
    { 137825, {'H', 74} },
    { 134044, {'L', 92} },
    { 132349, {'H', 73} },
    { 129766, {'L', 91} },
    { 127020, {'H', 72} },
    { 125580, {'L', 90} },
    { 121836, {'H', 71} },
    { 121485, {'L', 89} },
    { 117480, {'L', 88} },
    { 116795, {'H', 70} },
    { 113564, {'L', 87} },
    { 111895, {'H', 69} },
    { 109736, {'L', 86} },
    { 107134, {'H', 68} },
    { 105995, {'L', 85} },
    { 102510, {'H', 67} },
    { 102340, {'L', 84} },
    { 98770, {'L', 83} },
    { 98021, {'H', 66} },
    { 95284, {'L', 82} },
    { 93665, {'H', 65} },
    { 91881, {'L', 81} },
    { 89440, {'H', 64} },
    { 88560, {'L', 80} },
    { 85344, {'H', 63} },
    { 85320, {'L', 79} },
    { 82160, {'L', 78} },
    { 81375, {'H', 62} },
    { 79079, {'L', 77} },
    { 77531, {'H', 61} },
    { 76076, {'L', 76} },
    { 73810, {'H', 60} },
    { 73150, {'L', 75} },
    { 70300, {'L', 74} },
    { 70210, {'H', 59} },
    { 67525, {'L', 73} },
    { 66729, {'H', 58} },
    { 64824, {'L', 72} },
    { 63365, {'H', 57} },
    { 62196, {'L', 71} },
    { 60116, {'H', 56} },
    { 59640, {'L', 70} },
    { 57155, {'L', 69} },
    { 56980, {'H', 55} },
    { 54740, {'L', 68} },
    { 53955, {'H', 54} },
    { 52394, {'L', 67} },
    { 51039, {'H', 53} },
    { 50116, {'L', 66} },
    { 48230, {'H', 52} },
    { 47905, {'L', 65} },
    { 45760, {'L', 64} },
    { 45526, {'H', 51} },
    { 43680, {'L', 63} },
    { 42925, {'H', 50} },
    { 41664, {'L', 62} },
    { 40425, {'H', 49} },
    { 39711, {'L', 61} },
    { 38024, {'H', 48} },
    { 37820, {'L', 60} },
    { 35990, {'L', 59} },
    { 35720, {'H', 47} },
    { 34220, {'L', 58} },
    { 33511, {'H', 46} },
    { 32509, {'L', 57} },
    { 31395, {'H', 45} },
    { 30856, {'L', 56} },
    { 29370, {'H', 44} },
    { 29260, {'L', 55} },
    { 27720, {'L', 54} },
    { 27434, {'H', 43} },
    { 26235, {'L', 53} },
    { 25585, {'H', 42} },
    { 24804, {'L', 52} },
    { 23821, {'H', 41} },
    { 23426, {'L', 51} },
    { 22140, {'H', 40} },
    { 22100, {'L', 50} },
    { 20825, {'L', 49} },
    { 20540, {'H', 39} },
    { 19600, {'L', 48} },
    { 19019, {'H', 38} },
    { 18424, {'L', 47} },
    { 17575, {'H', 37} },
    { 17296, {'L', 46} },
    { 16215, {'L', 45} },
    { 16206, {'H', 36} },
    { 15180, {'L', 44} },
    { 14910, {'H', 35} },
    { 14190, {'L', 43} },
    { 13685, {'H', 34} },
    { 13244, {'L', 42} },
    { 12529, {'H', 33} },
    { 12341, {'L', 41} },
    { 11480, {'L', 40} },
    { 11440, {'H', 32} },
    { 10660, {'L', 39} },
    { 10416, {'H', 31} },
    { 9880, {'L', 38} },
    { 9455, {'H', 30} },
    { 9139, {'L', 37} },
    { 8555, {'H', 29} },
    { 8436, {'L', 36} },
    { 7770, {'L', 35} },
    { 7714, {'H', 28} },
    { 7140, {'L', 34} },
    { 6930, {'H', 27} },
    { 6545, {'L', 33} },
    { 6201, {'H', 26} },
    { 5984, {'L', 32} },
    { 5525, {'H', 25} },
    { 5456, {'L', 31} },
    { 4960, {'L', 30} },
    { 4900, {'H', 24} },
    { 4495, {'L', 29} },
    { 4324, {'H', 23} },
    { 4060, {'L', 28} },
    { 3795, {'H', 22} },
    { 3654, {'L', 27} },
    { 3311, {'H', 21} },
    { 3276, {'L', 26} },
    { 2925, {'L', 25} },
    { 2870, {'H', 20} },
    { 2600, {'L', 24} },
    { 2470, {'H', 19} },
    { 2300, {'L', 23} },
    { 2109, {'H', 18} },
    { 2024, {'L', 22} },
    { 1785, {'H', 17} },
    { 1771, {'L', 21} },
    { 1540, {'L', 20} },
    { 1496, {'H', 16} },
    { 1330, {'L', 19} },
    { 1240, {'H', 15} },
    { 1140, {'L', 18} },
    { 1015, {'H', 14} },
    { 969, {'L', 17} },
    { 819, {'H', 13} },
    { 816, {'L', 16} },
    { 680, {'L', 15} },
    { 650, {'H', 12} },
    { 560, {'L', 14} },
    { 506, {'H', 11} },
    { 455, {'L', 13} },
    { 385, {'H', 10} },
    { 364, {'L', 12} },
    { 286, {'L', 11} },
    { 285, {'H', 9} },
    { 220, {'L', 10} },
    { 204, {'H', 8} },
    { 165, {'L', 9} },
    { 140, {'H', 7} },
    { 120, {'L', 8} },
    { 91, {'H', 6} },
    { 84, {'L', 7} },
    { 56, {'L', 6} },
    { 55, {'H', 5} },
    { 35, {'L', 5} },
    { 30, {'H', 4} },
    { 20, {'L', 4} },
    { 14, {'H', 3} },
    { 10, {'L', 3} },
    { 5, {'H', 2} }
};

// bitset<321> dp[MAXN];
// bitset<321> vist[MAXN];


// bool solve(int c, int i) {
// 	if (c == 0) return true;
// 	if (c < 0 || i >= 320) return false;
// 	if (vist[c][i]) return dp[c][i];
// 	vist[c][i] = true;
// 
// 	dp[c][i] = ((solve(c - P[i].F, i+1) || solve(c, i+1)) ? 1 : 0);
// 	return dp[c][i];
// }

int mn[MAXN];
int par[MAXN];

void solve() {
	mn[0] = 0;
	ROF(i,319,-1) {
		FOR(j,0,P[i].F) {
			if (j+P[i].F < MAXN && mn[j] + 1 <= mn[j+P[i].F]) {
				mn[j+P[i].F] = mn[j] + 1;
				par[j+P[i].F] = i;
			}
		}
	}
}


int main() {
	ms(par, -1);
	ms(mn, INF);

	solve();

	int n, tc = 0;
	ri(n);
	while (n > 0) {
		printf("Case %d:", ++tc);	

		if (mn[n] >= INF) printf(" impossible\n");
		else {
			while (n > 0) {
				printf(" %d%d", P[par[n]].S.S, P[par[n]].S.F);
				n -= P[par[n]].F;
			}

			printf("\n");
		}
		// if (!solve(n, 0)) printf(" impossible\n");
		// else {
		// 	int i = 0;
		// 	while (n > 0) {
		// 		if (solve(n - P[i].F, i+1)) {
		// 			n -= P[i].F;
		// 			printf(" %d%c", P[i].S.S, P[i].S.F);
		// 		}
		// 		i++;
		// 	}

		// 	printf("\n");
		// }


		ri(n);
	}

	




	return 0;
}
