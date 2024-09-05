#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        string s;
        cin >> s;
        cout << "String #" << i << '\n';
        for (auto c : s) {
            cout << (char)((c- 'A' + 1) % 26 + 'A'); 
        }
        cout << "\n\n";
    }
}