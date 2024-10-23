#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string s; cin >> s;
    int N; cin >> N;
    vector<string> v(N);
    for (auto& i : v) cin >> i;

    int l = (int)s.size();
    for (int k = 0; k < 26; k++) {
        for (auto& c : s) {
            c++;
            if (c > 'z') c = 'a';
        }
        for (const auto& i : v) {
            if (s.find(i) != string::npos) {
                cout << s; 
                return 0;
            }
        }
    }
}