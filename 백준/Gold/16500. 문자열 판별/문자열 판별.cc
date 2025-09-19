#include <vector>
#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    string s; cin >> s;
    int N; cin >> N;
    vector<string> v(N);
    for (auto& i : v) cin >> i;

    vector<int> dp(s.size() + 1);
    dp[0] = 1;

    for (int i = 0; i < (int)s.size(); i++) {
        for (auto& a : v) {
            int len = (int)a.size();
            if (i + len > (int)s.size()) continue;
            int k = s.substr(i, len) == a;
            dp[i + len] |= k & dp[i];
        }
    }
    cout << dp.back();
}