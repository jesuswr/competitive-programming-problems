#include <iostream>
using namespace std;
 
int main() {
	
	int N, M;
	while(cin >> N >> M, N > 0 || M > 0){
		if (N > M) printf("0.000000\n");
		else printf("%.6lF\n", 1.0 * (M-N+1) / (M+1));
	}
 
	return 0;
} 