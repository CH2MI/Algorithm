#include <bits/stdc++.h>
using namespace std;

bool win(array<int, 4> a) {
    if (a[0] == a[1]) {
        if (a[2] != a[3]) return 1;
            return a[0] > a[2];
    }
    if (a[2] == a[3]) return 0;
    return (a[0] + a[1]) % 10 > (a[2] + a[3]) % 10;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B; cin >> A >> B;

    vector<int> v(10, 2);
    --v[A - 1], --v[B - 1];

    int sum = 0, cnt = 0;
    for (int i = 0; i < 10; i++) {
        if (!v[i]) continue;
        --v[i];
        for (int j = i; j < 10; j++) {
            if (!v[j]) continue;
            --v[j];
            sum += (v[i] + 1) * (v[j] + 1);
            if (win({A, B, i + 1, j + 1})) cnt += (v[i] + 1) * (v[j] + 1);
            ++v[j];
        }
        ++v[i];
    }
    cout << fixed;
    cout.precision(3);
    double ans = (double)cnt / (double)sum;
    cout << round(ans * 1000) / 1000;
}
