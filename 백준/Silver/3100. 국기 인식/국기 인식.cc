#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    set<char> st;
    vector<string> v(6);
    for (auto& s : v) {
        cin >> s;
        for (auto& c : s) {
            st.insert(c);
        }
    }
    vector<char> a(st.begin(), st.end());
    int mn = INT_MAX;

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            for (int k = 0; k < a.size(); k++) {
                if (i == k || j == k) continue;
                int sum = 0;
                for (int l = 0; l < 2; l++) {
                    sum += 9 - count(v[l].begin(), v[l].end(), a[i]);
                    sum += 9 - count(v[5 - l].begin(), v[5 - l].end(), a[j]);
                }
                for (int l = 2; l < 4; l++) {
                    sum += 9 - count(v[l].begin(), v[l].end(), a[k]);
                }
                mn = min(sum, mn);

                sum = 0;

                for (int l = 0; l < 3; l++) {
                    for (int m = 0; m < 6; m++) {
                        sum += v[m][l] != a[i];
                        sum += v[m][8 - l] != a[j];
                    }
                }
                for (int l = 3; l < 6; l++) {
                    for (int m = 0; m < 6; m++) {
                        sum += v[m][l] != a[k];
                    }
                }
                mn = min(sum, mn);
            }
        }
    }

    if (a.size() == 1) cout << 18;
    else cout << mn;
}

