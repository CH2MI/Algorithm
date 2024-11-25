#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    if (N + M - 1 > K) {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << i + 1 + j << ' ';
        }
        cout << '\n';
    }
}