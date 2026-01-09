#include <bits/stdc++.h>
using namespace std;

int cal(int N) {
    unordered_set<long long> st;

    if (4 <= N) st.insert(4);
    if (7 <= N) st.insert(7);

    while (1) {
        unordered_set<long long> tmp;
        for (auto i : st) {
            if (i * 10 + 4 <= N) tmp.insert(i * 10 + 4);
            if (i * 10 + 7 <= N) tmp.insert(i * 10 + 7);
            tmp.insert(i);
        }

        if (st.size() == tmp.size()) break;
        st = move(tmp);
    }

    return st.size();
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    #ifdef LOCAL_DEBUG
        freopen("input.txt", "r", stdin);
    #endif

    int A, B; cin >> A >> B;

    cout << cal(B) - cal(A - 1);
}
