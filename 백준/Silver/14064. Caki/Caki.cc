#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    deque<int> dq(n);
    vector<int> v(n);
    for (int i = 1; i <= n; i++) {
        dq[i - 1] = i;
    }
    for (int i = 0; i < k; i++) {
        int t; cin >> t;
        int l = find(dq.begin(), dq.end(), t) - dq.begin();
        if (l == 0) {
            dq.push_back(dq.front());
            dq.pop_front();
            v[dq.back() - 1]++;
            swap(dq[dq.size() - 2], dq[dq.size() - 1]);
        }
        else swap(dq[l], dq[l - 1]);
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[dq[i] - 1] = i;
    }
    sort(dq.begin(), dq.end(), [&](int a, int b) {
       if (v[a - 1] == v[b - 1]) return ans[a - 1] < ans[b - 1];
        return v[a - 1] > v[b - 1];
    });

    for (int i = 0, cnt = 0; i < n && cnt < 6; i++, cnt++) {
        cout << dq[i] << ' ';
    }
}