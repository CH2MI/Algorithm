#include <bits/stdc++.h>
using namespace std;

vector<string> Months = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        string Month, Day;
        int Year;
        cin >> Month >> Day >> Year;

        auto itr = find(Months.begin(), Months.end(), Month);
        if (itr == Months.end()) {
            cout << "Invalid\n";
            continue;
        }

        int day = stoi(Day.substr(0, Day.size() - 1));
        if (day < 1 || day > 31) {
            cout << "Invalid\n";
            continue;
        }

        string ret;
        if (to_string(itr - Months.begin() + 1).size() == 1) ret += '0';
        ret += to_string(itr - Months.begin() + 1) + '/';
        if (to_string(day).size() == 1) ret += '0';
        ret += to_string(day) + '/';
        if (Year % 100 < 10) ret += '0';
        ret += to_string(Year % 100);
        cout << ret << '\n';
    }
}