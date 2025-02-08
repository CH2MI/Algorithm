#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> fibo({1, 1});
    while (fibo[fibo.size() - 2] + fibo[fibo.size() - 1] <= 3000000) fibo.push_back(fibo[fibo.size() - 2] + fibo[fibo.size() - 1]);

    vector<int> v(3000001);

    for (int i = 1; i < 3000001; i++) {
        vector<int> t(fibo.size());
        for (int j : fibo) {
            if (i - j < 0) break;
            t[v[i - j]] = 1;
        }
        for (int j = 0; j < fibo.size(); j++) {
            if (!t[j]) {
                v[i] = j;
                break;
            }
        }
    }

    int N; cin >> N;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int p; cin >> p;
        sum ^= v[p];
    }
    if (sum) cout << "koosaga";
    else cout << "cubelover";
}