#include <iostream>
#include <string>
using namespace std;

int main() {
    int f = 0;
    for (int tc = 0; tc < 5; tc++) {
        string s;
        cin >> s;
        for (int i = 0; i < s.size() - 2; i++) {
            if (s.substr(i, 3) == "FBI") {
                f = 1;
                cout << tc + 1 << ' ';
                break;
            }
        }
    }
    if (!f) cout << "HE GOT AWAY!";
}