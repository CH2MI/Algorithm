#include <bits/stdc++.h>
using namespace std;


int N;

int a(vector<int> v) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
                cnt++;
            }
        }
    }

    return cnt;
}

int b(vector<int> v) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (v[j] < v[j + 1]) {
                swap(v[j], v[j + 1]);
                cnt++;
            }
        }
    }

    return cnt;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N;
    vector<int> v(N);
    for (int& i : v) cin >> i;

    cout << min(a(v), b(v) + 1);
}