#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;

    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            if (j > N - (i + j)) break;
            if (i + j <= N - (i + j)) continue;
            cnt++;
        }
    }

    cout << cnt;
}