#include <iostream>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, h; cin >> n >> h;
        int mx1 = 0, mx2 = 0;
        while (n--) {
            int a; cin >> a;
            if (a > mx1) {
                mx2 = mx1;
                mx1 = a;
            }
            else if (a > mx2) {
                mx2 = a;
            }
        }
        int ans = 2 * (h / (mx1 + mx2));
        h %= (mx1 + mx2);
        if (h == 0) {
            cout << ans << endl;
        }
        else if (h <= mx1) {
            cout << ans + 1 << endl;
        }
        else {
            cout << ans + 2 << endl;
        }
    }
    return 0;
}