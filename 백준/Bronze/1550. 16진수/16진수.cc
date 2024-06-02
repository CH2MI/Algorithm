#include <iostream>
using namespace std;

int H2D(char a) {
    if (a > '9') {
        return 10 + a - 'A';
    }
    return a - '0';
}

int main() {
    string s; cin >> s;
    int ret = 0;
    int i = 1;
    for (auto itr = s.rbegin(); itr != s.rend(); itr++, i <<= 4) {
        ret += H2D(*itr) * i;
    }
    cout << ret;
}