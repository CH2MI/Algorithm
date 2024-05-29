#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    for (int i = 0, cnt = 0; i < s.size(); i++, cnt++) {
        if (cnt == 10) {
            cout << '\n';
            cnt = 0;
        }
        cout << s[i];
    }
}