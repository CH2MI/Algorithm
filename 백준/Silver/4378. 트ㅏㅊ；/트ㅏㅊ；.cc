#include <bits/stdc++.h>
using namespace std;

char special(char c) {
    char ret = ' ';
    switch (c) {
        case '-':
            ret = '0';
        break;
        case '=':
            ret = '-';
        break;
        case '[':
            ret = 'P';
        break;
        case ']':
            ret = '[';
        break;
        case '\\':
            ret = ']';
        break;
        case ';':
            ret = 'L';
        break;
        case '\'':
            ret = ';';
        break;
        case ',':
            ret = 'M';
        break;
        case '.':
            ret = ',';
        break;
        case '/':
            ret = '.';
        break;
    }
    return ret;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    string alpha = " VXSWDFGUHJKNBIO EARYCQZT ";
    string num = "9`12345678";

    string s;
    while (getline(cin, s)) {
        for (auto c : s) {
            if (c == ' ') cout << c;
            else if ('0' <= c && c <= '9') cout << num[c - '0'];
            else if ('A' <= c && c <= 'Z') cout << alpha[c - 'A'];
            else cout << special(c);
        }
        cout << '\n';
    }



}
