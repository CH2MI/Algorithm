#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string s;
    cin >> s;

    bool answer = true;

    int len = (int)s.size();
    int i = 0;
    int cnt = 0;
    while (i < len) {
        if (s[i] != 'w') {
            answer = false;
            break;
        }
        while (i < len && s[i] == 'w') cnt++, i++; 
        if (len - i < cnt * 3) {
            answer = false;
            break;
        }   
        for (int j = 0; j < cnt; j++, i++) {
            if (s[i] != 'o') answer = false;
        }
        for (int j = 0; j < cnt; j++, i++) {
            if (s[i] != 'l') answer = false;
        }
        for (int j = 0; j < cnt; j++, i++) {
            if (s[i] != 'f') answer = false;
        }
        cnt = 0;
    }
    cout << answer;
}