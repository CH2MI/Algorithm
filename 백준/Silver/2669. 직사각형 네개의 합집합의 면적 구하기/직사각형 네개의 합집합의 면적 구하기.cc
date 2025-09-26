#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<vector<int>> v(101, vector<int>(101));
    for (int i = 0;  i < 4; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

        for (int x = x1; x < x2; x++) {
            for (int y = y1; y < y2; y++) {
                v[x][y] = 1;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < 101; i++) {
        sum += accumulate(v[i].begin(), v[i].end(), 0);
    }
    cout << sum;
}
