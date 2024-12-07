#include <bits/stdc++.h>
using namespace std;

struct Team {
    string uname, name;
    int num, p;
    bool operator <(Team& a) {
        if (this->num == a.num) return this->p < a.p;
        return this->num > a.num;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, K; cin >> n >> K;
    vector<Team> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].uname >> v[i].name >> v[i].num >> v[i].p;
    }
    sort(v.begin(), v.end());
    unordered_set<string> st;
    for (int i = 0; i < K; i++) {
        if (st.find(v[i].uname) != st.end()) {
            K++; continue;
        }
        cout << v[i].name << '\n';
        st.insert(v[i].uname);
    }
}
