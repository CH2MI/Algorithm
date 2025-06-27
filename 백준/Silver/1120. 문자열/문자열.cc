#include <bits/stdc++.h>
using namespace std;

int cal(string a, string b) {
    int cnt = b.size() - a.size();
    for (int i = 0; i < a.size(); i++) {
        cnt += a[i] != b[i];
    }
    return cnt;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string A, B; cin >> A >> B;
    if (A.size() > B.size()) swap(A, B);

    int mn = INT_MAX;
    for (int i = 0; i <= B.size() - A.size(); i++) {
        string t = B.substr(i, A.size());
        mn = min(mn, cal(A, t));
    }
    cout << mn;
}