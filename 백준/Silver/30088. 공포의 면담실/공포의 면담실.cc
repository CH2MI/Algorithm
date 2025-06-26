#include <bits/stdc++.h>
using namespace std;

vector<int> level;
vector<vector<int>> v;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    vector<long long> v(N);
    for (int i = 0; i < N; i++) {
        int n; cin >> n;
        for (int j = 0; j < n; j++) {
            int t; cin >> t;
            v[i] += t;
        }
    }

    sort(v.begin(), v.end());
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum = sum + (N - i) * v[i];
    }
    cout << sum;

}