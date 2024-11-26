#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    cin.ignore();
    while (N--) {
        int sum = 0, error = 0;
        while (true) {
            string s;
            getline(cin, s);
            if (s.empty()) break;
            for (auto c : s) {
                sum++;
                if (c == '#') error++;
            }
        }
        cout << "Efficiency ratio is ";
        cout << round((double)(sum - error) / (double)sum * 1000) / 10 << "%.\n";
    }
}