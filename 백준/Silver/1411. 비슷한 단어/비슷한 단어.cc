#include <bits/stdc++.h>
using namespace std;

vector<int> convert(string& a) {
    vector<int> alpha(26, -1);
    int cnt = 0;

    vector<int> ans(a.size());

    for (int i = 0; i < (int)a.size(); i++) {
        if (alpha[a[i] - 'a'] == -1) {
            alpha[a[i] - 'a'] = cnt++;
        }
        ans[i] = alpha[a[i] - 'a'];
    }

    return ans;
}

int check(string& A, string& B) {

    vector<int> a = convert(A), b = convert(B);

    return a == b;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;
    vector<string> v(N);
    for (auto& s : v) cin >> s;

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            cnt += check(v[i], v[j]);
        }
    }

    cout << cnt;
}