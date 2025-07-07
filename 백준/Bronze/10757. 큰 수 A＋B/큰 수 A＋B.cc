#include <bits/stdc++.h>
using namespace std;

class Integer {
public:
    Integer() = default;
    Integer(string s) {
        num = s;
    }

    Integer operator+(const Integer& B) const {
        string a = num;
        string b = B.num;

        if (a.size() < b.size()) swap(a, b);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int i, t = 0;
        string ans;

        for (i = 0; i < b.size(); i++) {
            int x = a[i] - '0';
            int y = b[i] - '0';
            string z = to_string(x + y + t);
            if (z.size() == 2) t = z.front() - '0';
            else t = 0;
            ans.append(&z.back());
        }

        for (; i < a.size(); i++) {
            int x = a[i] - '0';
            string z = to_string(x + t);
            if (z.size() == 2) t = z.front() - '0';
            else t = 0;
            ans.append(&z.back());
        }

        if (t) ans.push_back(static_cast<char>(t + '0'));
        reverse(ans.begin(), ans.end());

        return Integer(ans);
    }

    friend ostream& operator<<(ostream& os, const Integer& integer) {
        os << integer.num;
        return os;
    }

private:
     string num{};
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string a, b; cin >> a >> b;
    cout << Integer(a) + Integer(b);
}