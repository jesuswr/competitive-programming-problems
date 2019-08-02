#include <iostream>

using namespace std;

int main(){
	long long h,l;
	scanf("%lld %lld", &h, &l);
	long long div = 2*h;
	h = h*h;
	l = l*l;
	double ans = (double) (l-h)/div;
	printf("%.15lf\n", ans);
}
