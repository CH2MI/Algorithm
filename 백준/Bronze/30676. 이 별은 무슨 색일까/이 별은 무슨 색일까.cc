#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;
    if (N < 425) cout << "Violet";
    else if (N < 450) cout << "Indigo";
    else if (N < 495) cout << "Blue";
    else if (N < 570) cout << "Green";
    else if (N < 590) cout << "Yellow";
    else if (N < 620) cout << "Orange";
    else cout << "Red";
}
