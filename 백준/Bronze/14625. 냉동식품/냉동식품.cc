#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int sh, sm, eh, em, n; cin >> sh >> sm >> eh >> em >> n;

    int s = sh * 60 + sm;
    int e = eh * 60 + em;

    int cnt = 0;
    for (int i = s; i <= e; i++) {
        int nh = i / 60, nm = i % 60;
        cnt += (nh / 10 == n) || (nh % 10 == n) || (nm / 10 == n) || (nm % 10 == n);
    }
    cout << cnt;
}