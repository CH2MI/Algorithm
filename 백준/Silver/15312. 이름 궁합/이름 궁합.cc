#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int t[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};

    string a, b; cin >> a >> b;
    vector<int> v;
    int i;
    for (i = 0; i < a.size() && i < b.size(); i++) {
        v.push_back(t[a[i] - 'A']);
        v.push_back(t[b[i] - 'A']);
    }
    for (; i < a.size(); i++) v.push_back(t[a[i] - 'A']);
    for (; i < b.size(); i++) v.push_back(t[b[i] - 'A']);

    while (v.size() > 2) {
        vector<int> c;
        for (int i = 0; i < v.size() - 1; i++) {
            c.push_back((v[i] + v[i + 1]) % 10);
        }
        v = c;
    }
    cout << v[0] << v[1];

}