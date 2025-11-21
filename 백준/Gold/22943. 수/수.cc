#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    vector<int> is_prime(100000, 1), prime;

    for (int i = 2; i < 100000; i++) {
        if (!is_prime[i]) continue;
        prime.push_back(i);

        for (int j = i + i; j < 100000; j += i) is_prime[j] = 0;
    }

    int K, M; cin >> K >> M;
    int mx = pow(10, K);
    int mn = pow(10, K - 1) - 1;

    unordered_set<int> us;

    for (int i = 0; i < (int)prime.size(); i++) {
        for (int j = i + 1; j < (int)prime.size(); j++) {

            int sum = prime[i] + prime[j];
            if (mn < sum && sum < mx) {
                vector<int> cnt(10);
                while (sum) {
                    cnt[sum % 10]++;
                    sum /= 10;
                }

                if (*max_element(cnt.begin(), cnt.end()) < 2) us.insert(prime[i] + prime[j]);
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < (int)prime.size(); i++) {
        for (int j = i; j < (int)prime.size(); j++) {
            if (prime[i] == M || prime[j] == M) continue;
            long long mul = (long long)prime[i] * prime[j];
            while (mul < mx) {
                cnt += us.find(mul) != us.end();
                mul *= M;
            }
        }
    }
    cout << cnt;
}