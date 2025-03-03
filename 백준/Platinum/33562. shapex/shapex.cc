#include <bits/stdc++.h>
using namespace std;

vector<string> reg(100);

void A(int i, int j, int k) {
    int l = reg[i].size();
    if (l == 0) {
        reg[j] = reg[k] = "";
        return;
    }
    string s1, s2;
    for (int a = 0; a < l / 9 + 1; a++) {
        s1 += "----" + reg[i].substr(a * 9 + 4, 4);
        s2 += reg[i].substr(a * 9, 4) + "----";
        s1 += ":";
        s2 += ":";
    }
    stack<int> st1, st2;

    for (int a = 0; a < l / 9 + 1; a++) {
        if (s1.substr(a * 9, 8) == "--------") {
            st1.push(a);
        }
        if (s2.substr(a * 9, 8) == "--------") {
            st2.push(a);
        }
    }

    for (; !st1.empty(); st1.pop()) s1.erase(s1.begin() + st1.top() * 9, s1.begin() + st1.top() * 9 + 9);
    for (; !st2.empty(); st2.pop()) s2.erase(s2.begin() + st2.top() * 9, s2.begin() + st2.top() * 9 + 9);

    if (!s1.empty()) s1.pop_back();
    if (!s2.empty()) s2.pop_back();
    //cout << s1 << ' ' << s2 << '\n';
    reg[j] = s1; reg[k] = s2;
}

void B(int i, int j, int k) {
    int l = reg[i].size();
    if (l == 0) {
        reg[j] = "";
        return;
    }

    string s;
    for (int a = 0; a < l / 9 + 1; a++) {
        s += reg[i].substr(a * 9 + (4 - k) * 2, k * 2) + reg[i].substr(a * 9, (4 - k) * 2);
        s += ":";
    }

    if (!s.empty()) s.pop_back();
    //cout << s << '\n';
    reg[j] = s;
}

void C(int i, int j, int k) {
    string s1 = reg[i], s2 = reg[j];
    if (s1.size() == 0 || s2.size() == 0) {
        reg[k] = "";
        return;
    }


    s1.push_back(':'); s2.push_back(':');
    while (s1.size() <= 27) s1 += "--------:";
    while (s2.size() <= 27) s2 += "--------:";

    int a = 3;
    for (; a >= 0; a--) {
        int b = 0;
        for (; b < 4 - a; b++) {
            bool f = 1;
            for (int c = 0; c < 4; c++) {
                if (s2.substr(b * 9 + c * 2, 2) == "--") continue;
                if (s1.substr((a + b) * 9 + c * 2, 2) != "--") f = 0;
            }
            if (!f) break;
        }
        if (b != 4 - a) break;
    }

    ++a;
    for (int b = 0; a < 4; a++, b++) {
        for (int c = 0; c < 4; c++) {
            if (s2.substr(b * 9 + c * 2, 2) == "--") continue;
            s1.replace(a * 9 + c * 2, 2, s2.substr(b * 9 + c * 2, 2));
        }
    }

    stack<int> st;
    for (a = 0; a < s1.size() / 9 + 1; a++) {
        if (s1.substr(a * 9, 8) == "--------") {
            st.push(a);
        }
    }
    for (; !st.empty(); st.pop()) s1.erase(s1.begin() + st.top() * 9, s1.begin() + st.top() * 9 + 9);
    s1.pop_back();
    //cout << s1 << '\n';
    reg[k] = s1;
}

void D(int i, int j, char k) {
    string s = reg[i];
    if (!s.size()) {
        reg[j] = "";
        return;
    }

    int l = s.size();
    for (int a = 0; a < l / 9 + 1; a++) {
        for (int b = 0; b < 4; b++) {
            if (s[a * 9 + b * 2] != '-') s[a * 9 + b * 2 + 1] = k;
        }
    }

    //cout << s << '\n';
    reg[j] = s;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M; cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> reg[i];
    }

    for (int a = 0; a < M; a++) {
        int r; cin >> r;
        if (r == 1) {
            int i, j, k; cin >> i >> j >> k;
            A(i - 1, j - 1, k - 1);
        }
        else if (r == 2) {
            int i, j, k; cin >> i >> j >> k;
            B(i - 1, j - 1, k);
        }
        else if (r == 3) {
            int i, j, k; cin >> i >> j >> k;
            C(i - 1, j - 1, k - 1);
        }
        else {
            int i, j; char k; cin >> i >> j >> k;
            D(i - 1, j - 1, k);
        }
    }

    if (reg[99].size() == 0) cout << "None";
    else cout << reg[99];
}