#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    vector<pair<int, int>> v(8);
    for (int i = 0; i < 8; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end(), greater<>());
    int sum = 0;
    vector<int> answer(5);
    for (int i = 0; i < 5; i++) {
        sum += v[i].first;
        answer[i] = v[i].second + 1;
    }
    sort(answer.begin(), answer.end());
    cout << sum << '\n';
    for (auto i : answer) cout << i << ' ';
}