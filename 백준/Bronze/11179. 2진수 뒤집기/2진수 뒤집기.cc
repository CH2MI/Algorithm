#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    string s;
    while (N > 0) {
        s += N % 2 + '0';
        N /= 2;
    }
    cout << stoi(s, 0, 2);
}