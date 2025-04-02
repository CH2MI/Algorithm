#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    array<int, 26> wrong{}, right{};
    int sum = 0;
    while (true) {
        int t; cin >> t;
        if (t == -1) break;
        char n; string r;
        cin >> n >> r;

        if (r == "wrong") wrong[n - 'A']++;
        else {
            sum += t + 20 * wrong[n - 'A'];
            right[n - 'A'] += 1;
        }
    }
    cout << accumulate(right.begin(), right.end(), 0) << ' ' << sum;

}