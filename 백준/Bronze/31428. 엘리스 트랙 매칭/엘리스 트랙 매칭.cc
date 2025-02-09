#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<char> v(N);
    for (auto& i : v) cin >> i;
    char t; cin >> t;
    cout << count(v.begin(), v.end(), t);
}

