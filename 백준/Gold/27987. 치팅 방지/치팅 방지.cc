#include <bits/stdc++.h>
using namespace std;


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    vector<array<int, 2>> v(N);

    for (int i = 0; i < N; i++) {
        int K; cin >> K;
        v[i] = {K, i + 1};
    }
    sort(v.begin(), v.end());

    auto itr1 = upper_bound(v.begin(), v.end(), array<int, 2>{v.back()[0], 0});

    int interval = 0;
    int i = 0;

    string s;
    for (auto itr2 = itr1; itr2 != v.end(); itr2++) {
        s += to_string((*itr2)[1]) + ' ';
    }

    int cnt = v.back()[0];
    int sum = accumulate(v.begin(), itr1, 0, [](int a, const auto& arr) {
        return a + arr[0];
    }) + cnt;


    if (itr1 != v.begin()) {
        interval = (sum - cnt) / ((*itr1)[0] - 1) + 1;
        if (interval == 1) interval++;

        // 남은 횟수, 값
        priority_queue<array<int, 2>> pq;

        // 최근에 사용한 순서, 남은 횟수, 값
        queue<array<int, 3>> q;
        for (auto itr2 = v.begin(); itr2 != itr1; itr2++) {
            pq.push({(*itr2)[0], (*itr2)[1]});
        }

        for (; i < sum && pq.size() + q.size() != 0; i++) {
            if (!q.empty() && i + q.front()[0] >= interval) {
                pq.push({q.front()[1], q.front()[2]});
                q.pop();
            }
            if (i % interval || !cnt) {
                auto [a, b] = pq.top(); pq.pop();
                cout << b << ' ';
                if (--a) q.push({-i, a, b});
            }
            else {
                cout << s;
                --cnt;
            }
        }
    }

    for (; i < sum; i++) cout << s;
}