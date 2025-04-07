#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        string s = to_string(i);
        for (auto c : s) {
            if ((c - '0') % 3 == 0 && c != '0') cnt++;
        }
    }
    cout << cnt;

}