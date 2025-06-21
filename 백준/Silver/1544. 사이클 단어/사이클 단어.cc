#include <bits/stdc++.h>
using namespace std;

int main() {cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    unordered_set<string> st;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        st.insert(s);
    }

    for (auto itr1 = st.begin(); itr1 != st.end(); itr1++) {
        auto itr2 = itr1;
        for (itr2++; itr2 != st.end();) {
            if (itr1->size() != itr2->size()) {
                itr2++;
                continue;
            }

            int check = 0;
            for (int i = 0; i < itr1->size(); i++) {
                string t = itr2->substr(i) + itr2->substr(0, i);
                if (*itr1 == t) {
                    check = 1;
                    break;
                }
            }

            if (check) {
                auto itr3 = itr2++;
                st.erase(itr3);
            }
            else {
                itr2++;
            }
        }
    }
    cout << st.size();
}