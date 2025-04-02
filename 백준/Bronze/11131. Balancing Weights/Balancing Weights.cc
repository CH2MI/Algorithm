#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        int sum = 0;
        for (int i = 0; i < N; i++) {
            int a; cin >> a;
            sum += a;
        }

        if (sum < 0) cout << "Left\n";
        else if (sum > 0) cout << "Right\n";
        else cout << "Equilibrium\n";
    }
}