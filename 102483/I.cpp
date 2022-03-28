#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    double ans = 1;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        if (i + 1 < a[i]) {
            printf("-1\n");
            return 0;
        }
        ans = min(ans, (1.0 * a[i]) / (i + 1));
    }
    printf("%.8lF\n", ans);
    return 0;
}