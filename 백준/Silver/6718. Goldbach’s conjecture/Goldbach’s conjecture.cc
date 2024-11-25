#include <iostream>
#include <set>
#include <vector>
#define MAX 40000
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<bool> check(MAX, false);
    set<int> prime;

    for (int i = 2; i <= MAX; i++) {
        if (check[i]) continue;
        prime.insert(i);

        for (int j = i + i; j <= MAX; j += i) {
            check[j] = true;
        }
    }

    while (1) {
        int n; cin >> n;
        if (!n) break;

        int cnt = 0;
        for (auto i : prime) {
            if (i > n) break;
            if (prime.find(n - i) != prime.end()) cnt++;
        }
        cout << (cnt + 1) / 2 << '\n';
    }

}