#include <bits/stdc++.h>
using namespace std;
 
constexpr int MAX = 1000000;
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
 
    vector<int> nums(MAX + 1);
    vector<int> v;
    v.reserve(MAX);
 
    for (int i = 2; i * i <= MAX; i++) {
        if (nums[i]) continue;
 
        for (int j = i + i; j <= MAX; j += i) nums[j] = 1;
    }
 
    for (int i = 2; i <= MAX; i++)
        if (!nums[i]) v.push_back(i);
 
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        auto itr1 = lower_bound(v.begin(), v.end(), a);
        auto itr2 = upper_bound(v.begin(), v.end(), b);
 
        if (itr1 == itr2 || (itr2 - itr1) % 2 == 0) cout << -1 << '\n';
        else {
            int len = itr2 - itr1;
            cout << *(itr1 + len / 2) << '\n';
        }
        
    }
}
