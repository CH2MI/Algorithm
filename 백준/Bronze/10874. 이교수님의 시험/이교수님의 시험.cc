#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        for (int j = 0; j < 10; j++) {
            int t; cin >> t;
            if (j % 5 == t - 1) cnt++;
        }
        if (cnt == 10) cout << i + 1 << '\n';
    }
}