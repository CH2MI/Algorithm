#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    vector<long long> v(N);

    for (auto& i : v) cin >> i;

    sort(v.begin(), v.end());

    auto sum = accumulate(v.begin(), v.end(), 0ll);

    long long cnt = 0;

    // 어떤 원소가 제일 큰 값일 때
    for (int i = 0; i < N - 1; i++) {
        auto tmp = sum - (v.back() * 2) - v[i]; // 찾을 값
        auto itr1 = lower_bound(v.begin() + i + 1, v.end() - 1, tmp);
        auto itr2 = upper_bound(v.begin() + i + 1, v.end() - 1, tmp);
        cnt += itr2 - itr1;
    }

    // 어떤 원소가 두번째로 큰 값일 때
    for (int i = 0; i < N - 2; i++) {
        auto tmp = sum - v.back() - v[i];
        cnt += tmp == v[N - 2] * 2;
    }

    // 어떤 원소가 세번째로 큰 값일 때
    auto tmp = sum - v[N - 1] - v[N - 2];
    cnt += tmp == v[N - 3] * 2;
    cout << cnt;
}