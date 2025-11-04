#include <bits/stdc++.h>
using namespace std;

int arr[26] = {3, 2, 1, 2, 4, 3, 1, 3, 1, 1, 3, 1, 3, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N, M; cin >> N >> M;
    string a, b; cin >> a >> b;
    vector<int> v; v.reserve(N + M);

    int l = 0, r = 0;
    while (l < N && r < M) {
        v.push_back(arr[a[l++] - 'A']);
        v.push_back(arr[b[r++] - 'A']);
    }
    while (l < N) v.push_back(arr[a[l++] - 'A']);
    while (r < M) v.push_back(arr[b[r++] - 'A']);

    while (v.size() > 2) {
        vector<int> tmp; tmp.reserve(v.size());
        for (int i = 0; i < (int)v.size() - 1; i++) {
            tmp.push_back((v[i] + v[i + 1]) % 10);
        }
        v = std::move(tmp);
    }
    if (v[0]) cout << v[0];
    cout << v[1] << '%';
}