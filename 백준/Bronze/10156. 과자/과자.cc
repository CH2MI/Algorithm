#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int K, N, M;
    cin >> K >> N >> M;

    int val = K * N - M;
    if (val > 0) cout << val;
    else cout << 0;
}